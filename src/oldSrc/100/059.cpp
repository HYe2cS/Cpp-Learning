#include<stdio.h>

int jud1(int s[]);

void print(int u[]);

int count;                /*计数器*/

main()

{
    static int a[] = { 1,2,3,4,5,6 };    /*初始化数组*/

    printf("The possble table satisfied above conditions are:\n");

    for (a[1] = a[0] + 1; a[1] <= 5; ++a[1])          /*a[1]必须大于a[0]*/

        for (a[2] = a[1] + 1; a[2] <= 5; ++a[2])      /*a[2]必须大于a[1]*/

            for (a[3] = a[0] + 1; a[3] <= 5; ++a[3])   /*第二行的a[3]必须大于a[0]
*/

for (a[4] = a[1] > a[3] ? a[1] + 1 : a[3] + 1; a[4] <= 5; ++a[4])

/*第二行的a[4]必须大于左侧
a[3]和上边a[1]*/

if (jud1(a)) print(a);       /*如果满足题意，打印结果
*/
}

int jud1(int s[])

{
    int i, l;

    for (l = 1; l < 4; l++)

        for (i = l + 1; i < 5; ++i)

            if (s[l] == s[i])  return 0;    /*若数组中的数字有重复的，返回0
*/

    return 1;                            /*若数组中的数字没有重复的，返回
1*/
}

void print(int u[])

{
    int k;

    printf("\nNo.:%d", ++count);

    for (k = 0; k < 6; k++)

        if (k % 3 == 0)           /*输出数组的前三个元素作为第一行*/

            printf("\n%d", u[k]);

        else                 /*输出数组的后三个元素作为第二行*/

            printf("%d", u[k]);
}