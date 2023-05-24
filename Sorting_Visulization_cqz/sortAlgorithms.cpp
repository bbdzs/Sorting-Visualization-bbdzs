#include "sortAlgorithms.h"

sortAlgorithms::sortAlgorithms()
{
    stop = 1;    // 初始不在排序状态
    cmpCnt = 0;     // 初始化比较次数
    oprtCnt = 0;
    oneStep = 0;    // 初始非单步执行状态
    pause = 0;
}

sortAlgorithms::~sortAlgorithms()
{

}

// 是否正在排序
bool sortAlgorithms::isSorting()
{
    if(stop || sortingDone) return false;
    return true;
}

// 是否处于单步执行状态
bool sortAlgorithms::isOneStep()
{
    return oneStep;
}

// 是否处于暂停状态
bool sortAlgorithms::isPause()
{
    return pause;
}

// 设置排序状态
void sortAlgorithms::setSortingState(bool state)
{
    sortingDone = !state;
}

// 设置是否单步排序
void sortAlgorithms::setOneStepState(bool state)
{
    oneStep = state;
}

// 设置排序演示速度
void sortAlgorithms::setSpeed(int speed)
{
    this->speed = speed;
}

// 设置排序属性
void sortAlgorithms::setAttribute(int dataNum, int *numbers, int algorithmSelected, int speed)
{
    this->dataNum = dataNum;
    this->numbers = numbers;
    this->algorithmSelected = algorithmSelected;
    this->speed = speed;
//    this->stop = false;     // 排序即将开始，若当前处于停止状态需要置成false
}

// 获取比较次数
int sortAlgorithms::getCmpCnt()
{
    return cmpCnt;
}

// 获取交换次数
int sortAlgorithms::getOprtCnt()
{
    return oprtCnt;
}

// 停止排序线程
void sortAlgorithms::stopSorting()
{
    stop = true;
}

// 暂停排序
void sortAlgorithms::pauseSorting()
{
    //qDebug()<<"暂停排序";
    if(!pause)
    {
        this->pauseLock.lock();
        pause = true;
    }
}

// 继续排序
void sortAlgorithms::resumeSorting()
{
    //qDebug()<<"继续排序";
    if(pause)
    {
        this->pauseLock.unlock();
        pause = false;
    }
}

void sortAlgorithms::run()
{
    stop = false;
    while(!stop && !sortingDone)
    {
        process();
    }
    quit();
    wait();

}

void sortAlgorithms::process()
{
    // 重置比较和交换次数
    cmpCnt = 0;
    oprtCnt = 0;

    // 调用快速排序的函数
    switch (algorithmSelected)
    {
    case 0:     // 基数排序
        while(!stop && !sortingDone)
        {
            radixSort();
            if(stop) return;
            sortingDone = 1;
        }
        break;

    case 1:     // 快速排序
        while(!stop && !sortingDone)
        {
            quickSort(0, dataNum - 1);
            if(stop) return;
            sortingDone = 1;
        }
        break;

    case 2:     // 归并排序
        while(!stop && !sortingDone)
        {
            mergeSort(0, dataNum - 1);
            if(stop) return;
            sortingDone = 1;
        }
        break;

    case 3:     // 堆排序
        while(!stop && !sortingDone)
        {
            heapSort();
            if(stop) return;
            sortingDone = 1;
        }
        break;

    case 4:     // 希尔排序
        while(!stop && !sortingDone)
        {
            shellSort();
            if(stop) return;
            sortingDone = 1;
        }
        break;

    case 5:     // 插入排序
        while(!stop && !sortingDone)
        {
            insertSort();
            if(stop) return;
            sortingDone = 1;
        }
        break;

    case 6:     // 冒泡排序
        while(!stop && !sortingDone)
        {
            bubbleSort();
            if(stop) return;
            sortingDone = 1;
        }
        break;

    case 7:     // 选择排序
        while(!stop && !sortingDone)
        {
            selectSort();
            if(stop) return;
            sortingDone = 1;
        }
        break;
    }

    //排序结束，发送结束的信号
    emit showSBMsg(1, QString("排序已完成"));
    emit showSBMsg(2, QString(""));     // 清空操作和描述
    emit showSBMsg(3, QString(""));
    emit showSBMsg(4, QString(""));
    emit sortFinish();
    stop = true;
}

