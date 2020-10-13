/*
2.求两个整数的最大公约数和最小公倍数。用fmax函数求最大公约数，用fmin函数根据求出最小公倍数。
两个整数在主函数中输人，并传送给fmax ，求出的最大公约数返回主函数，然后再与两个整数一起作为实参传递给fmin ，以求出最小公倍数，再返回到主函数输出最大公约数和最小公倍数。
*/
#include<stdio.h>
int fmax(int m, int n)
{
    int r;
    do
    {
        r = m % n;
        m = n;
        n = r;
    } while (r);
    return m;
}
int fmin(int a, int b, int c)
{
    return a * b / c;
}
int main()
{
    int x, y, z;
    printf("input two number:");
    scanf("%d %d", &x, &y);
    z = fmax(x, y);
    printf("zdgys is %d\n", z);
    printf("zxgbs is %d\n", fmin(x, y, z));
    return 0;
}