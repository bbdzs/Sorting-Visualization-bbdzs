#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>
#include <QFontDatabase>
#include <QIcon>

namespace Ui {
class about;
}

class about : public QWidget
{
    Q_OBJECT

public:
    explicit about(QWidget *parent = nullptr);
    ~about();

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::about *ui;
};

#endif // ABOUT_H