// 交换a b两个位置的数
void sortAlgorithms::swap(int a, int b)
{
    oprtCnt++;
    int temp = numbers[a];
    numbers[a] = numbers[b];
    numbers[b] = temp;
}

// 0 基数排序
void sortAlgorithms::radixSort()
{
    // 找出最大元素
    int maximum = numbers[0];
    int max_flag = 0;

    for(int i = 1; i < dataNum; i++)
    {
        emit showSBMsg(2, QString("访问下标%1").arg(i));
        emit showSBMsg(3, QString("找出整个数组的最大元素"));

        if(stop) return;

        pauseLock.lock();
        pauseLock.unlock();
        emit compareColumn(i, max_flag);
        emit baseColumn(max_flag);
        msleep(speed);

        cmpCnt++;
        maximum = std::max(maximum, numbers[i]);
        if(maximum == numbers[i]) max_flag = i;
    }

    // 计算最大数的位数
    int digits = 0;

    while(maximum > 0)
    {
        if(stop) return;

        digits++;
        maximum /= 10;
    }

    emit showSBMsg(4, QString("最大元素位数为%1").arg(digits));

    // 根据最低有效数字排列
    for(int i = 0; i < digits; i++)
    {
        if(stop) return;

        int power = pow(10, i);     // 用于下面取出每一位
        int temp[dataNum];          // 辅助数组
        int count[10];              // 计数数组，用于排列0-9
        memset(count, 0, sizeof(count));

        // 按位大小统计个数
        for(int j = 0; j < dataNum; j++)
        {
            if(stop) return;


            int num = (numbers[j]/power) % 10;
            count[num]++;

            pauseLock.lock();
            pauseLock.unlock();
            cmpCnt++;                   // 算访问次数，虽然没有比较，但读取了这个数
            emit compareColumn(j, j);        // 用天蓝色指示当前所在位置
            emit showSBMsg(2, QString("排序第%1位 访问下标%2").arg(i+1).arg(j));
            emit showSBMsg(3, QString("按位数字大小统计个数，随后放入辅助数组"));
            msleep(speed);
        }

        // 累计计数个数
        for(int j = 1; j < 10; j++)
        {
            if(stop) return;

            count[j] += count[j-1];
        }

        // 按位大小有序放到辅助数组中
        for(int j = dataNum - 1; j >= 0; j--)
        {
            if(stop) return;

            int num = (numbers[j]/power) % 10;
            temp[count[num]-1] = numbers[j];
            count[num]--;

            cmpCnt++;                       // 算访问次数，虽然没有比较，但读取了这个数
            // emit compareColumn(j, j);       // 指示当前所在位置 避免动画过于枯燥，且过程与上面的统计个数动画一样，因此上面的遍历动画同时代表上面的统计操作和此处的放进辅助数组操作。此操作不再单独显示动画
        }

        // 用位有序的辅助数组更新原数组
        for(int j = 0; j < dataNum; j++)
        {
            if(stop) return;

            numbers[j] = temp[j];

            pauseLock.lock();
            pauseLock.unlock();
            oprtCnt++;                       // 算访问次数，虽然没有比较，但读取了这个数
            emit showSBMsg(2, QString("排序第%1位 更新下标%2").arg(i+1).arg(j));
            emit showSBMsg(3, QString("用辅助数组更新原数组"));
            emit updtColumn(j, true, numbers);  // 指示当前所在位置
            msleep(speed);
        }
    }

}


