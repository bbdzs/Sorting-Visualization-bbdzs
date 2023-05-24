#ifndef SORTALGORITHMS_H
#define SORTALGORITHMS_H

#include <QThread>
#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QMutex>
#include <QWaitCondition>
#include <algorithm>
#include <math.h>

class sortAlgorithms : public QThread
{
    Q_OBJECT

public:
    sortAlgorithms();
    ~sortAlgorithms();

    void setSortingState(bool state);       // 设置排序状态
    void setOneStepState(bool state);       // 设置是否单步排序
    bool isSorting();                       // 获取是否正在排序
    bool isPause();                         // 获取是否处于暂停状态
    bool isOneStep();                       // 获取是否处于单步执行状态
    void setSpeed(int speed);               // 设置排序演示速度
    void setAttribute(int dataNum, int *numbers, int algorithmSelected, int speed); // 设置排序属性
    int getCmpCnt();                        // 获取比较次数
    int getOprtCnt();                       // 获取交换次数
    void stopSorting();                     // 立即停止排序用于排序过程中点击重新生成数据
    void pauseSorting();                    // 暂停排序
    void resumeSorting();                   // 继续排序

protected:
    void run();                             // 重写父类函数，protected保证可以被父类的start调用
    void process();

signals:
    void sortFinish();                  // 排序结束
    void swapColumn(int, int, int*);    // 返回需要可视化交换的柱子序号,第三个参数为排序中间过程的数组指针. 注：此信号时更新柱子的值，并不是真正的交换两个柱子，因此部分更新操作也会发送（共用）此信号！
    void updtColumn(int, bool, int*);   // 更新一个柱子的值 第二个参数为是否重置上一个更新的值的颜色
    void compareColumn(int, int);       // 高亮当前正在比较的数
    void baseColumn(int);               // 高亮基准值（快排）
    void showSBMsg(int, QString);       // 状态栏信息显示 第几个label，显示什么内容

private:
    void swap(int a, int b);                    // 交换a b两个位置的数
    void radixSort();                            // 0 基数排序
    void quickSort(int left, int right);        // 1 快速排序
    void mergeSort(int left, int right);        // 2 归并排序
    void merge(int left, int mid, int right);   //   归并排序_合并函数
    void heapSort();                            // 3 堆排序
    void max_heapify(int start, int end);       //   堆排序_构建大根堆
    void shellSort();                           // 4 希尔排序
    void insertSort();                          // 5 插入排序
    void bubbleSort();                          // 6 冒泡排序
    void selectSort();                          // 7 选择排序


    QMutex pauseLock;
    bool stop;              // 线程状态
    bool sortingDone;       // 是否完成排序
    bool pause;             // 是否处于暂停状态

    bool oneStep;           // 是否单步执行
    int algorithmSelected;  // 使用的排序算法
    int speed;              // 排序速度
    int dataNum;            // 排序数据量
    int *numbers;           // 排序数据
    int cmpCnt = 0;         // 比较次数统计
    int oprtCnt = 0;        // 排序中交换次数
};

#endif // SORTALGORITHMS_H
