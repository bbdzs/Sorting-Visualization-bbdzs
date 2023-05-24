#include "dataImportDialog.h"
#include "ui_dataImportDialog.h"

dataImportDialog::dataImportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dataImportDialog)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/icon.ico"));
    this->setWindowTitle("请选择文件");

    // 设置样式表
    QFile styleFile(":/qdarkstyle/style.qss");
    QString styleSheet;
    if (styleFile.open(QIODevice::ReadOnly))
    {

        styleSheet = QLatin1String(styleFile.readAll());
        this->setStyleSheet(styleSheet);
    }
    styleFile.close();

    // 功能
    ui->pathShow->setReadOnly(true);
    ui->pathShow->setPlaceholderText("文件路径");
    ui->dataShow->setReadOnly(true);
    ui->dataShow->setPlaceholderText("请打开文件...");

    connect(ui->btn_openFile, SIGNAL(clicked()), this, SLOT(btn_openFile()));


}

dataImportDialog::~dataImportDialog()
{
    delete ui;
}

QString dataImportDialog::getFilePath()
{
    return path;
}

void dataImportDialog::btn_openFile()
{
    QMessageBox::Ok == QMessageBox::information(this, "提示", "1、请确保文件中的数据格式正确，否则将无法排序\n2、程序不会修改读入数据，数据大小将直接作为柱状图的像素高度显示在屏幕中，不合适的高度将影响您的使用体验", QMessageBox::Ok);


    //点击打开后新开一个文件选择窗口
    QFileDialog *qfd = new QFileDialog(this,"文件", QStandardPaths::writableLocation(QStandardPaths::DesktopLocation));

    //获取选中后的文件路径进行显示
    path = qfd->getOpenFileName();
    ui->pathShow->setText(path);

    //设置文本编码格式
    QTextCodec *qtc = QTextCodec::codecForName("utf-8");

    //读取文件中的内容
    QFile *qf = new QFile(path);
    qf->open(QIODevice::ReadOnly);
    QByteArray qby = qf->readAll();
    ui->dataShow->setText(qtc->toUnicode(qby));
    qDebug()<<path;
    qf->close();
}
