#include<stdio.h>

#define MAX 2147483647

long re(long int);

int nonres(long int s);

main()

{
    long int n, m;

    int count = 0;

    printf("Please enetr a number optionaly:");

    scanf("%ld", &n);

    printf("The generation process of palindrome:\n");

    while (!nonres((m = re(n)) + n))     /*判断整数与其反序数相加后是否为回文
数*/

    {
        if (m + n >= MAX)

        {
            printf(" input error,break.\n");

            break;
        }

        else

        {
            printf("[%d]:%ld+%ld=%ld\n", ++count, n, m, m + n);

            n += m;
        }
    }

    printf("[%d]:%ld+%ld=%ld\n", ++count, n, m, m + n);     /*输出最后得到的回
文数*/

    printf("Here we reached the aim at last!\n");
}

long re(long int a)     /*求输入整数的反序数*/

{
    long int t;

    for (t = 0; a > 0; a /= 10)    /*将整数反序*/

        t = t * 10 + a % 10;

    return t;
}

int nonres(long int s)   /*判断给定的整数是否是回文数*/

{
    if (re(s) == s) return 1;       /*若是回文数则返回１*/

    else return 0;               /*否则返回　０*/
}