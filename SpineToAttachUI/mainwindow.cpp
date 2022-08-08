#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "datathread.h"
#include "qpainter.h"
//#include "dialogspine.h"
#include "string.h"

Data_to_UI ui_data;
QQueue<Data_to_UI > q;

UIButtonInfo ButtonStatus;

struct Films film;

struct Processes proc;

char ctrlMode[6][10] = {"man p","semi p","auto p","man t","semi t","auto t"};

QList<float> bufferOneMin[4],  bufferThreeMin[4], bufferTenMin[4], bufferThirtyMin[4],
             bufferSixtyMin[4],bufferThreeHour[4],bufferTenHour[4],bufferThirtyHour[4];

int channelNum = 4;

bool uiChangeMSFlag = false;

QList<QPointF> points[4];

DialogSpine *dialogSpine;

//encoder *mEncoder = new encoder;

int proNum,layerNum,chan1_film_sel,chan2_film_sel,chan3_film_sel,chan4_film_sel;

QString button_text[6]={NULL,NULL,"RNG","EDG","IG"};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dialogSpine = new DialogSpine(this);
    DialogTable  *dialogtable = new DialogTable(this);
    DialogTable2 *dialogtable2 = new DialogTable2(this);

////    mEncoder = new encoder();
//    ui->stackedWidget->addWidget(dialogSpine);
//    ui->stackedWidget->addWidget(dialogtable);
//    ui->stackedWidget->addWidget(dialogtable2);
//    ui->stackedWidget->setCurrentWidget(dialogSpine);

    //process page and film page is created by UI. Insert main page here as 1st page
    ui->stackedWidget->insertWidget(0,dialogSpine);

    ui->stackedWidget->setCurrentWidget(dialogSpine);

//    QObject::connect(&stackWidgetInitDelay, &QTimer::timeout, this, &MainWindow::StackWidgetInit);
//    stackWidgetInitDelay.setInterval(100);
//    stackWidgetInitDelay.start();

    connect(ui->pushButton_r2, SIGNAL(clicked()), this, SLOT(ChooseWidgets()));
    connect(ui->pushButton_CFM, SIGNAL(clicked()), this, SLOT(pushButton2Clicked()));

//    QMenu *menu = new QMenu();
//    menu->addAction( tr("图标视图"));
//    menu->addAction( tr("细节视图"));

//    ui->pushButton_menu->setMenu(menu);

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
    //m_timer.start();

    ui->pushButton_menu->setMenu(menu);
    menu->addAction("1");
    menu->addAction( "2");
    menu->addAction( "3");
    menu->installEventFilter(this);     //"menu" will response if any event like menu appearing happens

    connect(menu, SIGNAL(triggered(QAction*)), this, SLOT(menuClicked(QAction*)));

    map.insert(menu,ui->pushButton_menu);
    ui->pushButton_menu->setStyleSheet("QPushButton::menu-indicator{image:None;}");

    //menuTimer to make the highlight mark to locate to 1st place of menu
    QObject::connect(&menuTimer, &QTimer::timeout, this, &MainWindow::MenuInitialStep);
    menuTimer.setInterval(100);

    OutPutInfo( "main constructor");

    QObject::connect(this, &MainWindow::toGraphSettingSignal, dialogSpine, &DialogSpine::FocusFirstWidget);

    QObject::connect(dialogSpine, &DialogSpine::CloseGraphSetting, this, &MainWindow::OutGraphSetting);

    QObject::connect(this, &MainWindow::ToPreWidget, dialogSpine, &DialogSpine::FocusToPreWidget);

    QObject::connect(this, &MainWindow::ToNextWidget, dialogSpine, &DialogSpine::FocusToNextWidget);

    QObject::connect(dialogSpine, &DialogSpine::sigThicknessAchieved, this, &MainWindow::ChangeMainShutterState);

    QObject::connect(dialogSpine, &DialogSpine::sigThicknessAchieved, this, &MainWindow::ChangeMainShutterState);

    QObject::connect(worker, &Datathread::ToggleMainShutterSignal,this, &MainWindow::ChangeMainShutterState);

    QObject::connect(ui->stackedWidget, &QStackedWidget::currentChanged, this, &MainWindow::StackedWidgetPageChanged);

    QObject::connect(ui->comboBox_proc, &ComboBoxClickable::menuClicked, this, &MainWindow::proc_combobox_clicked);
    QObject::connect(ui->comboBox_layer, &ComboBoxClickable::menuClicked, this, &MainWindow::proc_combobox_clicked);

    QObject::connect(ui->comboBox_filmSelection, &ComboBoxClickable::menuClicked, this, &MainWindow::BeforeChangingFilmNo);

    QObject::connect(this, &MainWindow::layerSelSingal, dialogSpine, &DialogSpine::LayerSelect);

    //ToggleMainShutterSignal();

    ButtonStatus.stateMS = 0;

    //Text.setHtml("<p style=\"font-size:50px;text-align:center;white-space: pre\" > X </p>");
    Text.setHtml("<p style=\"font-size:15px;text-align:center;white-space: pre\" >Main Shutt<br></p>"
                 " <span style=\"font-size: 15px;white-space: pre;\">      </span> <span style=\"font-size: 50px;\">X</span>");
    QPixmap pixmap(Text.size().width(), Text.size().height());
    pixmap.fill( Qt::transparent );
    QPainter painter( &pixmap );
    Text.drawContents(&painter, pixmap.rect());

    QIcon ButtonIcon(pixmap);
    ui->pushButton_mshuttle->setIcon(ButtonIcon);
    ui->pushButton_mshuttle->setIconSize(pixmap.rect().size());

    //ui->tableWidget_test->setRowCount(2);
    //ui->tableWidget_test->setColumnCount(2);

    //ui->proc_basic_info_table->item(0,9)->setText(QString::number(5.5));

    //set combobox to some table item
    SetOtherWidgetToTableItem();

    //read 1st film table data to variable, could be commented
    ReadCurrentFilmDataToVaraibles();

    ReadProcDataToVariables();

    //ConnectFilmTableChange();

    InitVariables();

    //TestFunction();

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

    fd_fifo_button_status = ::open("/temp_using/ButtonStatusFifo",O_RDWR);//以只写方式打开管道文件描述符
	if(fd_fifo_button_status < 0){
		perror("open ButtonStatusFifo");
//		return -1;
	}

    int flags = fcntl(fd_fifo_button_status, F_GETFL, 0);
    fcntl(fd_fifo_button_status, F_SETFL, flags | O_NONBLOCK);

    fd_fifo_film_data = ::open("/temp_using/FilmFifo",O_RDWR);//以只写方式打开管道文件描述符
	if(fd_fifo_film_data < 0){
		perror("open FilmFifo");
	}
    int flags_film = fcntl(fd_fifo_film_data, F_GETFL, 0);
    fcntl(fd_fifo_film_data, F_SETFL, flags_film | O_NONBLOCK);

    fd_fifo_proc_data = ::open("/temp_using/ProcFifo",O_RDWR);//以只写方式打开管道文件描述符
	if(fd_fifo_proc_data < 0){
		perror("open ProcFifo");
	}
    int flags_proc = fcntl(fd_fifo_proc_data, F_GETFL, 0);
    fcntl(fd_fifo_proc_data, F_SETFL, flags_proc | O_NONBLOCK);

