#include "helper.h"
#include "ui_helper.h"

helper::helper(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::helper)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("使用说明"));
    this->setWindowIcon(QIcon(":/icon.ico"));

    ui->instruction->setReadOnly(true);

    // 设置样式表
    QFile styleFile(":/qdarkstyle/style.qss");
    QString styleSheet;
    if (styleFile.open(QIODevice::ReadOnly))
    {

        styleSheet = QLatin1String(styleFile.readAll());
        ui->centralwidget->setStyleSheet(styleSheet);
    }
    styleFile.close();

    // 帮助内容
    QString text;

    text = "欢迎使用排序算法可视化系统！\n\n\n";


    text += "------------- 程序简介 -------------\n\n";

    text += "此程序是本人在大二下学期SWU计算机与信息科学学院《数据结构综合实践》课程中的作品。\n";
    text += "程序的设计目的是帮助正在学习排序算法的同学更好的理解排序算法的过程，同时，也可以用于掌握排序算法后的复习或加深理解。\n";
    text += "程序结合数据结构课程的教学内容，选择了目前较为常用的部分排序算法。共有8个排序算法，分别是基数排序、快速排序、归并排序、堆排序、希尔排序、插入排序、冒泡排序和选择排序。\n\n\n";


    text += "------------- 界面组成 -------------\n\n";

    text += "本程序的界面主要有五个部分组成，分别为菜单栏、排序信息展示区（下简称“信息区”）、排序过程演示区（下简称“演示区”）、排序过程控制区（下简称“控制区”）和状态栏。\n\n\n";
    text += "本程序在排序过程中不能调整窗口大小，如需调整窗口大小，请在排序开始前调整。\n";


    text += "-------------- 菜单栏 -------------\n\n";

    text += "菜单栏可用于选择排序算法以及查看说明和关于界面。\n\n\n";


    text += "-------------- 信息区 -------------\n\n";

    text += "信息区用于展示排序过程中的统计量，便于加深对不同排序算法的理解。\n";
    text += "其中，“比较次数”表示排序算法访问元素的总次数，包括比较操作和访问操作。在部分排序算法中需要用到辅助数组，在写入辅助数组时对原数组元素的访问也计入“比较次数”中。\n\n";
    text += "“操作次数”是排序算法涉及写入原数组的总操作次数，包括交换两个元素、从辅助数组中更新原数组等\n\n";
    text += "“排序用时”指从开始排序到排序完成总共消耗的时间。注意：在单步执行时，计时器不会停止。此外，计时器的计时速度不会根据“控制区”中排序速度滑块的快慢动态调整。因此，排序时间仅供参考。\n\n\n";


    text += "-------------- 演示区 -------------\n\n";

    text += "演示区用于演示排序过程，用柱状图表示排序数据。排序算法会将数据从小到大排序。程序通过排序算法传递的信号，实时改变不同“柱子“的高度，以此达到实时动态演示排序算法执行过程。\n\n";

    text += "演示区在排序过程中一共会用到4种颜色：\n";
    text += "白色表示当前步骤中没有动作的元素。\n";
    text += "天蓝色表示当前步骤中被访问的元素，如比较、访问等操作。\n";
    text += "红色表示当前步骤中参与写入操作的元素，如交换、更新等操作。\n";
    text += "浅绿色用于指示当前步骤中的基准值，或用于区分不同元素以便更加直观的看到排序过程\n\n";

    text += "在排序结束后，柱状图会从左到右依次变绿，表示排序完成，数据已有序。\n\n\n";


    text += "-------------- 控制区 -------------\n\n";

    text += "控制区左侧是“导入数据”和“生成数据”按钮。\n";
    text += "程序支持排序用户的数据文件，点击“导入数据”可以导入数据文件。读入格式为第一行一个整数n，表示数据量，后面n行每行一个数，表示待排序元素。注意：程序不会修改读入数据的大小，读入的数据大小将直接作为像素高度显示在屏幕中，请注意控制数据大小。\n";
    text += "若没有准备好的数据文件，可以用程序自带的生成数据功能。选择数据量后，程序自动随机生成排序数据。\n\n";

    text += "中部是选择排序算法下拉框和速度调节滑块。通过下拉框选择排序算法，与使用“算法”菜单栏的效果完全一致，可以根据自己的需要或喜好选择使用。下拉框在每个排序算法名称后显示了此算法的平均时间复杂度（忽略常数）和稳定性，便于比较不同算法的差异。\n";
    text += "速度调节滑块可以调整排序的演示速度。本程序支持在排序过程中随时调整演示速度。\n\n";

    text += "右侧是启停控制，共有4个按钮：开始排序、单步执行、暂停排序和继续排序。\n";
    text += "“开始排序”可以开始一个新排序，用于新添加数据后还没有排序进行时使用。\n";
    text += "“单步执行”可以令程序一步一步执行和演示排序过程，以便更加清晰的看到执行过程。开始单步排序后，点击一次本按钮，程序执行一步。每步的跨度根据不同排序的特点有所不同，如快速排序中，两个指针移动一次为一步；插入排序中，寻找合适位置，将当前元素插入到合适位置中为一步。在部分排序算法中，单步排序会使用相比普通演示模式更详细的步骤进行演示，展示出普通演示模式不会呈现在演示区的步骤。\n";
    text += "“暂停排序”可以暂停当前正在进行的排序，暂停时信息区的计时器也会停止。\n";
    text += "“继续排序”可用于暂停排序后排序的恢复，或希望从单步执行模式下进入普通演示模式。\n\n";

    text += "程序没有“停止排序”按钮。若在排序过程中希望停止当前排序，请使用左侧的“导入数据”或“生成数据”按钮。\n\n\n";


    text += "-------------- 状态栏 -------------\n\n";

    text += "状态栏用于显示排序过程中的当前操作和操作描述。在排序时，状态栏从左到右被分为4个区域，依次显示算法名称、当前操作、操作描述、关键值显示。用户可根据状态栏的信息结合演示区的动画更好的理解排序过程。\n";
    text += "此外，状态栏还用于显示欢迎语和部分按钮的功能简介。\n\n\n";

    text += "----------------------------------\n\n";

    text += "祝您使用愉快！\n";
    text += "作者：蔡前哲\n";

    ui->instruction->insertPlainText(text +='\n');
}

helper::~helper()
{
    delete ui;
}
