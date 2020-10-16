#include<stdio.h>

#define NUM 7       /*定义要处理的人数*/

int a[NUM + 1] = { 0,5,3,4,7,3,5,6 };       /*为简单直接定义选手的分数*/

int m[NUM + 1], l[NUM + 1];    /*m:已编名次的标记数组   l:记录同名次元素的下标*/

main()

{
    int i, smallest, num, k, j;

    num = 1;                       /*名次*/

    for (i = 1; i <= NUM; i++)       /*控制扫描整个数组，每次处理一个名次*/

        if (m[i] == 0)     /*若尚未进行名次处理(即找到第一个尚未处理的元素)*/

        {
            smallest = a[i];     /*取第一个未处理的元素作为当前的最小值*/

            k = 1;            /*数组l的下标，同名次的人数*/

            l[k] = i;        /*记录分值为smallest的同名次元素的下标*/

            for (j = i + 1; j <= NUM; j++)   /*从下一个元素开始对余下的元素进行处*/

                if (m[j] == 0)            /*若为尚未进行处理的元素*/

                    if (a[j] < smallest)    /*分数小于当前最小值*/

                    {
                        smallest = a[j];    /*则重新设置当覵最小值*/

                        k = 0;              /*重新设置同名次人数*/

                        l[++k] = j;         /*重新记录同名次元素下标*/
                    }

                    else if (a[j] == smallest)     /*若与当前最低分相同*/

                        l[++k] = j;               /*记录同名次的元素下标*/

            for (j = 1; j <= k; j++)       /*对同名次的元素进行名次处理*/

                m[l[j]] = num;

            num++;                  /*名次加1*/

            i = 0;          /*控制重新开始，找下一个没排名次的元素*/
        }

    printf("Player-No score Rank\n");

    for (j = 1; j <= NUM; j++)                 /*控制输出*/

        printf(" %3d      %4d      %4d\n", j, a[j], m[j]);
}