#endif
    ::write(fd_fifo_film_data, &film, sizeof(film));
    ::write(fd_fifo_proc_data, &proc, sizeof(proc));
#if __arm__

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

//navigate main page <-> process page <-> film page
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
            OutPutInfo("key is -%d", in_ev.value);
            QKeyEvent *event = new QKeyEvent ( QEvent::KeyPress, Qt::Key_Up, Qt::NoModifier);
            QWidget *widget1 = QApplication::focusWidget();
            QCoreApplication::postEvent ((QObject*)widget1, event);
//        }
//        else
//            ;



}

void MainWindow::MenuInitialStep()
{
    QCoreApplication::sendEvent(menu, event_down);
    menuTimer.stop();
}

/*After remap the encoder turn to F1 and F2,*/
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    QPushButton* parentButton = dynamic_cast<QPushButton*>(map[dynamic_cast<QMenu*>(watched)]);
    if (!parentButton)
        return false;

    QMenu* menu = dynamic_cast<QMenu*>(watched);
    if (!menu)
        return false;

    //after showing the menu,move the highlight mark to locate to 1st place of menu
    if (event->type() == QEvent::Show)
    {
        QPoint pos = menu->pos();
        qDebug() << "pos" << pos;

        pos.setX(pos.x() + parentButton->width() - menu->width());
        parentButton->menu()->move(parentButton->mapToGlobal(QPoint(parentButton->width(),-(menu->height()-parentButton->height())/2)));
//        QCoreApplication::postEvent(this, event_down);
        menuTimer.start();
        return true;
    }

    if(event->type()==QEvent::KeyPress)
    {
        OutPutInfo("36");
        QKeyEvent *mKeyPress = (QKeyEvent *)event;

        if(mKeyPress->key()==Qt::Key_F1)
        {
            OutPutInfo("F1 36");
            QKeyEvent *event = new QKeyEvent ( QEvent::KeyPress, Qt::Key_Up, Qt::NoModifier);
            QWidget *widget1 = QApplication::focusWidget();
            QCoreApplication::postEvent ((QObject*)widget1, event);
            qDebug() << "focused widget " << widget1;
        }

        else if (mKeyPress->key()==Qt::Key_F2)
        {
            OutPutInfo("F2 36");
            QKeyEvent *event = new QKeyEvent ( QEvent::KeyPress, Qt::Key_Down, Qt::NoModifier);
            QWidget *widget1 = QApplication::focusWidget();
            QCoreApplication::postEvent ((QObject*)widget1, event);
            qDebug() << "focused widget " << widget1;
        }
    }

//    return true;

//    return MainWindow::eventFilter(watched,event);
}

//void MainWindow::keyPressEvent(QKeyEvent *e)
//{

//    this->grabKeyboard();

//    if (e->key()==Qt::Key_F1)
//    {
//        this->releaseKeyboard();
//        QKeyEvent *event = new QKeyEvent ( QEvent::KeyPress, Qt::Key_Up, Qt::NoModifier);
//        QWidget *widget1 = QApplication::focusWidget();
//        QCoreApplication::postEvent ((QObject*)widget1, event);
//    }