// 1 快速排序
void sortAlgorithms::quickSort(int left, int right)
{
    if(stop) return;    // 用于用户在排序时点击 重新生成/导入数据 或 退出程序 后，立即停止当前排序，并根据需要开始新的排序
    if(left >= right) return;

    int i, j, base;     // 左右指针，基准
    i = left, j = right;
    base = numbers[left];     // 第一个值设为基准
    if(oneStep) {emit baseColumn(left); msleep(speed); }

    emit showSBMsg(4, QString("排序区间[%1, %2]，base：%3").arg(left).arg(right).arg(left));

    while(i < j)
    {
        if(stop) return;
        pauseLock.lock();           // 每个代码段都需要这两句保证暂停按钮/单步执行时暂停生效
        pauseLock.unlock();

        emit showSBMsg(2, QString("i = %1, j = %2 相遇后本轮结束").arg(i).arg(j));
        if(oneStep) {emit baseColumn(left); msleep(speed); resumeSorting(); }    // 防止新进入循环时基准颜色被覆盖

        while(numbers[j] >= base && i < j)  // 先j后i，保证一轮之后基准值左侧都是小于基准值的数，先i后j不能保证
        {
            j--;
            cmpCnt++;                 // 只统计元素数值比较次数，不统计指针i j自身的大小比较次数
            pauseLock.lock();
            pauseLock.unlock();
            emit showSBMsg(2, QString("i = %1, j = %2 相遇后本轮结束").arg(i).arg(j));
            emit showSBMsg(3, QString("移动 j 指针与base比较，找<base的位置"));
            if(oneStep){emit baseColumn(left); emit compareColumn(i, j); if(i != left){ emit baseColumn(left);resumeSorting();} msleep(speed);}
        }
        while(numbers[i] <= base && i < j)
        {
            i++;
            cmpCnt++;
            pauseLock.lock();
            pauseLock.unlock();
            emit showSBMsg(2, QString("i = %1, j = %2 相遇后本轮结束").arg(i).arg(j));
            emit showSBMsg(3, QString("移动 i 指针与base比较，找>base的位置"));
            if(oneStep){emit baseColumn(left); emit compareColumn(i, j); if(i != left){ emit baseColumn(left);resumeSorting();}  msleep(speed);}
        }

        if(i < j){
            swap(i, j);

            pauseLock.lock();
            pauseLock.unlock();
            qDebug() << "swap " << i << " " << j << endl;
            emit showSBMsg(2, QString("交换：%1 %2").arg(i).arg(j));
            emit showSBMsg(3, QString("交换指针，使最终base左侧小于base，右侧大于base"));
            emit swapColumn(i,j,numbers);
            emit baseColumn(left);
            resumeSorting();
            msleep(speed);
        }
    }

    numbers[left] = numbers[i];
    numbers[i] = base;
    oprtCnt++;
    emit swapColumn(left, i, numbers);    // 交换位于首位的基准值和指针相遇位置
    emit showSBMsg(2, QString("交换：%1 %2").arg(left).arg(i));
    emit showSBMsg(3, QString("交换基准值和指针相遇位置"));
    emit showSBMsg(4, QString("排序区间[%1, %2]，base：%3").arg(left).arg(right).arg(i));
    msleep(speed);

    quickSort(left, i - 1);
    quickSort(i + 1, right);

}

// 2 归并排序
void sortAlgorithms::mergeSort(int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(left, mid);          //对 a[left,mid]进行排序
        mergeSort(mid + 1, right);    //对 a[mid+1,right]进行排序
        merge(left, mid, right);       //进行合并操作
    }
}

// 归并排序_合并函数
void sortAlgorithms::merge(int left, int mid, int right)
{
    emit showSBMsg(4, QString("排序区间[%1, %2]，mid：%3").arg(left).arg(right).arg(mid));

    int* temp = new int[right - left + 1];  //用 new 申请一个辅助函数
    int i = left, j = mid + 1, k = 0;    // k为 temp 数组的下标
    while (i <= mid && j <= right)
    {
        if(stop) return;

        pauseLock.lock();
        pauseLock.unlock();
        cmpCnt++;
        emit compareColumn(i,j);
        if(oneStep) emit baseColumn(mid);   // 只有单步执行时显示mid值，否则太乱
        emit showSBMsg(2, QString("比较：i = %1, j = %2").arg(i).arg(j));
        emit showSBMsg(3, QString("较小值存入辅助数组"));
        msleep(speed);

        if (numbers[i] <= numbers[j])
        {
            temp[k++] = numbers[i++];  // 按从小到大存放在 temp 数组里面
            oprtCnt++;
        }
        else
        {
            temp[k++] = numbers[j++];
            oprtCnt++;
        }
    }
    while (i <= mid)  // j 序列结束，将剩余的 i 序列补充在 temp 数组中
    {
        if(stop) return;

        pauseLock.lock();
        pauseLock.unlock();
        if(oneStep) emit baseColumn(mid);
        emit compareColumn(i,j);    // 此处不算排序数据的比较操作，只循环下标比较。只更新当前柱子的颜色，用于指示。不统计比较次数
        emit showSBMsg(2, QString("i = %1, j = %2").arg(i).arg(j));
        emit showSBMsg(3, QString("j 序列结束，检查剩余 i 序列是否全部存入辅助数组"));
        msleep(speed);

        temp[k++] = numbers[i++];
    }
    while (j <= right)// i 序列结束，将剩余的 j 序列补充在 temp 数组中
    {
        if(stop) return;

        pauseLock.lock();
        pauseLock.unlock();
        if(oneStep) emit baseColumn(mid);
        emit compareColumn(i,j);    // 此处不算排序数据的比较操作，只循环下标比较。只更新当前柱子的颜色，用于指示。不统计比较次数
        emit showSBMsg(2, QString("i = %1, j = %2").arg(i).arg(j));
        emit showSBMsg(3, QString("i 序列结束，检查剩余 j 序列是否全部存入辅助数组"));
        msleep(speed);

        temp[k++] = numbers[j++];
    }

    k = 0;  //从下标为 0 开始传送
    for (int i = left; i <= right; i++)  //将 temp 数组 的值传递给数组 a
    {
        if(stop) return;

        pauseLock.lock();
        pauseLock.unlock();

        numbers[i] = temp[k++];
        oprtCnt++;

        emit updtColumn(i, true, numbers);
        emit showSBMsg(2, QString("更新下标 %1").arg(i));
        emit showSBMsg(3, QString("用辅助数组更新原数组"));
        msleep(speed);

    }

    delete[] temp;     // 释放辅助数组
}



