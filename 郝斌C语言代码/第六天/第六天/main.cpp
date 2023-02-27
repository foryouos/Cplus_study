#include <stdio.h>
#include <math.h>

enum func_name { Func_1 = 1, Func_2 };
enum func_name fn;

float collect(float s, float t, int m, float (*p)(float x));
float func_1(float x);
float func_2(float x);

int main(int argc, char** argv)
{
    int n;
    float a, b, v = 0.0;
    printf("请输入定积分区间范围，以及子区间的个数(逗号分隔)：\n");
    scanf("%f,%f,%d", &a, &b, &n);
    printf("请选择函数你想计算定积分的函数(1表示func_1，2表示func_2)：");
    scanf("%d", &fn);
    switch (fn)
    {
    case Func_1: v = collect(a, b, n, func_1); break;
    case Func_2: v = collect(a, b, n, func_2); break;
    default: break;
    }
    printf("------------------------------------------------------------\n");
    printf("区间[%.2f, %.2f]，划分%d个子区间，函数func_%d的定积分为%.2f\n", a, b, n, fn, v);
    return 0;
}

float collect(float s, float t, int n, float (*p)(float x))
{
    int i;
    float f, h, x, y1, y2, area;
    f = 0.0;
    h = (t - s) / n;
    x = s;
    y1 = (*p)(x);
    for (i = 1; i <= n; ++i)
    {
        x = x + h;
        y2 = (*p)(x);
        area = (y1 + y2) * h / 2;
        y1 = y2;
        f += area;
    }
    return (f);
}

float func_1(float x)
{
    float fx;
    fx = exp(-x);
    return (fx);
}

float func_2(float x)
{
    float fx;
    fx = x * sqrt(1 + cos(2 * x));
    return (fx);
}
