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
    printf("�����붨�������䷶Χ���Լ�������ĸ���(���ŷָ�)��\n");
    scanf("%f,%f,%d", &a, &b, &n);
    printf("��ѡ����������㶨���ֵĺ���(1��ʾfunc_1��2��ʾfunc_2)��");
    scanf("%d", &fn);
    switch (fn)
    {
    case Func_1: v = collect(a, b, n, func_1); break;
    case Func_2: v = collect(a, b, n, func_2); break;
    default: break;
    }
    printf("------------------------------------------------------------\n");
    printf("����[%.2f, %.2f]������%d�������䣬����func_%d�Ķ�����Ϊ%.2f\n", a, b, n, fn, v);
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
