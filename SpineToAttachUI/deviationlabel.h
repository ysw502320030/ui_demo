#ifndef DEVIATIONLABEL_H
#define DEVIATIONLABEL_H


#include <QObject>
#include <QLabel>
#include <QPainter>
#include <QPen>
//QPainter
//QPen
//#include "generalheaders.h"

class DeviationLabel : public QLabel
{
    Q_OBJECT
public:
    explicit DeviationLabel(QWidget *parent = 0);
    void setValue(float index);
    void reset();
    void setBgColor(QColor BgColor);
    void setTextColor(QColor TextColor);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *event);


private:
    int StartX;
    int StartY;
    int labelW;
    int labelH;
    int Startx;
    int Starty;
    int labelw;
    int labelh;
    int textStartx;
    int textStarty;
    int textw;
    int texth;
    int ProgressNum;

    float biasPercentVal;
    float lengthEffective;

    QColor bgColor;
    QColor textColor;
    bool drawTextFlag;
};

#endif // DEVIATIONLABEL_H