// 3 堆排序
void sortAlgorithms::heapSort()
{
    //初始化，i从最后一个父节点开始调整，从下到上 0 ~ dataNum-1
    for (int i = dataNum / 2 - 1; i >= 0; i--)
    {
        if(stop) return;
        max_heapify(i, dataNum - 1);
    }

    //此时已符合大根堆结构
    //使顶堆跟最后一个元素交换，i--达到弹出的效果，即i+1到len-1的范围都已经排好序，再重新调整使符合大根堆，直到排序完毕
    for (int i = dataNum - 1; i > 0; i--)
    {
        if(stop) return;

        swap(0, i);

        oprtCnt++;
        pauseLock.lock();
        pauseLock.unlock();
        emit showSBMsg(4, QString("建堆结束"));
        emit showSBMsg(2, QString("交换：%1 %2").arg(0).arg(i));
        emit showSBMsg(3, QString("大根堆建立结束，弹出堆顶元素放到最后"));
        emit swapColumn(0, i, numbers);
        msleep(speed);
        pauseLock.lock();       //此处不加互斥量会导致状态栏标签4不能显示“建堆结束”，一闪而过显示下面函数中设置的内容
        pauseLock.unlock();
        max_heapify(0, i - 1);
    }
}

// 堆排序_构建大根堆
void sortAlgorithms::max_heapify(int start, int end)    //此函数是判断大小并执行交换
{
    int fa = start;            // 获取父节点的下标
    int son = fa * 2 + 1;      // 左节点，因为下标0开始所以需要+1

    emit showSBMsg(4, QString("建立[%1,%2]上的大根堆").arg(start).arg(end));

    while (son <= end)          // 判断若无子节点直接退出
    {
        if(stop) return;

        if (son + 1 <= end && numbers[son] < numbers[son + 1]) //先比较两个子节点大小，选择最大的
        {
            pauseLock.lock();
            pauseLock.unlock();
            cmpCnt++;
            emit compareColumn(son, son+1);
            emit showSBMsg(2, QString("比较：son1 = %1, son2 = %2").arg(son).arg(son+1));
            emit showSBMsg(3, QString("比较两个子节点大小"));
            msleep(speed);

            son++;      //指向右节点
        }

        pauseLock.lock();
        pauseLock.unlock();
        cmpCnt++;
        emit compareColumn(son, fa);   // 指示下面的比较
        emit showSBMsg(2, QString("比较：fa = %1, son = %2").arg(fa).arg(son));
        emit showSBMsg(3, QString("比较子节点和父节点，父节点大则建堆完毕"));
        msleep(speed);

        if (numbers[fa] > numbers[son]) //如果父节点大于子节点代表调整完毕，直接跳出函数
            return;
        else  //否则交换父子节点再继续比较
        {
            pauseLock.lock();
            pauseLock.unlock();

            emit showSBMsg(2, QString("交换：fa = %1, son = %2").arg(fa).arg(son));
            emit showSBMsg(3, QString("子节点更大，交换后重复比较操作"));

            swap(fa, son);
            emit swapColumn(fa, son, numbers);

            fa = son;           // 父节点指向子节点
            son = son * 2 + 1;  // 子节点指向孙节点 ，即这个点还需要跟孙节点比较

            oprtCnt++;
            emit showSBMsg(4, QString("建立[%1,%2]上的大根堆").arg(start).arg(end)); // 更新建堆信息（下一循环的过程）
            msleep(speed);
        }
    }
}


