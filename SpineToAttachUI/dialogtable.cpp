#include "dialogtable.h"

#include "ui_dialogtable.h"

#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QtTest>

DialogTable::DialogTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTable)
{
    OutPutInfo("table1");
    ui->setupUi(this);
    setWindowTitle(tr("TableWidget"));//设置对话框的标题
    ui->qTableWidget->setColumnCount(4);//设置列数
    ui->qTableWidget->setRowCount(3);//设置行数
    ui->qTableWidget->setWindowTitle("QTableWidget");
//    QStringList m_Header;
//    m_Header<<QString("序号")<<QString("姓名")<<QString("性别")<<QString("地址");
//    ui->qTableWidget->setHorizontalHeaderLabels(m_Header);//添加横向表头
    ui->qTableWidget->verticalHeader()->setVisible(true);//纵向表头可视化
//    ui->qTableWidget->horizontalHeader()->setVisible(false);//横向表头可视化
    //ui->tableWidget->setShowGrid(false);//隐藏栅格
    ui->qTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置编辑方式：禁止编辑表格
    ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置表格选择方式：设置表格为整行选中
    //ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectColumns);//设置表格选择方式：设置表格为整列选中
    ui->qTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//选择目标方式
    ui->qTableWidget->setStyleSheet("selection-background-color:pink");//设置选中颜色：粉色


    for(int rows=0;rows<3;rows++)
    {
        for(int columns=0;columns<4;columns++)
        {
            if(columns==0)
            {
                ui->qTableWidget->setItem(rows,columns,new QTableWidgetItem("1"));
            }
            else if(columns==1)
            {
                ui->qTableWidget->setItem(rows,columns,new QTableWidgetItem("aki"));
            }
            else if(columns==2)
            {
                ui->qTableWidget->setItem(rows,columns,new QTableWidgetItem("female"));
            }
            else
            {
                ui->qTableWidget->setItem(rows,columns,new QTableWidgetItem("Chengdu"));
            }
        }
    }
    for(int rows=0;rows<3;rows++)
    {
        for(int columns=0;columns<4;columns++)
        {
            ui->qTableWidget->setColumnWidth(columns,125);
            ui->qTableWidget->setRowHeight(rows,30);
            ui->qTableWidget->item(rows,columns)->setTextAlignment(Qt::AlignCenter);//居中显示
            ui->qTableWidget->item(rows,columns)->setBackgroundColor(QColor(85,170,255));//设置前景颜色
            ui->qTableWidget->item(rows,columns)->setTextColor(QColor(0,0,0));//设置文本颜色
            ui->qTableWidget->item(rows,columns)->setFont(QFont("Helvetica"));//设置字体为黑体
        }
    }
//    ui->qTableWidget->setSpan(2, 2,2 ,1);//合并单元格
//    ui->qTableWidget->setItem(2, 2, new QTableWidgetItem(QIcon("E:\\Qt_Project\\QTableWidget\\1.jpg"), "路飞"));//插入图片
//    ui->qTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置水平滚动条
//    ui->qTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置垂直滚动条
    //设置行和列的大小设为与内容相匹配（如果设置了宽高就不要用了）
    //ui->qTableWidget->resizeColumnsToContents();
    //ui->qTableWidget->resizeRowsToContents();

    QString strText = ui->qTableWidget->item(1, 1)->text();//获取单元格的内容
    OutPutInfo("content: %s",strText);//输出单元格内容

    //设置列标签
    QStringList HStrList;
    HStrList.push_back(QString("Th"));
    HStrList.push_back(QString("ΔTh"));
    HStrList.push_back(QString("Δt"));
    HStrList.push_back(QString("Rate"));
//    HStrList.push_back(QString("other"));
    //设置行列数(只有列存在的前提下，才可以设置列标签)
    int HlableCnt = HStrList.count();
    ui->qTableWidget->setRowCount(3);
    ui->qTableWidget->setColumnCount(HlableCnt);
    //设置列标签
    ui->qTableWidget->setHorizontalHeaderLabels(HStrList);

    QStringList VStrList;
    VStrList.push_back(QString("latest"));
    VStrList.push_back(QString("latest-1"));
    VStrList.push_back(QString("latest-2"));
    ui->qTableWidget->setVerticalHeaderLabels(VStrList);

    ui->qTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->qTableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

////    ui->qTableWidget->item(0, 0)->setText(QString::number(5.5));

////    connect(ui->pushButton1, SIGNAL(clicked()), this, SLOT(TableNotUpdate()));

//    DialogSpine *mSpine = new DialogSpine(this);

//    connect(mSpine,                             // emitter
//        &DialogSpine::entry_added,       // signal
//        this,                                // receiver
//        &DialogTable::DataToTable);  // slot
////    [=](QQueue<Data_to_UI > &mQueue) {DataToTable(mQueue);}
////    SLOT(TableNotUpdate2())   &DialogTable::TableNotUpdate2


//    workerTable->moveToThread(thread_table);

    connect(worker,                             // emitter
            &Datathread::signal_to_table,       // signal
            this,                                // receiver
            &DialogTable::DataToTable);  // slot

//    connect(worker,                             // emitter
//        SIGNAL(signal_to_table()),       // signal
//        this,                                // receiver
//        SLOT(DataToTable()));  // slot

    if(!mthread->isRunning())
        mthread->start();

    connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
    connect(worker, SIGNAL(finished()), mthread, SLOT(quit()));
    connect(mthread, SIGNAL(finished()), mthread, SLOT(deleteLater()));
//        connect(this,                             // emitter
//            &DialogTable::test_signal_table,       // signal
//            this,                                // receiver
//            &DialogTable::TableNotUpdate2);  // slot

        ui->qTableWidget->item(1, 1)->setText(QString::number(66.62));
//        TableNotUpdate2();

}

DialogTable::~DialogTable()
{
    delete ui;
}

void DialogTable::DataToTable()
{

    if(q.size()<=3)
    {
        q.enqueue(ui_data);
        //OutPutInfo() << 12 << &q.head();
    }

    if(q.size() == 4)
    {

        for(int i=0;i<3;i++)
        {
            ui->qTableWidget->item(i, 0)->setText(QString::number(q[3-i].thA[1], 'f', 2));
            ui->qTableWidget->item(i,1)->setText(QString::number(q[3-i].thA[1] - q[3-i-1].thA[1], 'f', 2));
            ui->qTableWidget->item(i,2)->setText(QString::number(q[3-i].delta_time, 'f', 2));
            ui->qTableWidget->item(i,3)->setText(QString::number(q[3-i].rate[1], 'f', 2));

//            ui->qTableWidget->item(i, 0)->setText(QString::number(2.2));
//            ui->qTableWidget->item(i,1)->setText(QString::number(3.3));
//            ui->qTableWidget->item(i,2)->setText(QString::number(2.5));
//            ui->qTableWidget->item(i,3)->setText(QString::number(6.9));
        }

        q.dequeue();

    }
}

void DialogTable::TableNotUpdate()
{
//    ui->qTableWidget->item(1, 1)->setText(QString::number(55.56));
    int i =0;
    i=i+1;
    emit test_signal_table();
}


void DialogTable::TableNotUpdate2()
{
    static int i =0;
    i++;
    ui->qTableWidget->item(1, 1)->setText(QString::number(99.5+i));

}



//new QTableWidgetItem(QString::number())