//    else if (e->key()==Qt::Key_F2)
//    {
//        this->releaseKeyboard();
//        QKeyEvent *event = new QKeyEvent ( QEvent::KeyPress, Qt::Key_Down, Qt::NoModifier);
//        QWidget *widget1 = QApplication::focusWidget();
//        QCoreApplication::postEvent ((QObject*)widget1, event);
//    }
//}

void MainWindow::menuClicked(QAction *action)
{
    // do something with action
    qDebug() << "33" << action;

    if(action->text()=="1")
    {
        OutPutInfo("34 1 clicked");
    }

    if(action->text()=="2")
    {
        OutPutInfo("35 1 clicked");
        emit toGraphSettingSignal();
    }

    if(action->text()=="3")
    {
        menu->close();
    }
}

void MainWindow::StackWidgetInit()
{
//    dialogSpine = new DialogSpine(this);
//    dialogtable = new DialogTable(this);
//    dialogtable2 = new DialogTable2(this);

////    mEncoder = new encoder();

//    ui->stackedWidget->addWidget(dialogSpine);
//    ui->stackedWidget->addWidget(dialogtable);
//    ui->stackedWidget->addWidget(dialogtable2);

//    ui->stackedWidget->setCurrentWidget(dialogSpine);

//    stackWidgetInitDelay.stop();
}

void MainWindow::OutGraphSetting()
{
    ui->pushButton_start->setFocus();
}

void MainWindow::on_pushButton_3_clicked()
{
    emit ToPreWidget();
}

void MainWindow::on_pushButton_4_clicked()
{
    emit ToNextWidget();
}



void MainWindow::on_pushButton_mshuttle_clicked()
{
    uiChangeMSFlag = true;
    ChangeMainShutterState();
    QThread::msleep(150);
    uiChangeMSFlag = false;
}

void MainWindow::ChangeMainShutterState()
{
    static char zz =0;

    if(zz == 0){
        Text.setHtml("<p style=\"font-size:15px;text-align:center;white-space: pre\" >Main Shutt<br></p>"
                     " <span style=\"font-size: 15px;white-space: pre;\">   </span> <span style=\"color:green;font-size: 50px;\">●</span>");
        //" <span style=\"font-size: 15px;white-space: pre;\">       </span> <span style=\"font-size: 50px;\">●</span>"
        zz =1;
    }
    else{
        Text.setHtml("<p style=\"font-size:15px;text-align:center;white-space: pre\" >Main Shutt<br></p>"
                     " <span style=\"font-size: 15px;white-space: pre;\">      </span> <span style=\"font-size: 50px;\">X</span>");
        //<span style="font-size: 15px;white-space: pre;"> </span> <span style="font-size: 50px;">X/-</span>
        zz =0;
    }


    QPixmap pixmap(Text.size().width(), Text.size().height());
    pixmap.fill( Qt::transparent );
    QPainter painter( &pixmap );
    Text.drawContents(&painter, pixmap.rect());


    QIcon ButtonIcon(pixmap);
    ui->pushButton_mshuttle->setIcon(ButtonIcon);
    ui->pushButton_mshuttle->setIconSize(pixmap.rect().size());

    ButtonStatus.procStart = -1;
    ButtonStatus.proStop = -1;
    //ButtonStatus.stateMS = !ButtonStatus.stateMS;//Toogle this state

    OutPutInfo("ButtonStatus.stateMS before toggle is %d" , ButtonStatus.stateMS);

    if(ButtonStatus.stateMS == 0 || ButtonStatus.stateMS == -1) {
        ButtonStatus.stateMS = 1;
        OutPutInfo("ButtonStatus.stateMS after toggle is" , ButtonStatus.stateMS);
    }
    else if(ButtonStatus.stateMS == 1) {
        ButtonStatus.stateMS = 0;
        OutPutInfo("ButtonStatus.stateMS after toggle is" , ButtonStatus.stateMS);
    }

    ::write(fd_fifo_button_status, &ButtonStatus, sizeof(ButtonStatus));
}

void MainWindow::on_pushButton_start_clicked()
{
    ButtonStatus.procStart = 1;
    ButtonStatus.proStop = 0;
    //ButtonStatus.stateMS = -1;
    ::write(fd_fifo_button_status, &ButtonStatus, sizeof(ButtonStatus));
}

void MainWindow::on_pushButton_stop_clicked()
{
    ButtonStatus.procStart = 0;
    ButtonStatus.proStop = 1;
    //ButtonStatus.stateMS = -1;
    ::write(fd_fifo_button_status, &ButtonStatus, sizeof(ButtonStatus));
}

void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_pushButton_r3_clicked()
{
    //qDebug() << "index is "<< ui->stackedWidget->currentIndex();

    if(ui->stackedWidget->currentIndex() == 2) {

        int page=ui->stackedWidget_film->currentIndex();
        if(++page>=ui->stackedWidget_film->count())
            page=0;
        ui->stackedWidget_film->setCurrentIndex(page);

    }
}

void MainWindow::TestFunction()
{

}

