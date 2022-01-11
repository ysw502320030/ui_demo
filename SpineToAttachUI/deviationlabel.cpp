#include "deviationlabel.h"

DeviationLabel::DeviationLabel(QWidget *parent) : QLabel(parent)
{
    this->setMaximumWidth(10);
    this->setMinimumHeight(119);

//    this->setText("akaHa");
//    this->setBgColor(QColor(0,0,255));

    StartX = this->x();
    StartY = this->y();
    labelW = this->width();
    labelH = this->height();
    labelw = (((labelW*4)/5)*8)/10;
    labelh = (labelH*8)/10;
    Startx = StartX + labelW/10;
    Starty = StartY + labelH/10;
    textStartx = StartX + (labelW*4)/5;
    textStarty = StartY;
    textw = labelW/5;
    texth = labelH;
    ProgressNum = 0;
    bgColor = QColor(0,0,0);
    textColor = QColor(0,0,0);
    drawTextFlag = false;

//    lengthEffective = labelW - labelW/10;
    lengthEffective = labelH - labelH/10;

}
void DeviationLabel::reset()
{
   drawTextFlag = false;
}

void DeviationLabel::setValue(float val)
{
    drawTextFlag = true;
    biasPercentVal = val;
//    repaint();
    update();
}
void DeviationLabel::setBgColor(QColor BgColor)
{
    bgColor = BgColor;
}
void DeviationLabel::setTextColor(QColor TextColor)
{
    textColor = TextColor;
}

void DeviationLabel::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen(bgColor, 1, Qt::DotLine);

//    QPen pen=painter.pen();

    painter.setPen(pen);
    QRectF rectF1 = QRectF(StartX,StartY,labelW,labelH);
    painter.drawRect(rectF1);
    painter.setBrush(bgColor);
//    QRectF rectF2 = QRectF(Startx,Starty,(ProgressNum*labelw)/100,labelh);

//    QRectF rectF2 = QRectF(StartX+lengthEffective/2 + lengthEffective/2 * biasPercentVal ,Starty,labelW/10,labelh);

    QRectF rectF2 = QRectF(StartX,StartY+lengthEffective/2 + lengthEffective/2 *( -biasPercentVal ) ,labelW,labelH/10);

    painter.drawRect(rectF2);

//    if(drawTextFlag)
//    {
//        QRectF rectF3 = QRectF(textStartx,textStarty,textw,texth);
//        QString text = QString::number(ProgressNum) + "%";
//        painter.setPen(textColor);
//        painter.drawText(rectF3,Qt::AlignCenter,text);
//    }
}
