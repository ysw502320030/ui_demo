#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialogspine.h"
#include "dialogtable.h"
#include "dialogtable2.h"
#include "encoder.h"
#include <QThread>

#include <QKeyEvent>
#include <linux/input.h>

#include <QMenu>

#include <QTextDocument>

#include <QTableWidget>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//class DialogSpine;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int firstIndex=0;

//public:
//    //重写实现按键事件
//    void keyPressEvent(QKeyEvent *e);

public slots:
    void ChooseWidgets();
    void pushButton2Clicked();
    bool eventFilter(QObject *watched, QEvent *event);
    void menuClicked(QAction *action);
    void StackWidgetInit();
    void OutGraphSetting();

private:
    Ui::MainWindow *ui;
    QTimer m_timer,menuTimer,stackWidgetInitDelay;

public:
    QThread qThread;

public:
    void ChangeMainShutterState();
    void ReadCurrentFilmDataToVaraibles();
    void ConnectFilmTableChange();
    void WriteTableData(QTableWidgetItem* item);
    void TestFunction();
    void ReadProcDataToVariables();
    void StackedWidgetPageChanged();
    void InitVariables();
    void FilmNoChanged();
    void LoadProcVariableToTable();
    void proc_combobox_clicked();
    void LoadFilmVariablesToTable();
    void BeforeChangingFilmNo();
    void SetOtherWidgetToTableItem();

public:
    int fd,fd_encoder, fd_fifo_button_status,fd_fifo_film_data,fd_fifo_proc_data;
    int ret = 0,ret_encoder=0;
    struct input_event in_ev = {};

    QMenu *menu = new QMenu();
    QMenu *menu_2 = new QMenu();
    QMap<QMenu*, QPushButton*> map;

    QKeyEvent *event_down = new QKeyEvent ( QEvent::KeyPress, Qt::Key_Down, Qt::NoModifier);

    QTextDocument Text;

    enum FilmTablePartEnum {basic_info_part = 1,rate_pid_part= 2,temp_pid_part = 3, \
                            precon_part = 4,cap_depo_part = 5,postcon_part = 6} filmTablePart;

//    char boolVal[2][2] ={{'N'},{'Y'}};

    char boolVal[2][2] ={"N","Y"};

//    DialogSpine  *dialogSpine ;
//    DialogTable  *dialogtable ;
//    DialogTable2 *dialogtable2;

private:
    QSocketNotifier *in_fifo_notifier;
    QSocketNotifier *in_fifo_notifier_encoder;
    void encoder_handler();
//    void keyPressEvent(QKeyEvent *e);
    void MenuInitialStep();

//    struct Data_to_UI ui_data;
//    struct Data_to_UI *ui_data2;

//    QSocketNotifier *in_fifo_notifier;

//    int ret = 0;
//    int fd;

//    QQueue<Data_to_UI > q ;

signals:
    /* 工人开始工作（做些耗时的操作 ） */
    void startWork(const QString &);
    void startWork_test();
    void toGraphSettingSignal();
    void ToPreWidget();
    void ToNextWidget();

    void layerSelSingal();

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_mshuttle_clicked();
    void on_pushButton_start_clicked();
    //void on_pushButton_clicked();
    void on_pushButton_stop_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_r3_clicked();
    void on_pushButton_r2_clicked();
    void on_pushButton_r2_pressed();
    void on_comboBox_proc_currentIndexChanged(int index);
    void on_comboBox_layer_currentIndexChanged(int index);
    void on_proc_basic_info_table_itemChanged(QTableWidgetItem *item);
    void on_comboBox_filmSelection_currentIndexChanged(int index);
    void on_pushButton_r1_clicked();
};
#endif // MAINWINDOW_H
