#include<stdio.h>

int ok(int t, int* z);

int a[9];

main()

{
    int m, count = 0;

    for (m = 123; m <= 333; m++)           /*试探可能的三位数*/

        if (ok(m, a) && ok(2 * m, a + 3) && ok(3 * m, a + 6))      /*若满足题意*/

            printf("No.%d:  %d %d %d\n", ++count, m, 2 * m, 3 * m);    /*输出结果
*/
}

int ok(int t, int* z)     /*分解t的值，将其存入z指向的三个数组元素，若满足
要求返回1*/

{
    int* p1, * p2;

    for (p1 = z; p1 < z + 3; p1++)

    {
        *p1 = t % 10;               /*分解整数*/

        t /= 10;

        for (p2 = a; p2 < p1; p2++)     /*查询分解出的数字是否已经出现过*/

            if (*p1 == 0 || *p2 == *p1)return 0;    /*若重复则返回*/
    }

    return 1;                /*否则返回1*/
}