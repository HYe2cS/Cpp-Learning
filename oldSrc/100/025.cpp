#include<stdio.h>
main()
{
    int a, i, m;
    printf("There are following perfect numbers smaller than 1000:\n");
    for (a = 1; a < 1000; a++)      /*循环控制选取1~1000中的各数进行判断*/
    {
        for (m = 0, i = 1; i <= a / 2; i++)   /*计算a的因子，并将各因子之和m=a，则a是
完全数输出*/
if (!(a % i))m += i;
        if (m == a)
            printf("%4d    ", a);
    }
    printf("\n");
}