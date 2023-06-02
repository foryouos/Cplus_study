#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int leap_year(int y, int i)//如果是闰年，返回1，如果是平年返回0
{
    if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))//能够被400整除是世纪闰年，能被4整除，而不是100的倍数是普通闰年
    {
        i = 1;
    }
    return i;
}
void month_english(int M)     //成像，月份数字转英文函数，输入月份，输出英文
{
    switch (M)
    {
    case 1:printf("%s", "Jan"); break;
    case 2:printf("%s", "Feb"); break;
    case 3:printf("%s", "Mar"); break;
    case 4:printf("%s", "Apr"); break;
    case 5:printf("%s", "May"); break;
    case 6:printf("%s", "Jun"); break;
    case 7:printf("%s", "Jul"); break;
    case 8:printf("%s", "Aug"); break;
    case 9:printf("%s", "Sep"); break;
    case 10:printf("%s", "Oct"); break;
    case 11:printf("%s", "Nov"); break;
    case 12:printf("%s", "Dec"); break;

    }
}
int month_one_w(int d, int y, int m, int w)//判断该月份每一号的星期//学到一个基姆拉尔森公式/d为几号
{
    if (m == 01 || m == 02)//如果是一月或者是2月，算成上一年的13月或14月
    {
        m += 12;
        y--;
    }
    w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;//如果w=0代表星期天，
    return w;
}
void Appear_number(int y, int m, int w, int md)//产生为月份和年份，铭记形参也要定义类型，呈现数字类型
{
    int i = 1;
    for (i = 1; i <= md; i++)
    {
        w = month_one_w(i, y, m, w);//判断该月份每一天的星期，以便于进行空格与星期相互照应，
        if (i == 1 && w != 0)
        {
            switch (w)
            {
            case 1:printf(" "); break;
            case 2:printf("        "); break;
            case 3:printf("               "); break;
            case 4:printf("                      "); break;
            case 5:printf("                             "); break;
            case 6:printf("                                    "); break;
            }
        }

        switch (w)//根据星期对数据进行空格，实现对应
        {
        case 0:printf("%d", i); break;//星期天的结果为0
        case 1:if (i == 10)
        {           //当等于10号的时候，由于前面的单数日期，会出现空格误差，进行调整
            printf("%8d", i);
            break;
        }
              else
        {
            printf("%7d", i); break;
        }
        case 2:if (i == 10)
        {
            printf("%8d", i);
            break;
        }
              else
        {
            printf("%7d", i); break;
        }
        case 3:if (i == 10)
        {
            printf("%8d", i);
            break;
        }
              else
        {
            printf("%7d", i); break;
        }
        case 4:if (i == 10)
        {
            printf("%8d", i);
            break;
        }
              else
        {
            printf("%7d", i); break;
        }
        case 5:if (i == 10)
        {
            printf("%8d", i);
            break;
        }
              else
        {
            printf("%7d", i); break;
        }
        case 6:if (i == 10)
        {
            printf("%8d\n", i);
            break;
        }
              else
        {
            printf("%7d\n", i); break;
        }
        }

    }
    printf("\n");

}
void around_message(int M, int Y)
{
    printf("\n");
    printf("\t%d年第%d月的日历\n", Y, M);
    month_english(M); //引用输出数字转英文函数
    printf("%42d\n", Y);// 输出对应的年份
    printf("%s    %s    %s    %s    %s    %s    %s\n", "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT");//呈现星期一行，星期之间间隔3个字符
}
int main()
{
    int Y, YD, M, MD, judje_year, W; //Y是年，YD是年总共的天数，M月份，MD月的天数，judje_year判断闰年平年的变量值，W星期
    judje_year = 0;
    W = 0;
    int i;
    YD = 365;
    //在进行一次输入判断是输入年或者是具体月份，使用if语句进行分开
    printf("日历查询请输入相关查询信息（本程序支持1921年至9999年的所有日历\n");
loop:
    printf("请输入你要查询的年份\n");
    scanf("%4d", &Y);
    //对数据正确性进行检查
    if (Y >= 9999)
    {
        printf("您输入的数字太大了，请重新修改\n");
        goto loop;
    }
    else if (Y <= 1912)
    {
        printf("恕小弟无能，民国以前仍未实行公历，请重新输入\n");
        goto loop;
    }
    printf("请输入你要查询的月份，若查询整年日历，输入0\n");
    scanf("%d", &M);
    if (M > 12)
    {
        printf("输入错误哦，一年只有12个月,请重新输入\n");
        goto loop;
    }
    else if (M < 0)
    {
        printf("月份没有负数哦，请重新输入\n");
        goto loop;
    }
    //建立每个月的日期一维数组
    int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    //判断是闰年还是平年
    if (leap_year(Y, judje_year) == 1)  //闰年1二月份29天，平年0二月份28天
    {
        month[1] = 29;
        YD = 366;
    }
    printf("\t%s\n\n", "您查询的日历如下");


    if (M == 0)//如果月份为零代表输出整年的日历
    {
        for (i = 0; i < 12; i++)// 循环每一月的天数
        {
            around_message(i + 1, Y);//外框相关的数据信息，整理成函数
            Appear_number(Y, i + 1, W, month[i]); //具体的某一月日历数字呈现函数
        }
    }
    else if (M != 0)
    {
        around_message(M, Y);//外框相关的数据信息，整理成函数
        Appear_number(Y, M, W, month[M - 1]);
    }

}