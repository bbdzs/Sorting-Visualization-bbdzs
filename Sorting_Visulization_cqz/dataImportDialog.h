#ifndef DATAIMPORTDIALOG_H
#define DATAIMPORTDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include <QTextCodec>
#include <QStandardPaths>
#include <QMessageBox>

namespace Ui {
class dataImportDialog;
}

class dataImportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit dataImportDialog(QWidget *parent = nullptr);
    ~dataImportDialog();
    QString getFilePath();      // 外部获取用户选择的文件路径

private slots:
    void btn_openFile();

private:
    Ui::dataImportDialog *ui;
    QString path;
};

#endif // DATAIMPORTDIALOG_H
