/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGridLayout *sortInfo;
    QLabel *lable_static_sortingCompareCnt;
    QLabel *lable_static_sortingDataNum;
    QLabel *label_algorithmShow;
    QLabel *label_oprtCnt;
    QLabel *label_static_algorithmShow;
    QLabel *lable_static_sortingTime;
    QLabel *label_cmpCnt;
    QLabel *label_sortingTime;
    QLabel *label_dataNum;
    QLabel *lable_static_sortingSwapCnt;
    QSpacerItem *horizontalSpacer;
    QWidget *ShowSortingVisulizaion;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *hLayout_sortingVisulization;
    QWidget *oprtButton;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_dataImport;
    QPushButton *btn_dataGenerate;
    QGridLayout *gridLayout;
    QLabel *lable_static_sortingSpeed;
    QLabel *label_static_sortingAlgorithm;
    QComboBox *comboBox_sortingalgorithm;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_static_slow;
    QSlider *slider_sortingSpeed;
    QLabel *label_static_fast;
    QGridLayout *gridLayout_2;
    QPushButton *btn_oneStep;
    QPushButton *btn_sortingPause;
    QPushButton *btn_sortingStart;
    QPushButton *btn_sortingContinue;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        sortInfo = new QGridLayout();
        sortInfo->setObjectName(QString::fromUtf8("sortInfo"));
        lable_static_sortingCompareCnt = new QLabel(centralwidget);
        lable_static_sortingCompareCnt->setObjectName(QString::fromUtf8("lable_static_sortingCompareCnt"));
        lable_static_sortingCompareCnt->setStyleSheet(QString::fromUtf8("\n"
"padding: 0px;"));
        lable_static_sortingCompareCnt->setIndent(10);

        sortInfo->addWidget(lable_static_sortingCompareCnt, 0, 5, 1, 1);

        lable_static_sortingDataNum = new QLabel(centralwidget);
        lable_static_sortingDataNum->setObjectName(QString::fromUtf8("lable_static_sortingDataNum"));
        lable_static_sortingDataNum->setStyleSheet(QString::fromUtf8("\n"
"padding: 0px;"));
        lable_static_sortingDataNum->setIndent(10);

        sortInfo->addWidget(lable_static_sortingDataNum, 0, 3, 1, 1);

        label_algorithmShow = new QLabel(centralwidget);
        label_algorithmShow->setObjectName(QString::fromUtf8("label_algorithmShow"));
        label_algorithmShow->setStyleSheet(QString::fromUtf8("font: 13px \"\345\256\213\344\275\223\";\n"
"padding: 0px;"));
        label_algorithmShow->setIndent(0);

        sortInfo->addWidget(label_algorithmShow, 0, 1, 1, 1);

        label_oprtCnt = new QLabel(centralwidget);
        label_oprtCnt->setObjectName(QString::fromUtf8("label_oprtCnt"));
        label_oprtCnt->setIndent(0);

        sortInfo->addWidget(label_oprtCnt, 0, 8, 1, 1);

        label_static_algorithmShow = new QLabel(centralwidget);
        label_static_algorithmShow->setObjectName(QString::fromUtf8("label_static_algorithmShow"));
        label_static_algorithmShow->setStyleSheet(QString::fromUtf8("\n"
"padding: 0px;"));
        label_static_algorithmShow->setIndent(10);

        sortInfo->addWidget(label_static_algorithmShow, 0, 0, 1, 1);

        lable_static_sortingTime = new QLabel(centralwidget);
        lable_static_sortingTime->setObjectName(QString::fromUtf8("lable_static_sortingTime"));
        lable_static_sortingTime->setStyleSheet(QString::fromUtf8("\n"
"padding: 0px;"));
        lable_static_sortingTime->setIndent(10);

        sortInfo->addWidget(lable_static_sortingTime, 0, 9, 1, 1);

        label_cmpCnt = new QLabel(centralwidget);
        label_cmpCnt->setObjectName(QString::fromUtf8("label_cmpCnt"));
        label_cmpCnt->setIndent(0);

        sortInfo->addWidget(label_cmpCnt, 0, 6, 1, 1);

        label_sortingTime = new QLabel(centralwidget);
        label_sortingTime->setObjectName(QString::fromUtf8("label_sortingTime"));
        label_sortingTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_sortingTime->setIndent(0);

        sortInfo->addWidget(label_sortingTime, 0, 10, 1, 1);

        label_dataNum = new QLabel(centralwidget);
        label_dataNum->setObjectName(QString::fromUtf8("label_dataNum"));
        label_dataNum->setStyleSheet(QString::fromUtf8(""));
        label_dataNum->setIndent(0);

        sortInfo->addWidget(label_dataNum, 0, 4, 1, 1);

        lable_static_sortingSwapCnt = new QLabel(centralwidget);
        lable_static_sortingSwapCnt->setObjectName(QString::fromUtf8("lable_static_sortingSwapCnt"));
        lable_static_sortingSwapCnt->setStyleSheet(QString::fromUtf8("padding: 0px;"));
        lable_static_sortingSwapCnt->setIndent(10);

        sortInfo->addWidget(lable_static_sortingSwapCnt, 0, 7, 1, 1);

        horizontalSpacer = new QSpacerItem(148, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        sortInfo->addItem(horizontalSpacer, 0, 2, 1, 1);


        gridLayout_3->addLayout(sortInfo, 0, 0, 1, 1);

        ShowSortingVisulizaion = new QWidget(centralwidget);
        ShowSortingVisulizaion->setObjectName(QString::fromUtf8("ShowSortingVisulizaion"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(ShowSortingVisulizaion->sizePolicy().hasHeightForWidth());
        ShowSortingVisulizaion->setSizePolicy(sizePolicy1);
        ShowSortingVisulizaion->setMinimumSize(QSize(760, 400));
        ShowSortingVisulizaion->setBaseSize(QSize(0, 0));
        ShowSortingVisulizaion->setContextMenuPolicy(Qt::NoContextMenu);
        ShowSortingVisulizaion->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout_3 = new QHBoxLayout(ShowSortingVisulizaion);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        hLayout_sortingVisulization = new QHBoxLayout();
        hLayout_sortingVisulization->setSpacing(2);
        hLayout_sortingVisulization->setObjectName(QString::fromUtf8("hLayout_sortingVisulization"));
        hLayout_sortingVisulization->setSizeConstraint(QLayout::SetMaximumSize);
        hLayout_sortingVisulization->setContentsMargins(1, -1, 0, -1);

        horizontalLayout_3->addLayout(hLayout_sortingVisulization);


        gridLayout_3->addWidget(ShowSortingVisulizaion, 1, 0, 1, 1);

        oprtButton = new QWidget(centralwidget);
        oprtButton->setObjectName(QString::fromUtf8("oprtButton"));
        horizontalLayout_2 = new QHBoxLayout(oprtButton);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(4, 0, 4, -1);
        btn_dataImport = new QPushButton(oprtButton);
        btn_dataImport->setObjectName(QString::fromUtf8("btn_dataImport"));
        btn_dataImport->setStyleSheet(QString::fromUtf8("font: 13px \"\345\256\213\344\275\223\";"));

        verticalLayout->addWidget(btn_dataImport);

        btn_dataGenerate = new QPushButton(oprtButton);
        btn_dataGenerate->setObjectName(QString::fromUtf8("btn_dataGenerate"));
        btn_dataGenerate->setStyleSheet(QString::fromUtf8("font: 13px \"\345\256\213\344\275\223\";"));

        verticalLayout->addWidget(btn_dataGenerate);


        horizontalLayout_2->addLayout(verticalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 5, -1, 5);
        lable_static_sortingSpeed = new QLabel(oprtButton);
        lable_static_sortingSpeed->setObjectName(QString::fromUtf8("lable_static_sortingSpeed"));
        lable_static_sortingSpeed->setStyleSheet(QString::fromUtf8("font: 13px \"\345\256\213\344\275\223\";"));

        gridLayout->addWidget(lable_static_sortingSpeed, 0, 0, 1, 1);

        label_static_sortingAlgorithm = new QLabel(oprtButton);
        label_static_sortingAlgorithm->setObjectName(QString::fromUtf8("label_static_sortingAlgorithm"));
        label_static_sortingAlgorithm->setStyleSheet(QString::fromUtf8("font: 13px \"\345\256\213\344\275\223\";"));

        gridLayout->addWidget(label_static_sortingAlgorithm, 1, 0, 1, 1);

        comboBox_sortingalgorithm = new QComboBox(oprtButton);
        comboBox_sortingalgorithm->setObjectName(QString::fromUtf8("comboBox_sortingalgorithm"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBox_sortingalgorithm->sizePolicy().hasHeightForWidth());
        comboBox_sortingalgorithm->setSizePolicy(sizePolicy2);
        comboBox_sortingalgorithm->setStyleSheet(QString::fromUtf8("font: 13px \"\345\256\213\344\275\223\";"));

        gridLayout->addWidget(comboBox_sortingalgorithm, 1, 1, 1, 1);

        widget_3 = new QWidget(oprtButton);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy3);
        widget_3->setStyleSheet(QString::fromUtf8("font: 13px \"\345\256\213\344\275\223\";\n"
"padding: 0px;"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_static_slow = new QLabel(widget_3);
        label_static_slow->setObjectName(QString::fromUtf8("label_static_slow"));
        label_static_slow->setStyleSheet(QString::fromUtf8("font: 13px \"\345\256\213\344\275\223\";\n"
"padding: 0px;"));

        horizontalLayout->addWidget(label_static_slow);

        slider_sortingSpeed = new QSlider(widget_3);
        slider_sortingSpeed->setObjectName(QString::fromUtf8("slider_sortingSpeed"));
        slider_sortingSpeed->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(slider_sortingSpeed);

        label_static_fast = new QLabel(widget_3);
        label_static_fast->setObjectName(QString::fromUtf8("label_static_fast"));

        horizontalLayout->addWidget(label_static_fast);


        gridLayout->addWidget(widget_3, 0, 1, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1);

        horizontalLayout_2->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetMinAndMaxSize);
        gridLayout_2->setHorizontalSpacing(10);
        gridLayout_2->setVerticalSpacing(5);
        gridLayout_2->setContentsMargins(4, 4, 4, 4);
        btn_oneStep = new QPushButton(oprtButton);
        btn_oneStep->setObjectName(QString::fromUtf8("btn_oneStep"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(1);
        sizePolicy4.setHeightForWidth(btn_oneStep->sizePolicy().hasHeightForWidth());
        btn_oneStep->setSizePolicy(sizePolicy4);
        btn_oneStep->setToolTipDuration(2000);
        btn_oneStep->setStyleSheet(QString::fromUtf8("font: 13px \"\345\256\213\344\275\223\";"));

        gridLayout_2->addWidget(btn_oneStep, 0, 1, 2, 1);

        btn_sortingPause = new QPushButton(oprtButton);
        btn_sortingPause->setObjectName(QString::fromUtf8("btn_sortingPause"));
        btn_sortingPause->setToolTipDuration(2000);
        btn_sortingPause->setStyleSheet(QString::fromUtf8("font: 13px \"\345\256\213\344\275\223\";"));

        gridLayout_2->addWidget(btn_sortingPause, 0, 2, 1, 1);

        btn_sortingStart = new QPushButton(oprtButton);
        btn_sortingStart->setObjectName(QString::fromUtf8("btn_sortingStart"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(btn_sortingStart->sizePolicy().hasHeightForWidth());
        btn_sortingStart->setSizePolicy(sizePolicy5);
        btn_sortingStart->setToolTipDuration(2500);
        btn_sortingStart->setStyleSheet(QString::fromUtf8("font: 13px \"\345\256\213\344\275\223\";"));

        gridLayout_2->addWidget(btn_sortingStart, 0, 0, 2, 1);

        btn_sortingContinue = new QPushButton(oprtButton);
        btn_sortingContinue->setObjectName(QString::fromUtf8("btn_sortingContinue"));
        btn_sortingContinue->setToolTipDuration(2000);
        btn_sortingContinue->setStyleSheet(QString::fromUtf8("font: 13px \"\345\256\213\344\275\223\";"));

        gridLayout_2->addWidget(btn_sortingContinue, 1, 2, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);


        gridLayout_3->addWidget(oprtButton, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lable_static_sortingCompareCnt->setText(QCoreApplication::translate("MainWindow", "\346\257\224\350\276\203\346\254\241\346\225\260:", nullptr));
        lable_static_sortingDataNum->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\351\207\217:", nullptr));
        label_algorithmShow->setText(QCoreApplication::translate("MainWindow", " \346\216\222\345\272\217\346\234\252\345\274\200\345\247\213", nullptr));
        label_oprtCnt->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_static_algorithmShow->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\346\216\222\345\272\217\347\256\227\346\263\225:", nullptr));
        lable_static_sortingTime->setText(QCoreApplication::translate("MainWindow", "\346\216\222\345\272\217\347\224\250\346\227\266:", nullptr));
        label_cmpCnt->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_sortingTime->setText(QCoreApplication::translate("MainWindow", "0.00s", nullptr));
        label_dataNum->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lable_static_sortingSwapCnt->setText(QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234\346\254\241\346\225\260:", nullptr));
#if QT_CONFIG(tooltip)
        btn_dataImport->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        btn_dataImport->setStatusTip(QCoreApplication::translate("MainWindow", "\345\257\274\345\205\245\346\226\260\346\225\260\346\215\256\357\274\214\345\274\200\345\247\213\346\226\260\347\232\204\346\216\222\345\272\217\343\200\202 \357\274\210\350\213\245\345\244\204\344\272\216\346\216\222\345\272\217\350\277\207\347\250\213\344\270\255\357\274\214\345\210\231\344\274\232\345\201\234\346\255\242\346\255\243\345\234\250\350\277\233\350\241\214\347\232\204\346\216\222\345\272\217\357\274\211", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        btn_dataImport->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        btn_dataImport->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\205\245\346\225\260\346\215\256", nullptr));
#if QT_CONFIG(tooltip)
        btn_dataGenerate->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        btn_dataGenerate->setStatusTip(QCoreApplication::translate("MainWindow", "\347\224\237\346\210\220\346\226\260\346\225\260\346\215\256\357\274\214\345\274\200\345\247\213\346\226\260\347\232\204\346\216\222\345\272\217\343\200\202 \357\274\210\350\213\245\345\244\204\344\272\216\346\216\222\345\272\217\350\277\207\347\250\213\344\270\255\357\274\214\345\210\231\344\274\232\345\201\234\346\255\242\346\255\243\345\234\250\350\277\233\350\241\214\347\232\204\346\216\222\345\272\217\357\274\211", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        btn_dataGenerate->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        btn_dataGenerate->setText(QCoreApplication::translate("MainWindow", "\347\224\237\346\210\220\346\225\260\346\215\256", nullptr));
        lable_static_sortingSpeed->setText(QCoreApplication::translate("MainWindow", "\346\274\224\347\244\272\351\200\237\345\272\246\357\274\232", nullptr));
        label_static_sortingAlgorithm->setText(QCoreApplication::translate("MainWindow", "\346\216\222\345\272\217\347\256\227\346\263\225\357\274\232", nullptr));
        label_static_slow->setText(QCoreApplication::translate("MainWindow", "\346\205\242", nullptr));
        label_static_fast->setText(QCoreApplication::translate("MainWindow", "\345\277\253", nullptr));
#if QT_CONFIG(tooltip)
        btn_oneStep->setToolTip(QCoreApplication::translate("MainWindow", "\345\215\225\346\255\245\346\211\247\350\241\214\345\275\223\345\211\215\346\216\222\345\272\217\357\274\214\347\202\271\345\207\273\344\270\200\346\254\241\346\211\247\350\241\214\344\270\200\346\255\245", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        btn_oneStep->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        btn_oneStep->setText(QCoreApplication::translate("MainWindow", "\345\215\225\346\255\245\346\211\247\350\241\214", nullptr));
#if QT_CONFIG(tooltip)
        btn_sortingPause->setToolTip(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234\345\275\223\345\211\215\346\216\222\345\272\217", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        btn_sortingPause->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        btn_sortingPause->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        btn_sortingPause->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234\346\216\222\345\272\217", nullptr));
#if QT_CONFIG(tooltip)
        btn_sortingStart->setToolTip(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\345\275\223\345\211\215\351\200\211\346\213\251\347\232\204\346\216\222\345\272\217\343\200\202 \346\263\250\346\204\217\357\274\232\346\216\222\345\272\217\350\277\207\347\250\213\344\270\255\346\227\240\346\263\225\346\224\271\345\217\230\347\252\227\345\217\243\345\244\247\345\260\217\357\274\201", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        btn_sortingStart->setStatusTip(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\345\275\223\345\211\215\351\200\211\346\213\251\347\232\204\346\216\222\345\272\217\343\200\202 \346\263\250\346\204\217\357\274\232\346\216\222\345\272\217\350\277\207\347\250\213\344\270\255\346\227\240\346\263\225\346\224\271\345\217\230\347\252\227\345\217\243\345\244\247\345\260\217\357\274\201", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        btn_sortingStart->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        btn_sortingStart->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\346\216\222\345\272\217", nullptr));
#if QT_CONFIG(tooltip)
        btn_sortingContinue->setToolTip(QCoreApplication::translate("MainWindow", "\347\273\247\347\273\255\346\232\202\345\201\234\347\232\204\346\216\222\345\272\217", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        btn_sortingContinue->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        btn_sortingContinue->setText(QCoreApplication::translate("MainWindow", "\347\273\247\347\273\255\346\216\222\345\272\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
