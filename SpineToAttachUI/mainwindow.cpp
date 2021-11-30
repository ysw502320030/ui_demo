#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "datathread.h"

Data_to_UI ui_data;
QQueue<Data_to_UI > q;

QString button_text[6]={NULL,NULL,"RNG","EDG","IG"};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DialogSpine *dialogSpine = new DialogSpine(this);
    DialogTable *dialogtable = new DialogTable(this);
    DialogTable2 *dialogtable2 = new DialogTable2(this);

    ui->stackedWidget->addWidget(dialogSpine);
    ui->stackedWidget->addWidget(dialogtable);
    ui->stackedWidget->addWidget(dialogtable2);

    ui->stackedWidget->setCurrentWidget(dialogSpine);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(ChooseWidgets()));

//    Datathread *mthread = new Datathread;
//    mthread->moveToThread(&qThread);

//    connect(&qThread, SIGNAL(finished()),
//            mthread, SLOT(deleteLater()));
//    connect(&qThread, SIGNAL(finished()),
//            &qThread, SLOT(deleteLater()));

//    /* 点击按钮打断线程 */
//    connect(ui->pushButton_2, SIGNAL(clicked()),
//            this, SLOT(pushButton2Clicked()));

////    qThread.start();

//    /* 发送开始工作的信号，开始工作 */
////    connect(this, SIGNAL(startWork(QString)),
////            mthread, SLOT(Datathread::init_notifier(QString)));

//    connect(this, &MainWindow::startWork,
//            mthread, &Datathread::init_notifier);

////    DialogSpine *mspine = new DialogSpine;
////    connect(this,                             // emitter
////        SIGNAL(startWork_test()),       // signal
////        mspine,                                // receiver
////        SLOT(handleTimeout()));  // slot
///
}

MainWindow::~MainWindow()
{
    delete ui;
}

//切换页面
void MainWindow::ChooseWidgets()
{

    //获取页面的数量
    int nCount = ui->stackedWidget->count();
    //获取当前页面的索引
    int nIndex = ui->stackedWidget->currentIndex();

    //获取下一个需要显示的页面索引
    nIndex++;

    //当需要显示的页面索引大于等于总页面时，切换至首页
    if (nIndex >= nCount)
    {
        nIndex = firstIndex;
    }
//    ui->pushButton->setText(button_text[nIndex]);
    //显示当前页面
    ui->stackedWidget->setCurrentIndex(nIndex);

}

void MainWindow::pushButton2Clicked()
{
//    /* 字符串常量 */
//    const QString str = "正在运行";

//    /* 判断线程是否在运行 */
//    if(!qThread.isRunning()) {
//        /* 开启线程 */
//        qThread.start();
//    }

//    /* 发送正在运行的信号，线程收到信号后执行后返回线程耗时函数 + 此字符串 */
//    emit this->startWork(str);
//    emit this->startWork_test();

//#if __arm__
//    fd=::open("/temp_using/topeet", O_RDWR);
//    in_fifo_notifier = new QSocketNotifier(fd, QSocketNotifier::Read, this);
//    connect(in_fifo_notifier, &QSocketNotifier::activated,
//        this, &DialogSpine::handle_readNotification);
//#else
//    fd=::open("/home/alientek/other/code/Qt/02/01_qfile/topeet", O_RDWR);
//    in_fifo_notifier = new QSocketNotifier(fd, QSocketNotifier::Read, this);
//    connect(in_fifo_notifier, &QSocketNotifier::activated,
//        this, &DialogSpine::handleTimeout);

}


