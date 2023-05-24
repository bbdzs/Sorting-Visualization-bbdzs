#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/icon.ico"));

    // 水平居中靠上显示
    this->move((parent->width()-this->width())/2, (parent->height()-this->height())/2 - 25);

    // 设置无边框
    this->setWindowFlags(Qt::FramelessWindowHint);

    // 设置阴影效果
    QGraphicsDropShadowEffect * shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(10);      // 模糊半径
    shadow->setColor("#252525");    // 阴影颜色 深灰
    shadow->setOffset(8,8);         // 阴影偏移
    ui->background->setGraphicsEffect(shadow);

    // 导入和设置字体
    QFont font;
    int fontId = QFontDatabase::addApplicationFont(":/font/hgwt.ttf");
    QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
    font.setFamily(fontFamilies[0]);
    font.setPixelSize(22);
    ui->name->setFont(font);
    font.setPixelSize(20);
    ui->swu->setFont(font);

    fontId = QFontDatabase::addApplicationFont(":/font/hgxk.ttf");
    fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
    font.setFamily(fontFamilies[0]);
    font.setPixelSize(35);
    ui->title->setFont(font);


    // 显示logo 自动缩放大小
    QImage *logo = new QImage;
    logo->load(":/logo/LOGO-cqz-hor_single-trans.png");
    logo->scaled(ui->logo->size(),Qt::KeepAspectRatio);
    ui->logo->setScaledContents(true);
    ui->logo->setPixmap(QPixmap::fromImage(*logo));         //将图片放入label，使用setPixmap
    ui->logo->setAlignment(Qt::AlignCenter);                //将图片放在label中心，缩放了可以不需要这句

    // 显示icon 自动缩放大小
    QImage *icon = new QImage;
    icon->load(":/icon.png");
    icon->scaled(ui->title_icon->size(),Qt::KeepAspectRatio);

    ui->title_icon->setScaledContents(true);
    ui->title_icon->setPixmap(QPixmap::fromImage(*icon));         //将图片放入label，使用setPixmap
    ui->title_icon->setAlignment(Qt::AlignCenter);                //将图片放在label中心，缩放了可以不需要这句
}

about::~about()
{
    delete ui;
}

// 鼠标单击关闭帮助界面
void about::mousePressEvent(QMouseEvent *event)
{

    if(event->button() == Qt::LeftButton)           // 左键
        this->close();
    else if(event->button() == Qt::RightButton)     // 右键
        this->close();

}