void MainWindow::SetOtherWidgetToTableItem()
{
    ui->proc_basic_info_table->setCellWidget(0,10,ui->comboBox_TH_meas1);
    ui->proc_basic_info_table->setCellWidget(1,10,ui->comboBox_TH_meas2);
    ui->proc_basic_info_table->setCellWidget(2,10,ui->comboBox_TH_meas3);
    ui->proc_basic_info_table->setCellWidget(3,10,ui->comboBox_TH_meas4);

    ui->proc_adv_info_table->setCellWidget(0,1,ui->comboBox_final_layer);
    ui->proc_adv_info_table->setCellWidget(1,1,ui->comboBox_adv_setting);
    ui->proc_adv_info_table->setCellWidget(3,1,ui->comboBox_issue_signal);
    ui->proc_adv_info_table->setCellWidget(4,1,ui->comboBox_wait_operation);

    ui->filmTable1_1->setCellWidget(0,1,ui->comboBox_ctrl_type);
}

void MainWindow::InitVariables()
{
    for(int procNum =1; procNum<9;procNum++)
        sprintf(proc.name[procNum],"Proc%i", procNum);

    for(int procNum =1; procNum<9;procNum++)
        for(int layerNum= 1;layerNum < 33;layerNum++)
            sprintf(proc.lay_name[procNum][layerNum],"Layer%i", layerNum);

    //for(int i=0;i<6;i++)

    //currently using film1 and film2,film1 is init by ui
    int filmNo = 2;
    film.ctype[filmNo] = 2;
    strncpy(film.name[filmNo], "film2",sizeof(film.name[filmNo]) - 1);
    film.dens[filmNo] = 1;
    film.Zf[filmNo] = 1;
    film.sour[filmNo] = 2;
    film.sens[filmNo] = 2;
    film.tool[filmNo] = 100;

    film.r_pid_p[filmNo] = 0.6;
    film.r_pid_i[filmNo] = 46;
    film.r_pid_d[filmNo] = 0;
    film.pwr_max[filmNo] = 86;
    film.rate_max[filmNo] = 60;

    film.t_pid_p[filmNo] = 10;
    film.t_pid_i[filmNo] = 10;
    film.t_pid_d[filmNo] = 0;
    film.temp_max[filmNo] = 1000;

    film.ini[filmNo] = 0.5;
    film.ramp1[filmNo] = 5;
    film.pwr1[filmNo] = 1;
    film.soak1[filmNo] = 3;
    film.ramp2[filmNo] = 5;
    film.pwr2[filmNo] =2;
    film.soak2[filmNo] = 3;

    film.capture_ramp[filmNo] = 0.02;
    film.capture_rate_perc[filmNo] = 20;
    film.reduction_perc[filmNo] = 0;
    film.ready_deviation[filmNo] = 70;
    film.shut_delay_sec[filmNo] = 300;
    film.alarm_deviation[filmNo] = 90;
    film.error_deviation[filmNo] = 200;

    film.ramp3[filmNo] = 1;
    film.pwr3[filmNo] = 1;
    film.soak3[filmNo] =2;
    film.idle[filmNo] = 0;

}

void MainWindow::on_pushButton_r2_clicked()
{

}

void MainWindow::ConnectFilmTableChange()
{
    //QObject::connect(ui->filmTable1_1, &QTableWidget::itemChanged, this, &MainWindow::WriteFilmTableData);
    //QObject::connect(ui->filmTable1_2, &QTableWidget::itemChanged, this, &MainWindow::WriteFilmTableData);
    //QObject::connect(ui->filmTable1_3, &QTableWidget::itemChanged, this, &MainWindow::WriteFilmTableData);
    //QObject::connect(ui->filmTable1_4, &QTableWidget::itemChanged, this, &MainWindow::WriteFilmTableData);
    //QObject::connect(ui->filmTable1_5, &QTableWidget::itemChanged, this, &MainWindow::WriteFilmTableData);
    //QObject::connect(ui->filmTable1_6, &QTableWidget::itemChanged, this, &MainWindow::WriteFilmTableData);

    //QList<QTableWidget*> tableList = this->findChildren<QTableWidget*>();
    //foreach(auto table, tableList)
    //{
    //    QObject::connect(table, &QTableWidget::itemChanged, this, &MainWindow::WriteTableData);
    //}

    //QObject::connect(ui->lineEdit_th_setVal, &QLineEdit::editingFinished, this, &MainWindow::ReadProcDataToVariables);

}

//void MainWindow::WriteTableData(QTableWidgetItem* item)
//{
//    ReadCurrentFilmDataToVaraibles();
//
//    int i = item->column();
//    bool j = item->tableWidget()->objectName() == ui->proc_basic_info_table->objectName();
//
//    if(item->column() == 3 && (item->tableWidget()->objectName() == ui->proc_basic_info_table->objectName()))     //film number changed
//    {
//        LoadProcVariableToTable();
//    }
//
//    ReadProcDataToVariables();
//    ::write(fd_fifo_film_data, &film, sizeof(film));
//    ::write(fd_fifo_proc_data, &proc, sizeof(proc));
//}