// 4 希尔排序
void sortAlgorithms::shellSort()
{

    int i, j;
    for(int gap = dataNum >> 1; gap >= 1; gap = gap >> 1)
    {
        if(stop) return;

        emit showSBMsg(4, QString("gap = %1").arg(gap));
        pauseLock.lock();
        pauseLock.unlock();
        for(i = gap; i < dataNum; i++)
        {
            if(stop) return;

            pauseLock.lock();
            pauseLock.unlock();
            cmpCnt++;
            emit showSBMsg(2, QString("比较：i = %1, j = %2").arg(i).arg(i-gap));
            emit showSBMsg(3, QString("判断当前数是否需要移动"));
            emit compareColumn(i, i-gap);
            msleep(speed);

            if (numbers[i] < numbers[i - gap])  // i小于同组前面的数，把i用冒泡交换至同组前面合适的位置
            {

                int temp = numbers[i];
                for(j = i - gap; j >= 0 && numbers[j] > temp; j = j - gap)
                {
                    if(stop) return;

                    if(j != i-gap)  // 第一次进入循环不暂停和计数，否则与上面的暂停计数重复
                    {
                        pauseLock.lock();
                        pauseLock.unlock();
                        cmpCnt++;
                        emit showSBMsg(2, QString("比较：i = %1, j = %2").arg(i).arg(j));
                        emit showSBMsg(3, QString("寻找同组中 i 可以移动的最前位置"));
                        emit compareColumn(i, j);
                        msleep(speed);
                    }
                    numbers[j + gap] = numbers[j];  // 冒泡逐个更新值

                    pauseLock.lock();
                    pauseLock.unlock();
                    oprtCnt++; 
                    emit compareColumn(j, j+gap);       //仅用于指示变量，无比较意义
                    emit showSBMsg(2, QString("比较：i = %1, j = %2").arg(i).arg(j));
                    emit showSBMsg(3, QString("寻找同组中 i 可以移动的最前位置"));
                    pauseLock.lock();
                    pauseLock.unlock();
                    emit updtColumn(j+gap, false, numbers); // 更新一个值且不覆盖上次的颜色，视觉上是同组蓝色比较后同组都是红色更新值，不会一次只显示一个
                    emit showSBMsg(2, QString("移动：%1 -> %2").arg(j).arg(j+gap));
                    emit showSBMsg(3, QString("类似冒泡，移动中间变量，给 i 让出空间"));
                    msleep(speed);
                }
                numbers[j + gap] = temp;    // 原来的i移动到合适的位置

                oprtCnt++;
                pauseLock.lock();
                pauseLock.unlock();
                emit showSBMsg(2, QString("移动：%1 -> %2").arg(i).arg(j+gap));
                emit showSBMsg(3, QString("移动 i 到同组中满足条件的最靠前位置"));
                emit compareColumn(i, j+gap);       //仅用于指示变量，无比较意义
                emit updtColumn(j+gap, true, numbers);
                msleep(speed);
            }
        }
    }
}

