#include "dialogtable2.h"
#include "ui_dialogtable2.h"

#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>

DialogTable2::DialogTable2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTable2)
{
    ui->setupUi(this);

    setWindowTitle(tr("TableWidget"));//设置对话框的标题
    ui->qTableWidget2->setColumnCount(4);//设置列数
    ui->qTableWidget2->setRowCount(10);//设置行数
    ui->qTableWidget2->setWindowTitle("qTableWidget2");
//    QStringList m_Header;
//    m_Header<<QString("序号")<<QString("姓名")<<QString("性别")<<QString("地址");
//    ui->qTableWidget2->setHorizontalHeaderLabels(m_Header);//添加横向表头
    ui->qTableWidget2->verticalHeader()->setVisible(true);//纵向表头可视化
//    ui->qTableWidget2->horizontalHeader()->setVisible(false);//横向表头可视化
    //ui->tableWidget->setShowGrid(false);//隐藏栅格
    ui->qTableWidget2->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置编辑方式：禁止编辑表格
//    ui->qTableWidget2->setSelectionBehavior(QAbstractItemView::SelectItems);//设置表格选择方式：设置表格为整行选中
    //ui->qTableWidget2->setSelectionBehavior(QAbstractItemView::SelectColumns);//设置表格选择方式：设置表格为整列选中
    ui->qTableWidget2->setSelectionMode(QAbstractItemView::SingleSelection);//选择目标方式
    ui->qTableWidget2->setStyleSheet("selection-background-color:pink");//设置选中颜色：粉色

//        ui->qTableWidget2->setItem(1,2,new qTableWidget2Item("Chengdu"));
    for(int rows=0;rows<10;rows++)
    {
        for(int columns=0;columns<4;columns++)
        {
            if(columns==0)
            {
                ui->qTableWidget2->setItem(rows,columns,new QTableWidgetItem("12"));
            }
            else if(columns==1)
            {
                ui->qTableWidget2->setItem(rows,columns,new QTableWidgetItem("cola2"));
            }
            else if(columns==2)
            {
                ui->qTableWidget2->setItem(rows,columns,new QTableWidgetItem("female2"));
            }
            else
            {
                ui->qTableWidget2->setItem(rows,columns,new QTableWidgetItem("Chengdu2"));
            }
        }
    }
    for(int rows=0;rows<10;rows++)
    {
        for(int columns=0;columns<4;columns++)
        {
            ui->qTableWidget2->setColumnWidth(columns,125);
            ui->qTableWidget2->setRowHeight(rows,30);
            ui->qTableWidget2->item(rows,columns)->setTextAlignment(Qt::AlignCenter);//居中显示
            ui->qTableWidget2->item(rows,columns)->setBackgroundColor(QColor(85,170,255));//设置前景颜色
            ui->qTableWidget2->item(rows,columns)->setTextColor(QColor(0,0,0));//设置文本颜色
            ui->qTableWidget2->item(rows,columns)->setFont(QFont("Helvetica"));//设置字体为黑体
        }
    }
//    ui->qTableWidget2->setSpan(2, 2,2 ,1);//合并单元格
//    ui->qTableWidget2->setItem(2, 2, new QTableWidgetItem(QIcon("E:\\Qt_Project\\qTableWidget2\\1.jpg"), "路飞"));//插入图片
    ui->qTableWidget2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置水平滚动条
    ui->qTableWidget2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置垂直滚动条
    //设置行和列的大小设为与内容相匹配（如果设置了宽高就不要用了）
    //ui->qTableWidget2->resizeColumnsToContents();
    //ui->qTableWidget2->resizeRowsToContents();

    QString strText = ui->qTableWidget2->item(1, 1)->text();//获取单元格的内容
    qDebug()<<"content:"<<strText;//输出单元格内容

    //设置列标签
    QStringList HStrList;
    HStrList.push_back(QString("id"));
    HStrList.push_back(QString("name"));
    HStrList.push_back(QString("sex"));
    HStrList.push_back(QString("city"));
    HStrList.push_back(QString("other"));
    //设置行列数(只有列存在的前提下，才可以设置列标签)
    int HlableCnt = HStrList.count();
    ui->qTableWidget2->setRowCount(10);
    ui->qTableWidget2->setColumnCount(HlableCnt);
    //设置列标签
    ui->qTableWidget2->setHorizontalHeaderLabels(HStrList);
}

DialogTable2::~DialogTable2()
{
    delete ui;
}