void MainWindow::LoadProcVariableToTable()
{

    int filmNum[5] = {0};
    int procSel = ui->comboBox_proc->currentText().toInt();
    int layerSel = ui->comboBox_layer->currentText().toInt();

    //qDebug("page is %d", ui->stackedWidget->currentIndex());

    //inital process name as proc%d, init layer name as layer%d
    ui->lineEdit_proc_name->setText(proc.name[procSel]);
    ui->lineEdit_layer_name->setText(proc.lay_name[procSel][layerSel]);
    ui->lineEdit_th_setVal->setText(proc.lay_th[procSel][layerSel] == DASH_VAL ? QString(DASH_VAL) : QString::number(proc.lay_th[procSel][layerSel]));

    for(int chan =1; chan<5; chan++){

        filmNum[chan] = proc.lay_chan_film[procSel][layerSel][chan];
        ui->proc_basic_info_table->item(chan -1,1)->setText(filmNum[chan] == NULL_VAL? \
                                                    QString(DASH_VAL) : QString::number(film.sour[filmNum[chan]]));
        ui->proc_basic_info_table->item(chan -1,2)->setText(filmNum[chan] == NULL_VAL? \
                                                    QString(DASH_VAL) : QString::number(film.sens[filmNum[chan]]));
        ui->proc_basic_info_table->item(chan -1,3)->setText(filmNum[chan] == NULL_VAL? \
                                                    QString(DASH_VAL) : QString::number(filmNum[chan]));
        ui->proc_basic_info_table->item(chan -1,4)->setText(filmNum[chan] == NULL_VAL? \
                                                    QString(DASH_VAL) : QString(film.name[filmNum[chan]]));
        ui->proc_basic_info_table->item(chan -1,5)->setText(filmNum[chan] == NULL_VAL? \
                                                    QString(DASH_VAL) : QString(ctrlMode[film.ctype[filmNum[chan]]]));
        ui->proc_basic_info_table->item(chan -1,6)->setText(proc.lay_chan_sv1[procSel][layerSel][chan] == NULL_VAL? \
                                                    QString(DASH_VAL) : QString::number(proc.lay_chan_sv1[procSel][layerSel][chan]));
        ui->proc_basic_info_table->item(chan -1,7)->setText(proc.lay_chan_soak[procSel][layerSel][chan] == NULL_VAL? \
                                                    QString(DASH_VAL) : QString::number(proc.lay_chan_soak[procSel][layerSel][chan]));
        ui->proc_basic_info_table->item(chan -1,8)->setText(proc.lay_chan_ramp[procSel][layerSel][chan] == NULL_VAL? \
                                                    QString(DASH_VAL) : QString::number(proc.lay_chan_ramp[procSel][layerSel][chan]));
        ui->proc_basic_info_table->item(chan -1,9)->setText(proc.lay_chan_sv2[procSel][layerSel][chan] == NULL_VAL? \
                                                    QString(DASH_VAL) : QString::number(proc.lay_chan_sv2[procSel][layerSel][chan]));
        //ui->proc_basic_info_table->item(chan -1,10)->setText(proc.lay_chan_meas_th[procSel][layerSel][chan] == NULL_VAL? \
        //                                            QString(DASH_VAL) : QString(boolVal[proc.lay_chan_meas_th[procSel][layerSel][chan]]));
    }

    ui->comboBox_TH_meas1->setCurrentText(proc.lay_chan_meas_th[procSel][layerSel][1] == NULL_VAL? \
                                                    QString(DASH_VAL) : QString(boolVal[proc.lay_chan_meas_th[procSel][layerSel][1]]));
    ui->comboBox_TH_meas2->setCurrentText(proc.lay_chan_meas_th[procSel][layerSel][2] == NULL_VAL? \
                                                    QString(DASH_VAL) : QString(boolVal[proc.lay_chan_meas_th[procSel][layerSel][2]]));
    ui->comboBox_TH_meas3->setCurrentText(proc.lay_chan_meas_th[procSel][layerSel][3] == NULL_VAL? \
                                                    QString(DASH_VAL) : QString(boolVal[proc.lay_chan_meas_th[procSel][layerSel][3]]));
    ui->comboBox_TH_meas4->setCurrentText(proc.lay_chan_meas_th[procSel][layerSel][4] == NULL_VAL? \
                                                    QString(DASH_VAL) : QString(boolVal[proc.lay_chan_meas_th[procSel][layerSel][4]]));

    //ui->proc_adv_info_table->item(0,1)->setText(proc.lay_is_last_L[procSel][layerSel] == NULL_VAL? \
    //                                                QString(DASH_VAL) : QString(boolVal[proc.lay_is_last_L[procSel][layerSel]]));
    ui->comboBox_final_layer->setCurrentText(proc.lay_is_last_L[procSel][layerSel] == NULL_VAL? \
                                                    QString(DASH_VAL) : QString(boolVal[proc.lay_is_last_L[procSel][layerSel]]));
    ui->comboBox_adv_setting->setCurrentText(proc.lay_use_advanced_lay_par[procSel][layerSel] == NULL_VAL? \
                                                    QString(DASH_VAL) : QString(boolVal[proc.lay_use_advanced_lay_par[procSel][layerSel]]));
    ui->proc_adv_info_table->item(2,1)->setText(proc.lay_add_sec[procSel][layerSel] == NULL_VAL? \
                                                    QString(DASH_VAL) : QString::number(proc.lay_add_sec[procSel][layerSel]));
    ui->comboBox_issue_signal->setCurrentText(proc.lay_add_signal[procSel][layerSel] == NULL_VAL? \
                                                    QString(DASH_VAL) : QString(boolVal[proc.lay_add_signal[procSel][layerSel]]));
    ui->comboBox_wait_operation->setCurrentText(proc.lay_wait_operator[procSel][layerSel] == NULL_VAL? \
                                                    QString(DASH_VAL) : QString(boolVal[proc.lay_wait_operator[procSel][layerSel]]));
    ui->proc_adv_info_table->item(5,1)->setText(proc.lay_add_automation[procSel][layerSel] == NULL_VAL? \
                                                    QString(DASH_VAL) : QString::number(proc.lay_add_automation[procSel][layerSel]));
    ui->proc_adv_info_table->item(6,1)->setText(proc.lay_next_L[procSel][layerSel] == NULL_VAL? \
                                                    QString(DASH_VAL) : QString::number(proc.lay_next_L[procSel][layerSel]));
    ui->proc_adv_info_table->item(7,1)->setText(proc.lay_jumps_L[procSel][layerSel] == NULL_VAL? \
                                                    QString(DASH_VAL) : QString::number(proc.lay_jumps_L[procSel][layerSel]));
    ui->proc_adv_info_table->item(8,1)->setText(proc.lay_pass_N[procSel][layerSel] == NULL_VAL? \
                                                    QString(DASH_VAL) : QString::number(proc.lay_pass_N[procSel][layerSel]));

}

