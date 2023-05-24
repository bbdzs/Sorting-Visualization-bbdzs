/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_about
{
public:
    QWidget *background;
    QLabel *logo;
    QLabel *title;
    QLabel *name;
    QLabel *swu;
    QLabel *versinfo;
    QLabel *copyright;
    QWidget *line1;
    QWidget *line2;
    QLabel *title_icon;

    void setupUi(QWidget *about)
    {
        if (about->objectName().isEmpty())
            about->setObjectName(QString::fromUtf8("about"));
        about->resize(500, 400);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(about->sizePolicy().hasHeightForWidth());
        about->setSizePolicy(sizePolicy);
        about->setMinimumSize(QSize(500, 400));
        about->setMaximumSize(QSize(500, 400));
        about->setStyleSheet(QString::fromUtf8(""));
        background = new QWidget(about);
        background->setObjectName(QString::fromUtf8("background"));
        background->setGeometry(QRect(4, 4, 492, 392));
        background->setStyleSheet(QString::fromUtf8(" background-color: rgb(49, 26, 0);"));
        logo = new QLabel(background);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(0, 0, 380, 86));
        title = new QLabel(background);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(113, 140, 361, 51));
        title->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 255, 255);\n"
"padding: 0px;"));
        name = new QLabel(background);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(212, 220, 91, 31));
        name->setStyleSheet(QString::fromUtf8("color: qconicalgradient(cx:0.5, cy:0.5, angle:23.3, stop:0 rgba(205, 190, 7, 255), stop:0.0284091 rgba(191, 161, 9, 255), stop:0.0681818 rgba(175, 147, 8, 255), stop:0.159091 rgba(136, 94, 22, 255), stop:0.198864 rgba(136, 94, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(243, 198, 107, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.695 rgba(202, 174, 68, 255), stop:0.75 rgba(218, 202, 81, 255), stop:0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(255, 235, 85, 255), stop:1 rgba(200, 187, 25, 255));\n"
"padding: 0px;"));
        swu = new QLabel(background);
        swu->setObjectName(QString::fromUtf8("swu"));
        swu->setGeometry(QRect(206, 250, 101, 31));
        swu->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 254, 199);\n"
"padding: 0px;"));
        versinfo = new QLabel(background);
        versinfo->setObjectName(QString::fromUtf8("versinfo"));
        versinfo->setGeometry(QRect(205, 330, 131, 16));
        versinfo->setStyleSheet(QString::fromUtf8("font: 15px \"\345\256\213\344\275\223\";\n"
"color: rgb(255, 255, 255);\n"
"padding: 0px;"));
        copyright = new QLabel(background);
        copyright->setObjectName(QString::fromUtf8("copyright"));
        copyright->setGeometry(QRect(101, 370, 351, 16));
        copyright->setStyleSheet(QString::fromUtf8("font: 13px \"\345\256\213\344\275\223\";\n"
"color: rgb(223, 223, 223);\n"
"background-color: rgb(49, 26, 0);\n"
"padding: 0px;"));
        line1 = new QWidget(background);
        line1->setObjectName(QString::fromUtf8("line1"));
        line1->setGeometry(QRect(0, 245, 190, 2));
        line1->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(202, 155, 38, 255), stop:1 rgba(250, 236, 66, 255));\n"
""));
        line2 = new QWidget(background);
        line2->setObjectName(QString::fromUtf8("line2"));
        line2->setGeometry(QRect(300, 245, 190, 2));
        line2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0, stop:0 rgba(202, 155, 38, 255), stop:1 rgba(250, 236, 66, 255));"));
        title_icon = new QLabel(background);
        title_icon->setObjectName(QString::fromUtf8("title_icon"));
        title_icon->setGeometry(QRect(57, 143, 40, 40));

        retranslateUi(about);

        QMetaObject::connectSlotsByName(about);
    } // setupUi

    void retranslateUi(QWidget *about)
    {
        about->setWindowTitle(QCoreApplication::translate("about", "Form", nullptr));
        logo->setText(QCoreApplication::translate("about", "TextLabel", nullptr));
        title->setText(QCoreApplication::translate("about", "\346\216\222\345\272\217\347\256\227\346\263\225\345\217\257\350\247\206\345\214\226\347\263\273\347\273\237", nullptr));
        name->setText(QCoreApplication::translate("about", "\350\224\241\345\211\215\345\223\262", nullptr));
        swu->setText(QCoreApplication::translate("about", "\350\245\277\345\215\227\345\244\247\345\255\246", nullptr));
        versinfo->setText(QCoreApplication::translate("about", "\347\211\210\346\234\254\357\274\2321.0.0", nullptr));
        copyright->setText(QCoreApplication::translate("about", "Copyright \302\251 2023 \350\224\241\345\211\215\345\223\262. All rights reserved", nullptr));
        title_icon->setText(QCoreApplication::translate("about", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class about: public Ui_about {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
