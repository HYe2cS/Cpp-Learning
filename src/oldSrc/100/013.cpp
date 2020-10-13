#include<stdio.h>
main()
{
    int i;
    float total = 0;
    for (i = 0; i < 5; i++)                     /*i 为年数，取值为0~4年*/
        total = (total + 1000) / (1 + 0.0063 * 12);  /*累计算出年初存款数额，第五次的计
算
                                             结果即为题解*/
    printf("He must save %.2f at first.\n", total);
}