//Read data from ui table
void MainWindow::ReadProcDataToVariables()
{
    int procSel = ui->comboBox_proc->currentText().toInt();
    int layerSel = ui->comboBox_layer->currentText().toInt();

    strncpy(proc.name[procSel], ui->lineEdit_proc_name->text().toStdString().c_str(),sizeof(proc.name[procSel]) - 1);
    strncpy(proc.lay_name[procSel][layerSel], ui->lineEdit_layer_name->text().toStdString().c_str(),sizeof(proc.lay_name[procSel][layerSel]) - 1);
    proc.lay_th[procSel][layerSel] = ui->lineEdit_th_setVal->text().toFloat();

    for(int chan =1; chan<5; chan++){

        proc.lay_chan_film[procSel][layerSel][chan] = ui->proc_basic_info_table->item(chan -1,3)->text().toInt();
        proc.lay_chan_sv1[procSel][layerSel][chan] = ui->proc_basic_info_table->item(chan -1,6)->text().toFloat();
        proc.lay_chan_soak[procSel][layerSel][chan] = ui->proc_basic_info_table->item(chan -1,7)->text().toFloat();
        proc.lay_chan_ramp[procSel][layerSel][chan] = ui->proc_basic_info_table->item(chan -1,8)->text().toFloat();
        proc.lay_chan_sv2[procSel][layerSel][chan] = ui->proc_basic_info_table->item(chan -1,9)->text().toFloat();

    }

    proc.lay_chan_meas_th[procSel][layerSel][1] = ui->comboBox_TH_meas1 ->currentText() == 'Y' ? 1:0;
    proc.lay_chan_meas_th[procSel][layerSel][2] = ui->comboBox_TH_meas2 ->currentText() == 'Y' ? 1:0;
    proc.lay_chan_meas_th[procSel][layerSel][3] = ui->comboBox_TH_meas3 ->currentText() == 'Y' ? 1:0;
    proc.lay_chan_meas_th[procSel][layerSel][4] = ui->comboBox_TH_meas4 ->currentText() == 'Y' ? 1:0;

    proc.lay_is_last_L[procSel][layerSel] = ui->comboBox_final_layer->currentText() == 'Y' ? 1:0;
    proc.lay_use_advanced_lay_par[procSel][layerSel] = ui->comboBox_adv_setting->currentText() == 'Y' ? 1:0;
    proc.lay_add_sec[procSel][layerSel] = ui->proc_adv_info_table->item(2,1)->text().toFloat();
    proc.lay_add_signal[procSel][layerSel] = ui->comboBox_issue_signal->currentText() == 'Y' ? 1:0;
    proc.lay_wait_operator[procSel][layerSel] = ui->comboBox_wait_operation->currentText() == 'Y' ? 1:0;
    proc.lay_add_automation[procSel][layerSel] = ui->proc_adv_info_table->item(5,1)->text().toInt();
    proc.lay_next_L[procSel][layerSel] = ui->proc_adv_info_table->item(6,1)->text().toInt();
    proc.lay_jumps_L[procSel][layerSel] = ui->proc_adv_info_table->item(7,1)->text().toInt();
    proc.lay_pass_N[procSel][layerSel] = ui->proc_adv_info_table->item(8,1)->text().toInt();

}

