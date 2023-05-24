#ifndef HELPER_H
#define HELPER_H

#include <QMainWindow>
#include <QFile>

namespace Ui {
class helper;
}

class helper : public QMainWindow
{
    Q_OBJECT

public:
    explicit helper(QWidget *parent = nullptr);
    ~helper();

private:
    Ui::helper *ui;
};

#endif // HELPER_H
