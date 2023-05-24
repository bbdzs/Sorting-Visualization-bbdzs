/********************************************************************************
** Form generated from reading UI file 'helper.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPER_H
#define UI_HELPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_helper
{
public:
    QWidget *centralwidget;
    QTextEdit *instruction;
    QLabel *title;

    void setupUi(QMainWindow *helper)
    {
        if (helper->objectName().isEmpty())
            helper->setObjectName(QString::fromUtf8("helper"));
        helper->resize(640, 480);
        centralwidget = new QWidget(helper);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        instruction = new QTextEdit(centralwidget);
        instruction->setObjectName(QString::fromUtf8("instruction"));
        instruction->setGeometry(QRect(38, 110, 561, 321));
        title = new QLabel(centralwidget);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(242, 20, 151, 71));
        title->setStyleSheet(QString::fromUtf8("font: 35px \"\345\215\216\345\205\211\345\207\206\345\234\206_CNKI\";\n"
"padding: 0px;"));
        helper->setCentralWidget(centralwidget);

        retranslateUi(helper);

        QMetaObject::connectSlotsByName(helper);
    } // setupUi

    void retranslateUi(QMainWindow *helper)
    {
        helper->setWindowTitle(QCoreApplication::translate("helper", "MainWindow", nullptr));
        title->setText(QCoreApplication::translate("helper", "\344\275\277\347\224\250\350\257\264\346\230\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class helper: public Ui_helper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPER_H
