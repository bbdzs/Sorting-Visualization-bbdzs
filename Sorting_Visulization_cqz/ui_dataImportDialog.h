/********************************************************************************
** Form generated from reading UI file 'dataImportDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAIMPORTDIALOG_H
#define UI_DATAIMPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dataImportDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QFrame *line_3;
    QFrame *line;
    QLabel *label_3;
    QFrame *line_4;
    QLabel *label_5;
    QLabel *label_4;
    QFrame *line_5;
    QFrame *line_2;
    QWidget *widget_2;
    QPushButton *btn_openFile;
    QLabel *label;
    QLineEdit *pathShow;
    QWidget *widget_3;
    QTextEdit *dataShow;
    QLabel *label_2;

    void setupUi(QDialog *dataImportDialog)
    {
        if (dataImportDialog->objectName().isEmpty())
            dataImportDialog->setObjectName(QString::fromUtf8("dataImportDialog"));
        dataImportDialog->resize(400, 350);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dataImportDialog->sizePolicy().hasHeightForWidth());
        dataImportDialog->setSizePolicy(sizePolicy);
        dataImportDialog->setMinimumSize(QSize(400, 350));
        dataImportDialog->setMaximumSize(QSize(400, 350));
        buttonBox = new QDialogButtonBox(dataImportDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 310, 341, 32));
        buttonBox->setCursor(QCursor(Qt::PointingHandCursor));
        buttonBox->setStyleSheet(QString::fromUtf8(""));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(dataImportDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 5, 361, 80));
        line_3 = new QFrame(widget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(350, 10, 20, 61));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line = new QFrame(widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(-2, 63, 361, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(144, 0, 81, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 12px \"\345\256\213\344\275\223\";\n"
"padding: 0px;"));
        line_4 = new QFrame(widget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(0, 3, 130, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(75, 25, 241, 16));
        label_5->setStyleSheet(QString::fromUtf8("font: 12px \"\345\256\213\344\275\223\";\n"
"padding: 0px;"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(75, 45, 241, 16));
        label_4->setStyleSheet(QString::fromUtf8("font: 12px \"\345\256\213\344\275\223\";\n"
"padding: 0px;"));
        line_5 = new QFrame(widget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(230, 3, 130, 16));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(widget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(-7, 10, 16, 61));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        widget_2 = new QWidget(dataImportDialog);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(20, 85, 361, 61));
        btn_openFile = new QPushButton(widget_2);
        btn_openFile->setObjectName(QString::fromUtf8("btn_openFile"));
        btn_openFile->setGeometry(QRect(285, 30, 75, 23));
        btn_openFile->setCursor(QCursor(Qt::PointingHandCursor));
        btn_openFile->setStyleSheet(QString::fromUtf8("font: 12px \"\345\256\213\344\275\223\";\n"
"padding: 0px;"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 1, 101, 20));
        label->setStyleSheet(QString::fromUtf8("font: 12px \"\345\256\213\344\275\223\";\n"
"padding: 0px;"));
        pathShow = new QLineEdit(widget_2);
        pathShow->setObjectName(QString::fromUtf8("pathShow"));
        pathShow->setGeometry(QRect(0, 31, 271, 20));
        pathShow->setEchoMode(QLineEdit::Normal);
        widget_3 = new QWidget(dataImportDialog);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(20, 140, 361, 161));
        dataShow = new QTextEdit(widget_3);
        dataShow->setObjectName(QString::fromUtf8("dataShow"));
        dataShow->setGeometry(QRect(0, 30, 360, 131));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 101, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 12px \"\345\256\213\344\275\223\";\n"
"padding: 0px;"));

        retranslateUi(dataImportDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), dataImportDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dataImportDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(dataImportDialog);
    } // setupUi

    void retranslateUi(QDialog *dataImportDialog)
    {
        dataImportDialog->setWindowTitle(QCoreApplication::translate("dataImportDialog", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("dataImportDialog", "\346\225\260\346\215\256\346\240\274\345\274\217\350\257\264\346\230\216", nullptr));
        label_5->setText(QCoreApplication::translate("dataImportDialog", "\346\226\207\344\273\266\345\205\261n+1\350\241\214 (n <= 300)\357\274\214\346\257\217\350\241\214\344\270\200\344\270\252\346\225\260\343\200\202", nullptr));
        label_4->setText(QCoreApplication::translate("dataImportDialog", "\347\254\254\344\270\200\350\241\214\344\270\272\346\225\260\346\215\256\351\207\217\357\274\214\345\205\266\344\275\231n\350\241\214\344\270\272\345\276\205\346\216\222\345\272\217\346\225\260\346\215\256\343\200\202", nullptr));
        btn_openFile->setText(QCoreApplication::translate("dataImportDialog", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        label->setText(QCoreApplication::translate("dataImportDialog", "\350\257\267\351\200\211\346\213\251\346\225\260\346\215\256\346\226\207\344\273\266\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("dataImportDialog", "\350\257\267\346\243\200\346\237\245\346\226\207\344\273\266\345\206\205\345\256\271\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dataImportDialog: public Ui_dataImportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAIMPORTDIALOG_H
