#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialogspine.h"
#include "dialogtable.h"
#include "dialogtable2.h"
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int firstIndex=0;

public slots:
    void ChooseWidgets();
    void pushButton2Clicked();

private:
    Ui::MainWindow *ui;

public:
    QThread qThread;

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
};
#endif // MAINWINDOW_H
