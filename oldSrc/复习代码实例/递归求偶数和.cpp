/*
3、设计一个递归调用函数，求1到n的偶数和。
*/
#include<stdio.h>
int sum(int n)
{
    if (n <= 1)return 0;
    if (n % 2 == 0)return n + sum(n - 2);
    else return n - 1 + sum(n - 3);
}

int main()
{
    int n;
    printf("input n:");
    scanf("%d", &n);
    printf("sum is %d", sum(n));
    return 0;
}