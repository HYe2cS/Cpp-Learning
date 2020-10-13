/*
3、计算xn值。要求设计一个主函数，以输入x 和n 的值并打印结果；设计一个power(x,n)函数求xn的值，power(x,n)函数中使用递归调用方法。
*/
#include<stdio.h>
float power(float x, int n)
{
    if (n == 1)return x;
    else return x * power(x, n - 1);
}

int main()
{
    float x, p;
    int n;
    printf("input x and n:");
    scanf("%f %d", &x, &n);
    p = power(x, n);
    printf("%.2f (%d)=%.2f\n", x, n, p);
    return 0;
}