void MainWindow::ReadCurrentFilmDataToVaraibles()
{
    /*USe a combobox to navigate film number
     * use button r3 to navigate different page inside a film*/

    //QString patternFilm("filmTable(\d)_(\d)");
    QRegExp filmCheck("filmTable(\\d)_(\\d)");

    QList<QTableWidget*> tableList = this->findChildren<QTableWidget*>();

    int filmNo,tableNo;

    foreach(auto table, tableList)
    {
        OutPutInfo("the table is %s ",qUtf8Printable(table->objectName()));

        int retCheck = filmCheck.indexIn(table->objectName());  //check if is film table
        if(retCheck >= 0)
        {
            //qDebug("%s,%s", qUtf8Printable(filmCheck.cap(1)), qUtf8Printable(filmCheck.cap(2)));
            //filmNo = filmCheck.cap(1).toInt();

            /*film No. from combobox,tableNo from 2nd int of table name,
            table named is obtained by regex method*/
            filmNo = ui->comboBox_filmSelection->currentText().toInt();
            tableNo = filmCheck.cap(2).toInt();
            OutPutInfo("%d,%d", filmNo, tableNo);

            if(tableNo == basic_info_part){
                film.ctype[filmNo] = ui->comboBox_ctrl_type->currentIndex();
                //film.name[1] =
                strncpy(film.name[filmNo], table->item(1, 1)->text().toStdString().c_str(),sizeof(film.name[filmNo]) - 1);
                film.dens[filmNo] = table->item(2, 1)->text().toFloat();
                film.Zf[filmNo] =   table->item(3, 1)->text().toFloat();
                film.sour[filmNo] = table->item(4, 1)->text().toInt();
                film.sens[filmNo] = table->item(5, 1)->text().toInt();
                film.tool[filmNo] = table->item(6, 1)->text().toFloat();
            }
            else if(tableNo == rate_pid_part){
                film.r_pid_p[filmNo] =   table->item(0, 1)->text().toFloat();
                film.r_pid_i[filmNo] =   table->item(1, 1)->text().toFloat();
                film.r_pid_d[filmNo] =   table->item(2, 1)->text().toFloat();
                film.pwr_max[filmNo] =   table->item(3, 1)->text().toFloat();
                film.rate_max[filmNo] =  table->item(4, 1)->text().toFloat();
            }
            else if(tableNo == temp_pid_part){
                film.t_pid_p[filmNo] =   table->item(0, 1)->text().toFloat();
                film.t_pid_i[filmNo] =   table->item(1, 1)->text().toFloat();
                film.t_pid_d[filmNo] =   table->item(2, 1)->text().toFloat();
                film.temp_max[filmNo] =  table->item(3, 1)->text().toFloat();
            }
            else if(tableNo == precon_part){
                film.ini[filmNo] =   table->item(0, 1)->text().toFloat();
                film.ramp1[filmNo] =   table->item(1, 1)->text().toFloat();
                film.pwr1[filmNo] =   table->item(2, 1)->text().toFloat();
                film.soak1[filmNo] =   table->item(3, 1)->text().toFloat();
                film.ramp2[filmNo] =   table->item(4, 1)->text().toFloat();
                film.pwr2[filmNo] =   table->item(5, 1)->text().toFloat();
                film.soak2[filmNo] =   table->item(6, 1)->text().toFloat();
            }
            else if(tableNo == cap_depo_part){
                film.capture_ramp[filmNo] =   table->item(0, 1)->text().toFloat();
                film.capture_rate_perc[filmNo] =   table->item(1, 1)->text().toFloat();
                film.reduction_perc[filmNo] =   table->item(2, 1)->text().toFloat();
                film.ready_deviation[filmNo] =   table->item(3, 1)->text().toFloat();
                film.shut_delay_sec[filmNo] =   table->item(4, 1)->text().toFloat();
                film.alarm_deviation[filmNo] =   table->item(5, 1)->text().toFloat();
                film.error_deviation[filmNo] =   table->item(6, 1)->text().toFloat();
            }
            else if(tableNo == postcon_part){
                film.ramp3[filmNo] =   table->item(0, 1)->text().toFloat();
                film.pwr3[filmNo] =   table->item(1, 1)->text().toFloat();
                film.soak3[filmNo] =   table->item(2, 1)->text().toFloat();
                film.idle[filmNo] =   table->item(3, 1)->text().toFloat();
            }
        }
    }
}

