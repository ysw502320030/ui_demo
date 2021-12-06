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
    encoder *mEncoder = new encoder();

    ui->stackedWidget->addWidget(dialogSpine);
    ui->stackedWidget->addWidget(dialogtable);
    ui->stackedWidget->addWidget(dialogtable2);

    ui->stackedWidget->setCurrentWidget(dialogSpine);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(ChooseWidgets()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(pushButton2Clicked()));

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

    QObject::connect(&m_timer, &QTimer::timeout, this, &MainWindow::pushButton2Clicked);
    m_timer.setInterval(1000);
//    m_timer.start();
#if __arm__

//    fd=open("/dev/btn_key", O_RDWR);
//    if(fd < 0) {
//    qDebug() << 10 << "open failed";
//    return;
//    }

//    fd_encoder=open("/dev/input/event2", O_RDWR);
//    if(fd_encoder < 0) {
//    qDebug() << 10 << "fd_encoder open failed";
//    return;
//    }

//    in_fifo_notifier = new QSocketNotifier(fd, QSocketNotifier::Read, this);
//    connect(in_fifo_notifier, &QSocketNotifier::activated,
//    this, &MainWindow::handle_readNotification);

//    in_fifo_notifier_encoder = new QSocketNotifier(fd_encoder, QSocketNotifier::Read, this);
//    connect(in_fifo_notifier_encoder, &QSocketNotifier::activated,
//    this, &MainWindow::encoder_handler);

#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::keyPressEvent(QKeyEvent *e)
//{
//    int i =0;

//    i=i+1;
//////    else if ((e->modifiers() == Qt::ControlModifier) && (e->key() == Qt::Key_Right))
////    QLineEdit *control = table->currentContrl;
//////    control->setReadOnly(false);
//////    __super::keyPressEvent(e);
//    this->grabKeyboard();
////    if (e->key()==Qt::Key_Up)
////    {
////        this->releaseKeyboard();
////        table->toUpWhole();
////    }
////    else if (e->key()==Qt::Key_Down)
////    {
////        this->releaseKeyboard();
////        table->toDownWhole();
////    }
////    else if (e->key() == Qt::Key_Left)
////    {
//////        this->releaseKeyboard();
//////        table->toLeft();
////    }
////    else if (e->key() == Qt::Key_Right)
////    {
//////        this->releaseKeyboard();
//////        table->toRight();
////    }
//////    control->setReadOnly(true);
//}

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
//    for(int i =0;i<10;i++)
//    {
//        QThread::sleep(1);

//        QKeyEvent *event = new QKeyEvent ( QEvent::KeyPress, Qt::Key_Down, Qt::NoModifier);

//        QWidget *widget1 = QApplication::focusWidget();

//        QCoreApplication::postEvent ((QObject*)widget1, event);

//        QCoreApplication::event(event);

//        QApplication::event(event);

//    }


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

void MainWindow::encoder_handler()
{
////    for(int i =0;i<10;i++)
////    {
////        QThread::sleep(1);

//        int i =0;

//        i=i+1;

//        float databuf[16];
//    //    struct Data_to_UI ui_data;

//        ret_encoder = read(fd_encoder, &in_ev, sizeof(struct input_event));

//        if(ret_encoder >= 0){
//            qDebug() << "key is" << in_ev.value;
//        }

//        if(in_ev.value == 1)
//        {
//            qDebug() << "key is +" << in_ev.value;
//            QKeyEvent *event = new QKeyEvent ( QEvent::KeyPress, Qt::Key_Down, Qt::NoModifier);
//            QWidget *widget1 = QApplication::focusWidget();
//            QCoreApplication::postEvent ((QObject*)widget1, event);
//        }
//        else if(in_ev.value == -1)
//        {
            qDebug() << "key is -" << in_ev.value;
            QKeyEvent *event = new QKeyEvent ( QEvent::KeyPress, Qt::Key_Up, Qt::NoModifier);
            QWidget *widget1 = QApplication::focusWidget();
            QCoreApplication::postEvent ((QObject*)widget1, event);
//        }
//        else
//            ;



}
