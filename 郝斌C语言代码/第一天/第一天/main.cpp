#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main(int argc, char** argv)
{
    int x, y, z;
    x = y = 1;
    z = x++, ++y, y++;
    printf("%d,%d,%d\n", x, y, z);
}