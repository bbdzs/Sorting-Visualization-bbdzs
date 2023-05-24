#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTime>        // 用于随机数生成
#include <QInputDialog>
#include <QMessageBox>
#include <QTimer>
#include <vector>
#include <QMouseEvent>
#include <QFontDatabase>
#include "sortAlgorithms.h"
#include "dataImportDialog.h"
#include "about.h"
#include "helper.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    const int HLAYOUTWIDTH = 780;       // 默认柱状图区域大小 用于计算缩放倍数
    const int HLAYOUTHEIGHT = 410;      // 默认柱状图区域大小 用于计算缩放倍数
    double multiWidth = 1.0;            // 目前窗口宽度的缩放倍数 (窗口默认大小800x600)
    double multiHigh = 1.0;             // 目前窗口高度的缩放倍数 (窗口默认大小800x600)
    double columnWidth;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // 按钮
    void on_btn_dataImport_clicked();                   // 导入数据按钮
    void on_btn_dataGenerate_clicked();                 // 生成数据按钮
    void on_btn_sortingStart_clicked();                 // 开始排序按钮
    void on_btn_sortingPause_clicked();                 // 暂停排序按钮
    void on_btn_sortingContinue_clicked();              // 继续排序按钮
    void on_btn_oneStep_clicked();                      // 单步执行按钮

    //菜单栏
    void menuAct_actRadixSort();
    void menuAct_actQuickSort();
    void menuAct_actMergeSort();
    void menuAct_actHeapSort();
    void menuAct_actShellSort();
    void menuAct_actInsertSort();
    void menuAct_actBubbleSort();
    void menuAct_actSelectSort();

    void menuAct_actHelper();
    void menuAct_actAbout();

    // 其他
    void setSpeed(int speed);                           // 根据滑块设置速度
    void sortingAlgorithm(int index);                   // 用户选择了排序算法
    void updateColumns(int a, int b, int *newHeights);  // 接受排序过程对象发来的交换信号，更新界面中两个柱子的值
    void updateOneColumn(int c, bool resetPrev, int *newHeights);         // 更新界面中一个柱子的值
    void highLightColumns(int a, int b);                // 单次排序时，高亮正在比较的元素
    void highLightBase(int base);                       // 单次排序时，高亮基准值（部分算法）
    void showFinish();                                  // 接受排序完成信号，执行完成动画
    void updateSortingTime();                           // 更新排序用时
    void sbShow(int num, QString text);                 // 状态栏信息显示 第num个label，显示text内容



private:
    void initMenuBar();                                 // 初始化菜单栏和对应的槽
    void dataGenerator();                               // 生成排序数据打乱后显示到界面
    void addDataColumns();                              // 将数据用柱状显示到界面
    void deleteColumns();                               // 删除排序视图柱子
    virtual void mouseMoveEvent(QMouseEvent *event) override;   // 按下鼠标左键移动时输出鼠标坐标 用于调试
    virtual void resizeEvent(QResizeEvent* event) override;     // 重载窗口大小调整事件，修改柱状图到合适高度
    void initVar();                     // 初始化统计信息变量
    void initLabel();                   // 初始化统计信息显示标签
    void debug_outNumber();             // 输出numbers数组查看数据

    // 对象
    Ui::MainWindow *ui;
    sortAlgorithms *sortCtrl;   // 排序过程总控制对象
    QLabel *columns;            // 与numbers数组对应的柱子对象
    QTimer* timer;              // 排序计时器
    QLabel *sortName;           // 状态里显示算法名称    从左到右第1个label
    QLabel *oprtContent;        // 状态栏显示操作内容    从左到右第2个label
    QLabel *sortDscrb;          // 状态栏显示算法描述    从左到右第3个label
    QLabel *keyValue;           // 状态栏显示关键变量的值 从左到右第4个label

    // 菜单栏
    QMenu *menu_algorithm;
    QAction *actRadixSort;
    QAction *actQuickSort;
    QAction *actMergeSort;
    QAction *actHeapSort;
    QAction *actShellSort;
    QAction *actInsertSort;
    QAction *actBubbleSort;
    QAction *actSelectSort;

    QMenu *menu_help;
    QAction *actHelper;
    QAction *actAbout;

    // 变量
    bool sorted = 0;            // 当前数据是否已排序
    bool dataGenerating = 0;    // 是否正在生成数据
    bool dataImporting = 0;     // 是否正在导入数据
    bool datahaved = 0;         // 是否已经有了数据
    int algorithmSelected = 1;  // 当前用户选择的排序算法序号 初始状态为快排_手工
    int sortSpeed = 50;         // 用户选择的排序速度
    int prevDataNum = 0;        // 上次排序演示数据量,用于生成数据中记忆上次数值
    int dataNum;                // 待排序演示数据量，初值100
    int *numbers;               // 整数数组，存储待排序数据
    float sortingTime = 0.00;   // 排序用时
    int prevUpdtA = -1, prevUpdtB = -1;             // 上次更新的柱子，记录后用于修改柱子颜色
    std::vector<int> prevUpdtC;                          // 更新单个值时可选择是否重置之前的更新颜色，用于储存哪些值没有重置
    int prevCmpA = -1, prevCmpB = -1;               // 上次比较时高亮的元素
    int prevBase = -1;                              // 上次的基准值
};
#endif // MAINWINDOW_H
