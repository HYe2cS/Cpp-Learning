#include<stdio.h>

int zxgb(int a, int b);

main()

{
    int i, j, k, l, m, n;

    printf("Input two FENSHU:\n");

    scanf("%d/%d,%d/%d", &i, &j, &k, &l);       /*输入两个分数*/

    m = zxgb(j, l) / j * i;                  /*求出第一个分数通分后的分子*/

    n = zxgb(j, l) / l * k;                  /*求出第二个分数通分后的分子*/

    if (m > n)   printf("%d/%d>%d/%d\n", i, j, k, l);    /*比较分子的大小*/

    else if (m == n)   printf("%d/%d=%d/%d\n", i, j, k, l);    /*输出比较的结果
*/

    else        printf("%d/%d<%d/%d\n", i, j, k, l);
}

int zxgb(int a, int b)

{
    long int c;

    int d;

    if (a < b) c = a, a = b, b = c;     /*若a<b,则交换两变量的值*/

    for (c = a * b; b != 0;)

    {
        d = b;  b = a % b;  a = d;
    }

    return (int)c / a;
}