void MainWindow::LoadFilmVariablesToTable()
{
    int filmNo = ui->comboBox_filmSelection->currentText().toInt();

    //ui->filmTable1_1->item(0,1)->setText("Auto P");    //film.ctype[filmNo] = 2 -> auto p
    ui->comboBox_ctrl_type->setCurrentIndex(film.ctype[filmNo]);
    //film.name[1] =
    ui->filmTable1_1->item(1, 1)->setText(film.name[filmNo]);
    ui->filmTable1_1->item(2, 1)->setText(QString::number(film.dens[filmNo], 'f', 2));
    ui->filmTable1_1->item(3, 1)->setText(QString::number(film.Zf[filmNo], 'f', 2));
    ui->filmTable1_1->item(4, 1)->setText(QString::number(film.sour[filmNo]));
    ui->filmTable1_1->item(5, 1)->setText(QString::number(film.sens[filmNo]));
    ui->filmTable1_1->item(6, 1)->setText(QString::number(film.tool[filmNo], 'f', 2));

    ui->filmTable1_2->item(0, 1)->setText(QString::number(film.r_pid_p[filmNo], 'f', 2));
    ui->filmTable1_2->item(1, 1)->setText(QString::number(film.r_pid_i[filmNo], 'f', 2));
    ui->filmTable1_2->item(2, 1)->setText(QString::number(film.r_pid_d[filmNo], 'f', 2));
    ui->filmTable1_2->item(3, 1)->setText(QString::number(film.pwr_max[filmNo], 'f', 2));
    ui->filmTable1_2->item(4, 1)->setText(QString::number(film.rate_max[filmNo], 'f', 2));

    ui->filmTable1_3->item(0, 1)->setText(QString::number(film.t_pid_p[filmNo], 'f', 2));
    ui->filmTable1_3->item(1, 1)->setText(QString::number(film.t_pid_i[filmNo], 'f', 2));
    ui->filmTable1_3->item(2, 1)->setText(QString::number(film.t_pid_d[filmNo], 'f', 2));
    ui->filmTable1_3->item(3, 1)->setText(QString::number(film.temp_max[filmNo], 'f', 2));

    ui->filmTable1_4->item(0, 1)->setText(QString::number(film.ini[filmNo], 'f', 2));
    ui->filmTable1_4->item(1, 1)->setText(QString::number(film.ramp1[filmNo], 'f', 2));
    ui->filmTable1_4->item(2, 1)->setText(QString::number(film.pwr1[filmNo], 'f', 2));
    ui->filmTable1_4->item(3, 1)->setText(QString::number(film.soak1[filmNo], 'f', 2));
    ui->filmTable1_4->item(4, 1)->setText(QString::number(film.ramp2[filmNo], 'f', 2));
    ui->filmTable1_4->item(5, 1)->setText(QString::number(film.pwr2[filmNo], 'f', 2));
    ui->filmTable1_4->item(6, 1)->setText(QString::number(film.soak2[filmNo], 'f', 2));

    ui->filmTable1_5->item(0, 1)->setText(QString::number(film.capture_ramp[filmNo], 'f', 2));
    ui->filmTable1_5->item(1, 1)->setText(QString::number(film.capture_rate_perc[filmNo], 'f', 2));
    ui->filmTable1_5->item(2, 1)->setText(QString::number(film.reduction_perc[filmNo], 'f', 2));
    ui->filmTable1_5->item(3, 1)->setText(QString::number(film.ready_deviation[filmNo], 'f', 2));
    ui->filmTable1_5->item(4, 1)->setText(QString::number(film.shut_delay_sec[filmNo], 'f', 2));
    ui->filmTable1_5->item(5, 1)->setText(QString::number(film.alarm_deviation[filmNo], 'f', 2));
    ui->filmTable1_5->item(6, 1)->setText(QString::number(film.error_deviation[filmNo], 'f', 2));

    ui->filmTable1_6->item(0, 1)->setText(QString::number(film.ramp3[filmNo], 'f', 2));
    ui->filmTable1_6->item(1, 1)->setText(QString::number(film.pwr3[filmNo], 'f', 2));
    ui->filmTable1_6->item(2, 1)->setText(QString::number(film.soak3[filmNo], 'f', 2));
    ui->filmTable1_6->item(3, 1)->setText(QString::number(film.idle[filmNo], 'f', 2));

}

//after the r2 button clicked, change to proc page
void MainWindow::StackedWidgetPageChanged()
{
    if(ui->stackedWidget->currentIndex() == 1) {
        LoadProcVariableToTable();
    }
}

void MainWindow::proc_combobox_clicked()
{
    ReadProcDataToVariables();
}

//void MainWindow::on_combobox_indexChanged()
//{
//    LoadProcVariableToTable();
//}

//1).If stackedWidget is already in proc page, save current proc data before going to film page.
//2).The reasonable way to update the film&struct, is updating after chaning of each item,
//but when load variable to table, such action will be trigger by too many times.
void MainWindow::on_pushButton_r2_pressed()
{
    if(ui->stackedWidget->currentIndex() == 1) {
        ReadProcDataToVariables();
        ::write(fd_fifo_proc_data, &proc, sizeof(proc));
    }
    if(ui->stackedWidget->currentIndex() == 2) {
        ReadCurrentFilmDataToVaraibles();
        ::write(fd_fifo_film_data, &film, sizeof(film));
    }
}

void MainWindow::on_comboBox_proc_currentIndexChanged(int index)
{
    LoadProcVariableToTable();
}

void MainWindow::on_comboBox_layer_currentIndexChanged(int index)
{
    LoadProcVariableToTable();
}

void MainWindow::on_proc_basic_info_table_itemChanged(QTableWidgetItem *item)
{
    //film No. changed
    if(item->column() == 3){

        bool ok;
        int num = item->text().toInt(&ok,10);

        if(ok & num>0){

            int chan = item->row();
            ui->proc_basic_info_table->item(chan,1)->setText(QString::number(film.sour[num]));
            ui->proc_basic_info_table->item(chan,2)->setText(QString::number(film.sens[num]));
            ui->proc_basic_info_table->item(chan,4)->setText(QString(film.name[num]));
            ui->proc_basic_info_table->item(chan,5)->setText(QString(ctrlMode[film.ctype[num]]));
        }
    }
}

void MainWindow::BeforeChangingFilmNo()
{
    ReadCurrentFilmDataToVaraibles();
}

void MainWindow::on_comboBox_filmSelection_currentIndexChanged(int index)
{
    LoadFilmVariablesToTable();
}

void MainWindow::on_pushButton_r1_clicked()
{
    ReadProcDataToVariables();

    //used to notify layer info to Main UI
    proNum = ui->comboBox_proc->currentText().toInt();
    layerNum = ui->comboBox_layer->currentText().toInt();

    //used to notify layer info to target program
    proc.proNum = ui->comboBox_proc->currentText().toInt();
    proc.layerNum = ui->comboBox_layer->currentText().toInt();

    chan1_film_sel = ui->proc_basic_info_table->item(0,3)->text().toInt();
    chan2_film_sel = ui->proc_basic_info_table->item(1,3)->text().toInt();
    chan3_film_sel = ui->proc_basic_info_table->item(2,3)->text().toInt();
    chan4_film_sel = ui->proc_basic_info_table->item(3,3)->text().toInt();

    emit layerSelSingal();

}
