/********************************************************************************
** Form generated from reading UI file 'dialogspine.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSPINE_H
#define UI_DIALOGSPINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <deviationlabel.h>

QT_BEGIN_NAMESPACE

class Ui_DialogSpine
{
public:
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_procStatus;
    QLabel *label_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_graphics;
    QComboBox *comboBox_yRangeSel;
    QComboBox *comboBox_deviation;
    QComboBox *comboBox_5_change_xRange;
    QComboBox *comboBox_4_ch1Zoom;
    QComboBox *comboBox_3_ch2Zoom;
    QComboBox *comboBox_2_ch3Zoom;
    QComboBox *comboBox_ch4Zoom;
    QLabel *label_6;
    QPushButton *pushButton_clr;
    QPushButton *pushButton_exit;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_InfoHeader;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayoutInfoContent;
    QLabel *label_rate4;
    QLabel *label_pwr3;
    QLabel *label_senPct2;
    QLabel *label_sen4;
    QLabel *label_setTemp2;
    QLabel *label_setTemp3;
    QLabel *label_rate1;
    QLabel *label_material4;
    QLabel *label_setRate4;
    QLabel *label_mode3;
    QLabel *label_temp1;
    QLabel *label_setRate3;
    QLabel *label_status4;
    QLabel *label_material2;
    QLabel *label_src1;
    QLabel *label_senPct3;
    QLabel *label_temp3;
    QLabel *label_temp2;
    QLabel *label_setRate1;
    QLabel *label_src2;
    QLabel *label_senPct1;
    QLabel *label_temp4;
    QLabel *label_pwr4;
    QLabel *label_status2;
    QLabel *label_status1;
    QLabel *label_material3;
    QLabel *label_rate2;
    QLabel *label_material1;
    QLabel *label_pwr1;
    QLabel *label_src4;
    QLabel *label_sen3;
    QLabel *label_setTemp4;
    QLabel *label_setRate2;
    QLabel *label_pwr2;
    QLabel *label_powerCH1;
    QLabel *label_sen1;
    QLabel *label_powerCH3;
    QLabel *label_status3;
    QLabel *label_mode4;
    QLabel *label_sen2;
    QLabel *label_senPct4;
    QLabel *label_src3;
    QLabel *label_mode1;
    QLabel *label_mode2;
    QLabel *label_setTemp1;
    QLabel *label_rate3;
    QLabel *label_powerCH4;
    QLabel *label_powerCH2;
    QLabel *label_12;
    QLabel *label_15;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_18;
    QLabel *label_17;
    QLabel *label_16;
    QLabel *label_14;
    QLabel *label_13;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_9;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3_ThInfo;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_70;
    QLabel *label_71;
    QLabel *label_layer_th;
    QLabel *label_layer_th_setval;
    QLabel *label_46;
    QLabel *label_th_total;
    QLabel *label_72;
    QWidget *widget;
    QWidget *widget_2;
    QLabel *label_73_YAxis;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_3_deviation;
    DeviationLabel *label_deviation1;
    DeviationLabel *label_deviation2;
    DeviationLabel *label_deviation3;
    DeviationLabel *label_deviation4;
    DeviationLabel *label_deviation_test;
    DeviationLabel *label_deviation_test_2;
    DeviationLabel *label_deviation_test_3;
    DeviationLabel *label_deviation_test_4;

    void setupUi(QDialog *DialogSpine)
    {
        if (DialogSpine->objectName().isEmpty())
            DialogSpine->setObjectName(QString::fromUtf8("DialogSpine"));
        DialogSpine->resize(930, 580);
        DialogSpine->setFocusPolicy(Qt::StrongFocus);
        toolButton = new QToolButton(DialogSpine);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(10, 140, 31, 31));
        QFont font;
        font.setPointSize(20);
        toolButton->setFont(font);
        toolButton_2 = new QToolButton(DialogSpine);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(10, 180, 31, 31));
        toolButton_2->setFont(font);
        horizontalLayoutWidget = new QWidget(DialogSpine);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(140, 120, 631, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setCursor(QCursor(Qt::ArrowCursor));

        horizontalLayout->addWidget(pushButton);

        verticalLayoutWidget = new QWidget(DialogSpine);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, -20, 931, 81));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_procStatus = new QLabel(verticalLayoutWidget);
        label_procStatus->setObjectName(QString::fromUtf8("label_procStatus"));

        horizontalLayout_2->addWidget(label_procStatus);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_graphics = new QHBoxLayout();
        horizontalLayout_graphics->setObjectName(QString::fromUtf8("horizontalLayout_graphics"));
        comboBox_yRangeSel = new QComboBox(verticalLayoutWidget);
        comboBox_yRangeSel->addItem(QString());
        comboBox_yRangeSel->addItem(QString());
        comboBox_yRangeSel->setObjectName(QString::fromUtf8("comboBox_yRangeSel"));

        horizontalLayout_graphics->addWidget(comboBox_yRangeSel);

        comboBox_deviation = new QComboBox(verticalLayoutWidget);
        comboBox_deviation->addItem(QString());
        comboBox_deviation->addItem(QString());
        comboBox_deviation->addItem(QString());
        comboBox_deviation->setObjectName(QString::fromUtf8("comboBox_deviation"));
        QFont font1;
        font1.setPointSize(9);
        comboBox_deviation->setFont(font1);

        horizontalLayout_graphics->addWidget(comboBox_deviation);

        comboBox_5_change_xRange = new QComboBox(verticalLayoutWidget);
        comboBox_5_change_xRange->addItem(QString());
        comboBox_5_change_xRange->addItem(QString());
        comboBox_5_change_xRange->addItem(QString());
        comboBox_5_change_xRange->addItem(QString());
        comboBox_5_change_xRange->addItem(QString());
        comboBox_5_change_xRange->addItem(QString());
        comboBox_5_change_xRange->addItem(QString());
        comboBox_5_change_xRange->addItem(QString());
        comboBox_5_change_xRange->setObjectName(QString::fromUtf8("comboBox_5_change_xRange"));

        horizontalLayout_graphics->addWidget(comboBox_5_change_xRange);

        comboBox_4_ch1Zoom = new QComboBox(verticalLayoutWidget);
        comboBox_4_ch1Zoom->addItem(QString());
        comboBox_4_ch1Zoom->addItem(QString());
        comboBox_4_ch1Zoom->addItem(QString());
        comboBox_4_ch1Zoom->addItem(QString());
        comboBox_4_ch1Zoom->addItem(QString());
        comboBox_4_ch1Zoom->addItem(QString());
        comboBox_4_ch1Zoom->addItem(QString());
        comboBox_4_ch1Zoom->addItem(QString());
        comboBox_4_ch1Zoom->setObjectName(QString::fromUtf8("comboBox_4_ch1Zoom"));

        horizontalLayout_graphics->addWidget(comboBox_4_ch1Zoom);

        comboBox_3_ch2Zoom = new QComboBox(verticalLayoutWidget);
        comboBox_3_ch2Zoom->addItem(QString());
        comboBox_3_ch2Zoom->addItem(QString());
        comboBox_3_ch2Zoom->addItem(QString());
        comboBox_3_ch2Zoom->addItem(QString());
        comboBox_3_ch2Zoom->addItem(QString());
        comboBox_3_ch2Zoom->addItem(QString());
        comboBox_3_ch2Zoom->addItem(QString());
        comboBox_3_ch2Zoom->addItem(QString());
        comboBox_3_ch2Zoom->setObjectName(QString::fromUtf8("comboBox_3_ch2Zoom"));

        horizontalLayout_graphics->addWidget(comboBox_3_ch2Zoom);

        comboBox_2_ch3Zoom = new QComboBox(verticalLayoutWidget);
        comboBox_2_ch3Zoom->addItem(QString());
        comboBox_2_ch3Zoom->addItem(QString());
        comboBox_2_ch3Zoom->addItem(QString());
        comboBox_2_ch3Zoom->addItem(QString());
        comboBox_2_ch3Zoom->addItem(QString());
        comboBox_2_ch3Zoom->addItem(QString());
        comboBox_2_ch3Zoom->addItem(QString());
        comboBox_2_ch3Zoom->addItem(QString());
        comboBox_2_ch3Zoom->setObjectName(QString::fromUtf8("comboBox_2_ch3Zoom"));
        comboBox_2_ch3Zoom->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_graphics->addWidget(comboBox_2_ch3Zoom);

        comboBox_ch4Zoom = new QComboBox(verticalLayoutWidget);
        comboBox_ch4Zoom->addItem(QString());
        comboBox_ch4Zoom->addItem(QString());
        comboBox_ch4Zoom->addItem(QString());
        comboBox_ch4Zoom->addItem(QString());
        comboBox_ch4Zoom->addItem(QString());
        comboBox_ch4Zoom->addItem(QString());
        comboBox_ch4Zoom->addItem(QString());
        comboBox_ch4Zoom->addItem(QString());
        comboBox_ch4Zoom->setObjectName(QString::fromUtf8("comboBox_ch4Zoom"));
        comboBox_ch4Zoom->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_graphics->addWidget(comboBox_ch4Zoom);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFrameShape(QFrame::Panel);

        horizontalLayout_graphics->addWidget(label_6);

        pushButton_clr = new QPushButton(verticalLayoutWidget);
        pushButton_clr->setObjectName(QString::fromUtf8("pushButton_clr"));

        horizontalLayout_graphics->addWidget(pushButton_clr);

        pushButton_exit = new QPushButton(verticalLayoutWidget);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));

        horizontalLayout_graphics->addWidget(pushButton_exit);


        verticalLayout->addLayout(horizontalLayout_graphics);

        horizontalLayoutWidget_2 = new QWidget(DialogSpine);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 210, 931, 41));
        horizontalLayout_InfoHeader = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_InfoHeader->setObjectName(QString::fromUtf8("horizontalLayout_InfoHeader"));
        horizontalLayout_InfoHeader->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget = new QWidget(DialogSpine);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 270, 931, 201));
        gridLayoutInfoContent = new QGridLayout(gridLayoutWidget);
        gridLayoutInfoContent->setObjectName(QString::fromUtf8("gridLayoutInfoContent"));
        gridLayoutInfoContent->setContentsMargins(0, 0, 0, 0);
        label_rate4 = new QLabel(gridLayoutWidget);
        label_rate4->setObjectName(QString::fromUtf8("label_rate4"));

        gridLayoutInfoContent->addWidget(label_rate4, 4, 4, 1, 1);

        label_pwr3 = new QLabel(gridLayoutWidget);
        label_pwr3->setObjectName(QString::fromUtf8("label_pwr3"));

        gridLayoutInfoContent->addWidget(label_pwr3, 3, 6, 1, 1);

        label_senPct2 = new QLabel(gridLayoutWidget);
        label_senPct2->setObjectName(QString::fromUtf8("label_senPct2"));
        label_senPct2->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_senPct2, 2, 11, 1, 1);

        label_sen4 = new QLabel(gridLayoutWidget);
        label_sen4->setObjectName(QString::fromUtf8("label_sen4"));

        gridLayoutInfoContent->addWidget(label_sen4, 4, 2, 1, 1);

        label_setTemp2 = new QLabel(gridLayoutWidget);
        label_setTemp2->setObjectName(QString::fromUtf8("label_setTemp2"));
        label_setTemp2->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_setTemp2, 2, 8, 1, 1);

        label_setTemp3 = new QLabel(gridLayoutWidget);
        label_setTemp3->setObjectName(QString::fromUtf8("label_setTemp3"));

        gridLayoutInfoContent->addWidget(label_setTemp3, 3, 8, 1, 1);

        label_rate1 = new QLabel(gridLayoutWidget);
        label_rate1->setObjectName(QString::fromUtf8("label_rate1"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_rate1->sizePolicy().hasHeightForWidth());
        label_rate1->setSizePolicy(sizePolicy);
        label_rate1->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_rate1, 1, 4, 1, 1);

        label_material4 = new QLabel(gridLayoutWidget);
        label_material4->setObjectName(QString::fromUtf8("label_material4"));

        gridLayoutInfoContent->addWidget(label_material4, 4, 3, 1, 1);

        label_setRate4 = new QLabel(gridLayoutWidget);
        label_setRate4->setObjectName(QString::fromUtf8("label_setRate4"));

        gridLayoutInfoContent->addWidget(label_setRate4, 4, 5, 1, 1);

        label_mode3 = new QLabel(gridLayoutWidget);
        label_mode3->setObjectName(QString::fromUtf8("label_mode3"));

        gridLayoutInfoContent->addWidget(label_mode3, 3, 9, 1, 1);

        label_temp1 = new QLabel(gridLayoutWidget);
        label_temp1->setObjectName(QString::fromUtf8("label_temp1"));
        sizePolicy.setHeightForWidth(label_temp1->sizePolicy().hasHeightForWidth());
        label_temp1->setSizePolicy(sizePolicy);
        label_temp1->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_temp1, 1, 7, 1, 1);

        label_setRate3 = new QLabel(gridLayoutWidget);
        label_setRate3->setObjectName(QString::fromUtf8("label_setRate3"));

        gridLayoutInfoContent->addWidget(label_setRate3, 3, 5, 1, 1);

        label_status4 = new QLabel(gridLayoutWidget);
        label_status4->setObjectName(QString::fromUtf8("label_status4"));

        gridLayoutInfoContent->addWidget(label_status4, 4, 10, 1, 1);

        label_material2 = new QLabel(gridLayoutWidget);
        label_material2->setObjectName(QString::fromUtf8("label_material2"));
        label_material2->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_material2, 2, 3, 1, 1);

        label_src1 = new QLabel(gridLayoutWidget);
        label_src1->setObjectName(QString::fromUtf8("label_src1"));
        sizePolicy.setHeightForWidth(label_src1->sizePolicy().hasHeightForWidth());
        label_src1->setSizePolicy(sizePolicy);
        label_src1->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_src1, 1, 1, 1, 1);

        label_senPct3 = new QLabel(gridLayoutWidget);
        label_senPct3->setObjectName(QString::fromUtf8("label_senPct3"));

        gridLayoutInfoContent->addWidget(label_senPct3, 3, 11, 1, 1);

        label_temp3 = new QLabel(gridLayoutWidget);
        label_temp3->setObjectName(QString::fromUtf8("label_temp3"));

        gridLayoutInfoContent->addWidget(label_temp3, 3, 7, 1, 1);

        label_temp2 = new QLabel(gridLayoutWidget);
        label_temp2->setObjectName(QString::fromUtf8("label_temp2"));
        label_temp2->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_temp2, 2, 7, 1, 1);

        label_setRate1 = new QLabel(gridLayoutWidget);
        label_setRate1->setObjectName(QString::fromUtf8("label_setRate1"));
        sizePolicy.setHeightForWidth(label_setRate1->sizePolicy().hasHeightForWidth());
        label_setRate1->setSizePolicy(sizePolicy);
        label_setRate1->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_setRate1, 1, 5, 1, 1);

        label_src2 = new QLabel(gridLayoutWidget);
        label_src2->setObjectName(QString::fromUtf8("label_src2"));
        label_src2->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_src2, 2, 1, 1, 1);

        label_senPct1 = new QLabel(gridLayoutWidget);
        label_senPct1->setObjectName(QString::fromUtf8("label_senPct1"));
        sizePolicy.setHeightForWidth(label_senPct1->sizePolicy().hasHeightForWidth());
        label_senPct1->setSizePolicy(sizePolicy);
        label_senPct1->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_senPct1, 1, 11, 1, 1);

        label_temp4 = new QLabel(gridLayoutWidget);
        label_temp4->setObjectName(QString::fromUtf8("label_temp4"));

        gridLayoutInfoContent->addWidget(label_temp4, 4, 7, 1, 1);

        label_pwr4 = new QLabel(gridLayoutWidget);
        label_pwr4->setObjectName(QString::fromUtf8("label_pwr4"));

        gridLayoutInfoContent->addWidget(label_pwr4, 4, 6, 1, 1);

        label_status2 = new QLabel(gridLayoutWidget);
        label_status2->setObjectName(QString::fromUtf8("label_status2"));
        QFont font2;
        font2.setPointSize(4);
        label_status2->setFont(font2);
        label_status2->setFrameShape(QFrame::Box);
        label_status2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_status2->setWordWrap(true);

        gridLayoutInfoContent->addWidget(label_status2, 2, 10, 1, 1);

        label_status1 = new QLabel(gridLayoutWidget);
        label_status1->setObjectName(QString::fromUtf8("label_status1"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_status1->sizePolicy().hasHeightForWidth());
        label_status1->setSizePolicy(sizePolicy1);
        label_status1->setFont(font2);
        label_status1->setFrameShape(QFrame::Box);
        label_status1->setWordWrap(true);

        gridLayoutInfoContent->addWidget(label_status1, 1, 10, 1, 1);

        label_material3 = new QLabel(gridLayoutWidget);
        label_material3->setObjectName(QString::fromUtf8("label_material3"));

        gridLayoutInfoContent->addWidget(label_material3, 3, 3, 1, 1);

        label_rate2 = new QLabel(gridLayoutWidget);
        label_rate2->setObjectName(QString::fromUtf8("label_rate2"));
        label_rate2->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_rate2, 2, 4, 1, 1);

        label_material1 = new QLabel(gridLayoutWidget);
        label_material1->setObjectName(QString::fromUtf8("label_material1"));
        sizePolicy.setHeightForWidth(label_material1->sizePolicy().hasHeightForWidth());
        label_material1->setSizePolicy(sizePolicy);
        label_material1->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_material1, 1, 3, 1, 1);

        label_pwr1 = new QLabel(gridLayoutWidget);
        label_pwr1->setObjectName(QString::fromUtf8("label_pwr1"));
        sizePolicy.setHeightForWidth(label_pwr1->sizePolicy().hasHeightForWidth());
        label_pwr1->setSizePolicy(sizePolicy);
        label_pwr1->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_pwr1, 1, 6, 1, 1);

        label_src4 = new QLabel(gridLayoutWidget);
        label_src4->setObjectName(QString::fromUtf8("label_src4"));

        gridLayoutInfoContent->addWidget(label_src4, 4, 1, 1, 1);

        label_sen3 = new QLabel(gridLayoutWidget);
        label_sen3->setObjectName(QString::fromUtf8("label_sen3"));

        gridLayoutInfoContent->addWidget(label_sen3, 3, 2, 1, 1);

        label_setTemp4 = new QLabel(gridLayoutWidget);
        label_setTemp4->setObjectName(QString::fromUtf8("label_setTemp4"));

        gridLayoutInfoContent->addWidget(label_setTemp4, 4, 8, 1, 1);

        label_setRate2 = new QLabel(gridLayoutWidget);
        label_setRate2->setObjectName(QString::fromUtf8("label_setRate2"));
        label_setRate2->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_setRate2, 2, 5, 1, 1);

        label_pwr2 = new QLabel(gridLayoutWidget);
        label_pwr2->setObjectName(QString::fromUtf8("label_pwr2"));
        label_pwr2->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_pwr2, 2, 6, 1, 1);

        label_powerCH1 = new QLabel(gridLayoutWidget);
        label_powerCH1->setObjectName(QString::fromUtf8("label_powerCH1"));
        sizePolicy.setHeightForWidth(label_powerCH1->sizePolicy().hasHeightForWidth());
        label_powerCH1->setSizePolicy(sizePolicy);
        label_powerCH1->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_powerCH1, 1, 0, 1, 1);

        label_sen1 = new QLabel(gridLayoutWidget);
        label_sen1->setObjectName(QString::fromUtf8("label_sen1"));
        sizePolicy.setHeightForWidth(label_sen1->sizePolicy().hasHeightForWidth());
        label_sen1->setSizePolicy(sizePolicy);
        label_sen1->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_sen1, 1, 2, 1, 1);

        label_powerCH3 = new QLabel(gridLayoutWidget);
        label_powerCH3->setObjectName(QString::fromUtf8("label_powerCH3"));
        QFont font3;
        font3.setPointSize(6);
        label_powerCH3->setFont(font3);

        gridLayoutInfoContent->addWidget(label_powerCH3, 3, 0, 1, 1);

        label_status3 = new QLabel(gridLayoutWidget);
        label_status3->setObjectName(QString::fromUtf8("label_status3"));

        gridLayoutInfoContent->addWidget(label_status3, 3, 10, 1, 1);

        label_mode4 = new QLabel(gridLayoutWidget);
        label_mode4->setObjectName(QString::fromUtf8("label_mode4"));

        gridLayoutInfoContent->addWidget(label_mode4, 4, 9, 1, 1);

        label_sen2 = new QLabel(gridLayoutWidget);
        label_sen2->setObjectName(QString::fromUtf8("label_sen2"));
        label_sen2->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_sen2, 2, 2, 1, 1);

        label_senPct4 = new QLabel(gridLayoutWidget);
        label_senPct4->setObjectName(QString::fromUtf8("label_senPct4"));

        gridLayoutInfoContent->addWidget(label_senPct4, 4, 11, 1, 1);

        label_src3 = new QLabel(gridLayoutWidget);
        label_src3->setObjectName(QString::fromUtf8("label_src3"));

        gridLayoutInfoContent->addWidget(label_src3, 3, 1, 1, 1);

        label_mode1 = new QLabel(gridLayoutWidget);
        label_mode1->setObjectName(QString::fromUtf8("label_mode1"));
        sizePolicy.setHeightForWidth(label_mode1->sizePolicy().hasHeightForWidth());
        label_mode1->setSizePolicy(sizePolicy);
        label_mode1->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_mode1, 1, 9, 1, 1);

        label_mode2 = new QLabel(gridLayoutWidget);
        label_mode2->setObjectName(QString::fromUtf8("label_mode2"));
        label_mode2->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_mode2, 2, 9, 1, 1);

        label_setTemp1 = new QLabel(gridLayoutWidget);
        label_setTemp1->setObjectName(QString::fromUtf8("label_setTemp1"));
        sizePolicy.setHeightForWidth(label_setTemp1->sizePolicy().hasHeightForWidth());
        label_setTemp1->setSizePolicy(sizePolicy);
        label_setTemp1->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_setTemp1, 1, 8, 1, 1);

        label_rate3 = new QLabel(gridLayoutWidget);
        label_rate3->setObjectName(QString::fromUtf8("label_rate3"));

        gridLayoutInfoContent->addWidget(label_rate3, 3, 4, 1, 1);

        label_powerCH4 = new QLabel(gridLayoutWidget);
        label_powerCH4->setObjectName(QString::fromUtf8("label_powerCH4"));

        gridLayoutInfoContent->addWidget(label_powerCH4, 4, 0, 1, 1);

        label_powerCH2 = new QLabel(gridLayoutWidget);
        label_powerCH2->setObjectName(QString::fromUtf8("label_powerCH2"));
        label_powerCH2->setFont(font3);
        label_powerCH2->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_powerCH2, 2, 0, 1, 1);

        label_12 = new QLabel(gridLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);
        label_12->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_12, 0, 0, 1, 1);

        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy);
        label_15->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_15, 0, 1, 1, 1);

        label_19 = new QLabel(gridLayoutWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        sizePolicy.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy);
        label_19->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_19, 0, 2, 1, 1);

        label_20 = new QLabel(gridLayoutWidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        sizePolicy.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy);
        label_20->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_20, 0, 3, 1, 1);

        label_18 = new QLabel(gridLayoutWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        sizePolicy.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy);
        label_18->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_18, 0, 4, 1, 1);

        label_17 = new QLabel(gridLayoutWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        sizePolicy.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy);
        label_17->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_17, 0, 5, 1, 1);

        label_16 = new QLabel(gridLayoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        sizePolicy.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy);
        label_16->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_16, 0, 6, 1, 1);

        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy);
        label_14->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_14, 0, 7, 1, 1);

        label_13 = new QLabel(gridLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);
        label_13->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_13, 0, 8, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_11, 0, 9, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_10, 0, 10, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setFrameShape(QFrame::Box);

        gridLayoutInfoContent->addWidget(label_9, 0, 11, 1, 1);

        horizontalLayoutWidget_3 = new QWidget(DialogSpine);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(30, 470, 331, 80));
        horizontalLayout_3_ThInfo = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3_ThInfo->setObjectName(QString::fromUtf8("horizontalLayout_3_ThInfo"));
        horizontalLayout_3_ThInfo->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_70 = new QLabel(horizontalLayoutWidget_3);
        label_70->setObjectName(QString::fromUtf8("label_70"));

        verticalLayout_2->addWidget(label_70);

        label_71 = new QLabel(horizontalLayoutWidget_3);
        label_71->setObjectName(QString::fromUtf8("label_71"));

        verticalLayout_2->addWidget(label_71);


        horizontalLayout_3_ThInfo->addLayout(verticalLayout_2);

        label_layer_th = new QLabel(horizontalLayoutWidget_3);
        label_layer_th->setObjectName(QString::fromUtf8("label_layer_th"));

        horizontalLayout_3_ThInfo->addWidget(label_layer_th);

        label_layer_th_setval = new QLabel(horizontalLayoutWidget_3);
        label_layer_th_setval->setObjectName(QString::fromUtf8("label_layer_th_setval"));

        horizontalLayout_3_ThInfo->addWidget(label_layer_th_setval);

        label_46 = new QLabel(horizontalLayoutWidget_3);
        label_46->setObjectName(QString::fromUtf8("label_46"));

        horizontalLayout_3_ThInfo->addWidget(label_46);

        label_th_total = new QLabel(horizontalLayoutWidget_3);
        label_th_total->setObjectName(QString::fromUtf8("label_th_total"));

        horizontalLayout_3_ThInfo->addWidget(label_th_total);

        label_72 = new QLabel(DialogSpine);
        label_72->setObjectName(QString::fromUtf8("label_72"));
        label_72->setGeometry(QRect(39, 305, 21, 31));
        label_72->setMargin(0);
        widget = new QWidget(DialogSpine);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 80, 20, 271));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(85, 170, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(128, 255, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(106, 212, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(42, 85, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(56, 113, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(170, 212, 127, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush9(QColor(0, 0, 0, 128));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        widget->setPalette(palette);
        widget->setAutoFillBackground(false);
        widget_2 = new QWidget(DialogSpine);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(810, 80, 20, 271));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        widget_2->setPalette(palette1);
        widget_2->setFont(font2);
        widget_2->setAutoFillBackground(false);
        label_73_YAxis = new QLabel(DialogSpine);
        label_73_YAxis->setObjectName(QString::fromUtf8("label_73_YAxis"));
        label_73_YAxis->setGeometry(QRect(20, 180, 31, 51));
        label_73_YAxis->setLayoutDirection(Qt::LeftToRight);
        label_73_YAxis->setAutoFillBackground(false);
        horizontalLayoutWidget_4 = new QWidget(DialogSpine);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(310, 60, 288, 121));
        horizontalLayout_3_deviation = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_3_deviation->setObjectName(QString::fromUtf8("horizontalLayout_3_deviation"));
        horizontalLayout_3_deviation->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_3_deviation->setContentsMargins(0, 0, 0, 0);
        label_deviation1 = new DeviationLabel(horizontalLayoutWidget_4);
        label_deviation1->setObjectName(QString::fromUtf8("label_deviation1"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_deviation1->sizePolicy().hasHeightForWidth());
        label_deviation1->setSizePolicy(sizePolicy2);

        horizontalLayout_3_deviation->addWidget(label_deviation1);

        label_deviation2 = new DeviationLabel(horizontalLayoutWidget_4);
        label_deviation2->setObjectName(QString::fromUtf8("label_deviation2"));
        sizePolicy2.setHeightForWidth(label_deviation2->sizePolicy().hasHeightForWidth());
        label_deviation2->setSizePolicy(sizePolicy2);

        horizontalLayout_3_deviation->addWidget(label_deviation2);

        label_deviation3 = new DeviationLabel(horizontalLayoutWidget_4);
        label_deviation3->setObjectName(QString::fromUtf8("label_deviation3"));
        sizePolicy2.setHeightForWidth(label_deviation3->sizePolicy().hasHeightForWidth());
        label_deviation3->setSizePolicy(sizePolicy2);

        horizontalLayout_3_deviation->addWidget(label_deviation3);

        label_deviation4 = new DeviationLabel(horizontalLayoutWidget_4);
        label_deviation4->setObjectName(QString::fromUtf8("label_deviation4"));
        sizePolicy2.setHeightForWidth(label_deviation4->sizePolicy().hasHeightForWidth());
        label_deviation4->setSizePolicy(sizePolicy2);

        horizontalLayout_3_deviation->addWidget(label_deviation4);

        label_deviation_test = new DeviationLabel(DialogSpine);
        label_deviation_test->setObjectName(QString::fromUtf8("label_deviation_test"));
        label_deviation_test->setGeometry(QRect(100, 80, 16, 17));
        label_deviation_test_2 = new DeviationLabel(DialogSpine);
        label_deviation_test_2->setObjectName(QString::fromUtf8("label_deviation_test_2"));
        label_deviation_test_2->setGeometry(QRect(120, 80, 16, 17));
        label_deviation_test_3 = new DeviationLabel(DialogSpine);
        label_deviation_test_3->setObjectName(QString::fromUtf8("label_deviation_test_3"));
        label_deviation_test_3->setGeometry(QRect(140, 80, 16, 17));
        label_deviation_test_4 = new DeviationLabel(DialogSpine);
        label_deviation_test_4->setObjectName(QString::fromUtf8("label_deviation_test_4"));
        label_deviation_test_4->setGeometry(QRect(160, 80, 16, 17));

        retranslateUi(DialogSpine);

        QMetaObject::connectSlotsByName(DialogSpine);
    } // setupUi

    void retranslateUi(QDialog *DialogSpine)
    {
        DialogSpine->setWindowTitle(QApplication::translate("DialogSpine", "Dialog", nullptr));
        toolButton->setText(QApplication::translate("DialogSpine", "+", nullptr));
        toolButton_2->setText(QApplication::translate("DialogSpine", "-", nullptr));
        label->setText(QApplication::translate("DialogSpine", "4565", nullptr));
        label_2->setText(QApplication::translate("DialogSpine", "TextLabel", nullptr));
        pushButton->setText(QApplication::translate("DialogSpine", "Nomad", nullptr));
        label_procStatus->setText(QApplication::translate("DialogSpine", "READY TO START", nullptr));
        label_4->setText(QApplication::translate("DialogSpine", "-", nullptr));
        label_5->setText(QApplication::translate("DialogSpine", "Time", nullptr));
        comboBox_yRangeSel->setItemText(0, QApplication::translate("DialogSpine", "Auto/ON", nullptr));
        comboBox_yRangeSel->setItemText(1, QApplication::translate("DialogSpine", "Auto/OFF", nullptr));

        comboBox_deviation->setItemText(0, QApplication::translate("DialogSpine", "Dev/OFF", nullptr));
        comboBox_deviation->setItemText(1, QApplication::translate("DialogSpine", "Dev/10%", nullptr));
        comboBox_deviation->setItemText(2, QApplication::translate("DialogSpine", "Dev/50%", nullptr));

        comboBox_5_change_xRange->setItemText(0, QApplication::translate("DialogSpine", "1 Min", nullptr));
        comboBox_5_change_xRange->setItemText(1, QApplication::translate("DialogSpine", "3 Min", nullptr));
        comboBox_5_change_xRange->setItemText(2, QApplication::translate("DialogSpine", "10 Min", nullptr));
        comboBox_5_change_xRange->setItemText(3, QApplication::translate("DialogSpine", "30 Min", nullptr));
        comboBox_5_change_xRange->setItemText(4, QApplication::translate("DialogSpine", "1 Hour", nullptr));
        comboBox_5_change_xRange->setItemText(5, QApplication::translate("DialogSpine", "3 Hour", nullptr));
        comboBox_5_change_xRange->setItemText(6, QApplication::translate("DialogSpine", "10 Hour", nullptr));
        comboBox_5_change_xRange->setItemText(7, QApplication::translate("DialogSpine", "30 Hour", nullptr));

        comboBox_4_ch1Zoom->setItemText(0, QApplication::translate("DialogSpine", "0.1", nullptr));
        comboBox_4_ch1Zoom->setItemText(1, QApplication::translate("DialogSpine", "0.3", nullptr));
        comboBox_4_ch1Zoom->setItemText(2, QApplication::translate("DialogSpine", "1", nullptr));
        comboBox_4_ch1Zoom->setItemText(3, QApplication::translate("DialogSpine", "3", nullptr));
        comboBox_4_ch1Zoom->setItemText(4, QApplication::translate("DialogSpine", "10", nullptr));
        comboBox_4_ch1Zoom->setItemText(5, QApplication::translate("DialogSpine", "30", nullptr));
        comboBox_4_ch1Zoom->setItemText(6, QApplication::translate("DialogSpine", "100", nullptr));
        comboBox_4_ch1Zoom->setItemText(7, QApplication::translate("DialogSpine", "300", nullptr));

        comboBox_3_ch2Zoom->setItemText(0, QApplication::translate("DialogSpine", "0.1", nullptr));
        comboBox_3_ch2Zoom->setItemText(1, QApplication::translate("DialogSpine", "0.3", nullptr));
        comboBox_3_ch2Zoom->setItemText(2, QApplication::translate("DialogSpine", "1", nullptr));
        comboBox_3_ch2Zoom->setItemText(3, QApplication::translate("DialogSpine", "3", nullptr));
        comboBox_3_ch2Zoom->setItemText(4, QApplication::translate("DialogSpine", "10", nullptr));
        comboBox_3_ch2Zoom->setItemText(5, QApplication::translate("DialogSpine", "30", nullptr));
        comboBox_3_ch2Zoom->setItemText(6, QApplication::translate("DialogSpine", "100", nullptr));
        comboBox_3_ch2Zoom->setItemText(7, QApplication::translate("DialogSpine", "300", nullptr));

        comboBox_2_ch3Zoom->setItemText(0, QApplication::translate("DialogSpine", "0.1", nullptr));
        comboBox_2_ch3Zoom->setItemText(1, QApplication::translate("DialogSpine", "0.3", nullptr));
        comboBox_2_ch3Zoom->setItemText(2, QApplication::translate("DialogSpine", "1", nullptr));
        comboBox_2_ch3Zoom->setItemText(3, QApplication::translate("DialogSpine", "3", nullptr));
        comboBox_2_ch3Zoom->setItemText(4, QApplication::translate("DialogSpine", "10", nullptr));
        comboBox_2_ch3Zoom->setItemText(5, QApplication::translate("DialogSpine", "30", nullptr));
        comboBox_2_ch3Zoom->setItemText(6, QApplication::translate("DialogSpine", "100", nullptr));
        comboBox_2_ch3Zoom->setItemText(7, QApplication::translate("DialogSpine", "300", nullptr));

        comboBox_ch4Zoom->setItemText(0, QApplication::translate("DialogSpine", "0.1", nullptr));
        comboBox_ch4Zoom->setItemText(1, QApplication::translate("DialogSpine", "0.3", nullptr));
        comboBox_ch4Zoom->setItemText(2, QApplication::translate("DialogSpine", "1", nullptr));
        comboBox_ch4Zoom->setItemText(3, QApplication::translate("DialogSpine", "3", nullptr));
        comboBox_ch4Zoom->setItemText(4, QApplication::translate("DialogSpine", "10", nullptr));
        comboBox_ch4Zoom->setItemText(5, QApplication::translate("DialogSpine", "30", nullptr));
        comboBox_ch4Zoom->setItemText(6, QApplication::translate("DialogSpine", "100", nullptr));
        comboBox_ch4Zoom->setItemText(7, QApplication::translate("DialogSpine", "300", nullptr));

        label_6->setText(QApplication::translate("DialogSpine", "A/sec", nullptr));
        pushButton_clr->setText(QApplication::translate("DialogSpine", "CLR", nullptr));
        pushButton_exit->setText(QApplication::translate("DialogSpine", "EXIT", nullptr));
        label_rate4->setText(QString());
        label_pwr3->setText(QString());
        label_senPct2->setText(QString());
        label_sen4->setText(QString());
        label_setTemp2->setText(QString());
        label_setTemp3->setText(QString());
        label_rate1->setText(QApplication::translate("DialogSpine", "1.22", nullptr));
        label_material4->setText(QString());
        label_setRate4->setText(QString());
        label_mode3->setText(QString());
        label_temp1->setText(QApplication::translate("DialogSpine", "10", nullptr));
        label_setRate3->setText(QString());
        label_status4->setText(QString());
        label_material2->setText(QString());
        label_src1->setText(QApplication::translate("DialogSpine", "0", nullptr));
        label_senPct3->setText(QString());
        label_temp3->setText(QString());
        label_temp2->setText(QString());
        label_setRate1->setText(QApplication::translate("DialogSpine", "2", nullptr));
        label_src2->setText(QString());
        label_senPct1->setText(QString());
        label_temp4->setText(QString());
        label_pwr4->setText(QString());
        label_status2->setText(QString());
        label_status1->setText(QApplication::translate("DialogSpine", "RAMP1", nullptr));
        label_material3->setText(QString());
        label_rate2->setText(QString());
        label_material1->setText(QApplication::translate("DialogSpine", "aka", nullptr));
        label_pwr1->setText(QApplication::translate("DialogSpine", "20", nullptr));
        label_src4->setText(QString());
        label_sen3->setText(QString());
        label_setTemp4->setText(QString());
        label_setRate2->setText(QString());
        label_pwr2->setText(QString());
        label_powerCH1->setText(QApplication::translate("DialogSpine", "1", nullptr));
        label_sen1->setText(QApplication::translate("DialogSpine", "1", nullptr));
        label_powerCH3->setText(QString());
        label_status3->setText(QString());
        label_mode4->setText(QString());
        label_sen2->setText(QString());
        label_senPct4->setText(QString());
        label_src3->setText(QString());
        label_mode1->setText(QApplication::translate("DialogSpine", "Man P", nullptr));
        label_mode2->setText(QString());
        label_setTemp1->setText(QApplication::translate("DialogSpine", "30", nullptr));
        label_rate3->setText(QString());
        label_powerCH4->setText(QString());
        label_powerCH2->setText(QString());
        label_12->setText(QApplication::translate("DialogSpine", "CH", nullptr));
        label_15->setText(QApplication::translate("DialogSpine", "Src", nullptr));
        label_19->setText(QApplication::translate("DialogSpine", "Sens", nullptr));
        label_20->setText(QApplication::translate("DialogSpine", "Material", nullptr));
        label_18->setText(QApplication::translate("DialogSpine", "R [A/S]", nullptr));
        label_17->setText(QApplication::translate("DialogSpine", "R/SV", nullptr));
        label_16->setText(QApplication::translate("DialogSpine", "PWR [%]", nullptr));
        label_14->setText(QApplication::translate("DialogSpine", "T[C]", nullptr));
        label_13->setText(QApplication::translate("DialogSpine", "T/SV", nullptr));
        label_11->setText(QApplication::translate("DialogSpine", "Mode", nullptr));
        label_10->setText(QApplication::translate("DialogSpine", "Status", nullptr));
        label_9->setText(QApplication::translate("DialogSpine", "%", nullptr));
        label_70->setText(QApplication::translate("DialogSpine", "TextLabel", nullptr));
        label_71->setText(QApplication::translate("DialogSpine", "TextLabel", nullptr));
        label_layer_th->setText(QApplication::translate("DialogSpine", "0.00A", nullptr));
        label_layer_th_setval->setText(QApplication::translate("DialogSpine", "99999.00", nullptr));
        label_46->setText(QApplication::translate("DialogSpine", "Total", nullptr));
        label_th_total->setText(QApplication::translate("DialogSpine", "TextLabel", nullptr));
        label_72->setText(QApplication::translate("DialogSpine", "0", nullptr));
        label_73_YAxis->setText(QApplication::translate("DialogSpine", "R\n"
"A\n"
"T\n"
"E", nullptr));
        label_deviation1->setText(QApplication::translate("DialogSpine", "TextLabel", nullptr));
        label_deviation2->setText(QApplication::translate("DialogSpine", "TextLabel", nullptr));
        label_deviation3->setText(QApplication::translate("DialogSpine", "TextLabel", nullptr));
        label_deviation4->setText(QApplication::translate("DialogSpine", "TextLabel", nullptr));
        label_deviation_test->setText(QApplication::translate("DialogSpine", "TextLabel", nullptr));
        label_deviation_test_2->setText(QApplication::translate("DialogSpine", "TextLabel", nullptr));
        label_deviation_test_3->setText(QApplication::translate("DialogSpine", "TextLabel", nullptr));
        label_deviation_test_4->setText(QApplication::translate("DialogSpine", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSpine: public Ui_DialogSpine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSPINE_H
