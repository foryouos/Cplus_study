#include <stdio.h>
#include <math.h>
int main(int argc, char** argv)
{
    float  i = 6.7;

    double ip;
    //printf("%d\n", abs(j));
    printf("%f\n",modf(i, &ip));
    
    printf("%f\n", ip);
    return 0;
}