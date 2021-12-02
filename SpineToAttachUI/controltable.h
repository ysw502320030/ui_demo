#ifndef CONTROLTABLE_H
#define CONTROLTABLE_H


#include <QWidget>
#include <QList>
#include <QObject>
#include <QVariant>
#include <QLineEdit>

#include <QKeyEvent>

typedef QList<QLineEdit*> ControlList;

class ControlTable: public QObject
{
    Q_OBJECT
public:
    //注意parent不能为空
    ControlTable(QWidget *parent);

    void setTable(const QList<ControlList>& t);

    void setTableWhole(const ControlList &controlList);

    //按钮焦点上移
    void toUp();
    //按钮焦点下移
    void toDown();
    //按钮焦点左移
    void toLeft();
    //按钮焦点右移
    void toRight();

    void toUpWhole();

    void toDownWhole();

private:
    //返回表格第r行所有按钮列表
    ControlList rowControls(int r);
    //返回表格第c列所有按钮列表
    ControlList colControls(int c);

    ControlList wholeControls();

    //获取控件行号
    int row(QLineEdit* control);
    //获取控件列号
    int col(QLineEdit* control);

    int widget_position(QLineEdit *control);

    //判断行列是否都有效
    bool isValid(int r, int c);

    bool isValidWhole(int num);
    //按钮表格最大行数
    int  rowCount();

    int  wholeCount();

    void selectControl(QLineEdit* control);

    //返回btnList第index索引位置的后一个按钮
    //如果btnList只有一个按钮，则返回按钮本身
    QLineEdit* nextControl(const ControlList& controlList, int index);
    //返回btnList第index索引位置的前一个按钮
    //如果btnList只有一个按钮，则返回按钮本身
    QLineEdit* preControl(const ControlList& controlList, int index);

    QLineEdit *preControlWhole(const ControlList &controlList, int index);

    QLineEdit *nextControlWhole(const ControlList& controlList, int index);



private:
    QWidget* widget;
//    QWidget* currentContrl; //记录当前焦点所在按钮
    QLineEdit* testContrl; //记录当前焦点所在按钮
    QList<ControlList> table;//按钮表格
    QList<QLineEdit*> tableWhole;

    const char* rowid;
    const char* colid;
    const char* widgetID;

public:
        QLineEdit* currentContrl; //记录当前焦点所在按钮
};
#endif // CONTROLTABLE_H.