// 5 插入排序
void sortAlgorithms::insertSort()
{
    for(int i = 1; i < dataNum; i++)
    {
        if(stop) return;

        int key = numbers[i];
        int j = i - 1;

        pauseLock.lock();
        pauseLock.unlock();
        emit baseColumn(i);
        emit showSBMsg(2, QString("更新待插入元素 %1 -> %2 ").arg(j).arg(j+1));
        emit showSBMsg(3, QString("寻找合适位置，将待插入元素插入到有序序列中"));
        emit showSBMsg(4, QString("当前待插入：i = %1").arg(i));
        msleep(speed);

        while(j >= 0 && numbers[j] > key)
        {
            if(stop) return;

            pauseLock.lock();
            pauseLock.unlock();
            cmpCnt++;
            emit showSBMsg(2, QString("比较：j = %1, i = %2").arg(j).arg(i));
            emit compareColumn(i, j);
            emit baseColumn(i);
            msleep(speed);

            numbers[j+1] = numbers[j];

            oprtCnt++;
            emit updtColumn(j+1, true, numbers);
            emit showSBMsg(2, QString("j = %1 后移1位").arg(j));
            emit compareColumn(i, j);       // 避免颜色被覆盖，下同
            emit baseColumn(i);
            msleep(speed);
            if(oneStep) resumeSorting();    // 单步执行时此处不暂停，一个基准值作为一步，否则过程逻辑展现不清晰

            j--;
        }
        numbers[j+1] = key;

        oprtCnt++;
        emit updtColumn(j+1, true, numbers);
        emit showSBMsg(2, QString("已找到合适位置，插入 i "));
        msleep(speed);

    }
}

// 6 冒泡排序
void sortAlgorithms::bubbleSort()
{
    for (int i = 0; i < dataNum; i++)
    {
        emit showSBMsg(4, QString("第 %1 轮").arg(i+1));
        for (int j = 0; j < dataNum - 1 - i; j++)
        {
            if(stop) return;

            pauseLock.lock();
            pauseLock.unlock();

            cmpCnt++;
            if(oneStep)
            {
                pauseLock.lock();
                pauseLock.unlock();
                emit compareColumn(j, j + 1);
                emit baseColumn(j);     // 指示当前位置颜色
                msleep(speed);
            }
            emit showSBMsg(2, QString("当前下标 %1   比较%2, %3 ").arg(j).arg(j).arg(j+1));

            if (numbers[j] > numbers[j + 1])
            {
                swap(j, j + 1);

                pauseLock.lock();
                pauseLock.unlock();
                emit swapColumn(j, j + 1, numbers);
                emit showSBMsg(2, QString("交换：%1, %2 ").arg(j).arg(j+1));
                msleep(speed);
            }
        }
    }

}

// 7 选择排序
void sortAlgorithms::selectSort()
{
    for(int i = 0; i < dataNum - 1; i++)	// 控制排序的轮数，每一轮新增一个排好序的元素
    {
        if(stop) return;


        int min = numbers[i], min_flag = i;

        pauseLock.lock();
        pauseLock.unlock();
        emit showSBMsg(4, QString("第 %1 轮").arg(i+1));
        emit baseColumn(min_flag); // 指示最小值
        msleep(speed);

        for(int j = i + 1; j < dataNum; j++)	// 遍历未排好序的序列，找出最小值
        {
            if(stop) return;

            if(!oneStep)    // 此处加锁为了暂停排序功能。单步执行时找到新的最小值为一步，不需要在这停下
            {
                pauseLock.lock();
                pauseLock.unlock();
            }

            cmpCnt++;       // 下面j与最小值比较
            emit showSBMsg(2, QString("比较：j = %1, min_pos = %2 ").arg(j).arg(min_flag));
            emit showSBMsg(3, QString("查找无序序列中最小值"));
            emit compareColumn(min_flag, j);    // 指示j和当前最小值比较过程
            emit baseColumn(min_flag);          // 防止最小值颜色被覆盖
            msleep(speed);

            if(numbers[j] < min)        // 记录最小值以及下标
            {
                min = numbers[j];
                min_flag = j;

                pauseLock.lock();           // 单步执行时找到新的最小值为一步
                pauseLock.unlock();
                emit showSBMsg(2, QString("更新：min_pos = %1 ").arg(min_flag));
                emit showSBMsg(3, QString("找到更小的值，更新min_pos"));
                emit baseColumn(min_flag);  // 指示新的最小值
                msleep(speed);
            }
        }

        swap(i, min_flag);  // 交换i和最小值

        oprtCnt++;
        pauseLock.lock();
        pauseLock.unlock();
        emit showSBMsg(2, QString("交换：min_pos = %1, i = %2 ").arg(min_flag).arg(i));
        emit showSBMsg(3, QString("最小值交换到无序序列头部，有序序列长度+1"));
        emit swapColumn(i, min_flag, numbers);
        msleep(speed);
    }

}
