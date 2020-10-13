#include<stdio.h>

main()

{
    int a, b, c, d;

    printf("Please enter a number:");

    scanf("%d", &a);           /*输入整数*/

    b = a * a * a;                  /*求整数的三次方*/

    printf("%d*%d*%d=%d=", a, a, a, b);

    for (d = 0, c = 0; c < a; c++)       /*输出数列，首项为a*a-a+1,等差值为2*/

    {
        d += a * a - a + 1 + c * 2;       /*求数列的前a项的和*/

        printf(c ? "+%d" : "%d", a * a - a + 1 + c * 2);
    }

    if (d == b)printf(" Y\n");    /*若条件满足则输出"Y"*/

    else printf(" N\n");       /*否则输出"N"*/
}