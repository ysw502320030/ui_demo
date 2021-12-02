#include "controltable.h"
#include <QDebug>

ControlTable::ControlTable(QWidget *parent):
    QObject(parent),rowid("table_row"),colid("table_col"),widgetID("ID is")
{
    Q_ASSERT(parent);
    currentContrl = 0;
    testContrl = 0;
    widget = parent;
}

void ControlTable::setTable(const QList<ControlList> &t)
{
    bool isSetDefaultControl = false;
    table = t;
    for (int i = 0; i < rowCount(); ++i)
    {
        ControlList controList =table.at(i);
        for (int j = 0; j < controList.size(); ++j)
        {
            if (table[i][j])
            {
                table[i][j]->setProperty(rowid, i);
                table[i][j]->setProperty(colid, j);
                if (!isSetDefaultControl)
                {
                    selectControl(table[i][j]);
                    isSetDefaultControl = true;
                }
            }
        }
    }
}

void ControlTable::setTableWhole(const ControlList &controlList)
{
    bool isSetDefaultControl = false;
    tableWhole = controlList;
    for (int i = 0; i < wholeCount(); ++i)
    {
        if (tableWhole[i])
        {
            tableWhole[i]->setProperty(widgetID, i);
            if (!isSetDefaultControl)
            {
                selectControl(tableWhole[i]);
                isSetDefaultControl = true;
            }
        }

    }
}

void ControlTable::toUp()
{
    QLineEdit *control = currentContrl;
    QLineEdit *testWidget = testContrl;
    int curRow = row(control);
    //qDebug()<<curRow;
    int curCol = col(control);

    if (isValid(curRow, curCol))
    {
        control = preControl(colControls(curCol), curRow);
        selectControl(control);
    }
    control->setFocus();
}

void ControlTable::toUpWhole()
{
    QLineEdit *control = currentContrl;
    QLineEdit *testWidget = testContrl;
    int curRow = row(control);
    //qDebug()<<curRow;
    int curCol = col(control);

    int posiNum = widget_position(control);

    if (isValidWhole(posiNum))
    {
        control = preControl(wholeControls(), posiNum);
        selectControl(control);
    }
    control->setFocus();
}

void ControlTable::toDownWhole()
{
    QLineEdit* control = currentContrl;
    int curRow = row(control);
    int curCol = col(control);

    int posiNum = widget_position(control);

    if (isValidWhole(posiNum))
    {
        control = nextControl(wholeControls(), posiNum);
        selectControl(control);
    }
    control->setFocus();
}

void ControlTable::toDown()
{
    QLineEdit* control = currentContrl;
    int curRow = row(control);
    int curCol = col(control);

    if (isValid(curRow, curCol))
    {
        control = nextControl(colControls(curCol), curRow);
        selectControl(control);
    }
    control->setFocus();
}

void ControlTable::toLeft()
{
    QLineEdit* control = currentContrl;
    int curRow = row(control);
    int curCol = col(control);

    if (isValid(curRow, curCol))
    {
        control = preControl(rowControls(curRow), curCol);
        selectControl(control);
    }
    control->setFocus();
}

void ControlTable::toRight()
{
    QLineEdit* control = currentContrl;
    int curRow = row(control);
    int curCol = col(control);

    if (isValid(curRow, curCol))
    {
        control = nextControl(rowControls(curRow), curCol);
        selectControl(control);
    }
    control->setFocus();
}


ControlList ControlTable::rowControls(int r)
{
    return table[r];
}

ControlList ControlTable::colControls(int c)
{
    ControlList ret;
    for (int i = 0; i < rowCount(); ++i)
    {
        ret.append(table[i][c]);
    }
    return ret;
}

ControlList ControlTable::wholeControls()
{
    return tableWhole;
}

int ControlTable::row(QLineEdit *control)
{
    if (!control)
    {
        return -1;
    }

    if (!control->property(rowid).isValid())
    {
        return -1;
    }
    return control->property(rowid).toInt();
}

int ControlTable::col(QLineEdit *control)
{
    if (!control)
    {
        return -1;
    }

    if (!control->property(colid).isValid())
    {
        return -1;
    }
    return control->property(colid).toInt();
}

int ControlTable::widget_position(QLineEdit *control)
{
    if (!control)
    {
        return -1;
    }

    if (!control->property(widgetID).isValid())
    {
        return -1;
    }
    return control->property(widgetID).toInt();
}

bool ControlTable::isValid(int r, int c)
{
    return r != -1 && c != -1;
}

bool ControlTable::isValidWhole(int num)
{
    return num != -1;
}

int ControlTable::rowCount()
{
    return table.size();
}

int ControlTable::wholeCount()
{
    return tableWhole.size();
}

void ControlTable::selectControl(QLineEdit *control)
{
    QLineEdit* old= currentContrl;

    currentContrl = control;
}

QLineEdit *ControlTable::nextControl(const ControlList &controlList, int index)
{
    QLineEdit * ret = 0;
    int tmp = 0;
    int size = controlList.size();
    for (int i = index+1; i <= size+index; ++i)
    {
        tmp = i % size;
        if (controlList.at(tmp) != 0)
        {
            ret = controlList.at(tmp);
            break;
        }
    }
    return ret;
}

QLineEdit *ControlTable::preControl(const ControlList &controlList, int index)
{
    QLineEdit* ret = 0;
    int tmp = 0;
    int size = controlList.size();
    for (int i = index-1; i >= index-size; --i)
    {
        if (i < 0)
        {
            tmp = i + size;
        }
        else
        {
            tmp = i;
        }

        if (controlList.at(tmp) != 0)
        {
            ret = controlList.at(tmp);
            break;
        }
    }
    return ret;
}

QLineEdit *ControlTable::preControlWhole(const ControlList &controlList, int index)
{
    QLineEdit* ret = 0;
    int tmp = 0;
    int size = controlList.size();
    int i = index-1;
//    for (int i = index-1; i >= index-size; --i)
//    {
        if (i < 0)
        {
            tmp = i + size;
        }
        else
        {
            tmp = i;
        }

        if (controlList.at(tmp) != 0)
        {
            ret = controlList.at(tmp);
//            break;
        }
//    }
    return ret;
}

QLineEdit *ControlTable::nextControlWhole(const ControlList &controlList, int index)
{
    QLineEdit * ret = 0;
    int tmp = 0;
    int size = controlList.size();
    int i = index+1;
//    for (int i = index+1; i <= size+index; ++i)
//    {
        tmp = i % size;
        if (controlList.at(tmp) != 0)
        {
            ret = controlList.at(tmp);
//            break;
        }
//    }
    return ret;
}

