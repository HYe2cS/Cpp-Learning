#include<stdio.h>

#include<stdlib.h>
main()

{
    int number, i, j, k, l;

    printf("Please enter a number=");

    scanf("%d", &number);                /*输入整数*/

    for (i = 1; i < number / 2; i++)         /*试探法。试探i,j,k,k的不同值*/

        for (j = 0; j <= i; j++)

            for (k = 0; k <= j; k++)

                for (l = 0; l <= k; l++)

                    if (number == i * i + j * j + k * k + l * l)    /*若满足定理要求则输出
结果*/

                    {
                        printf(" %d=%d*%d+%d*%d+%d*%d+%d*%d\n", number, i,
                            i, j, j, k, k, l, l);

                        exit(0);
                    }
}