#include<stdio.h>

#include<stdlib.h>

void bhdy(int s, int b);

void prt();

int a[4], flag, count;

main()

{
    int b1, b2, i, j, k = 0, p, c;

    printf("Game guess your number in mind is # # # #.\n");

    for (i = 1; i < 10 && k < 4; i++)    /*分别显示四个1~9确定四个数字的组成*/

    {
        printf("No.%d:your number may be:%d%d%d%d\n", ++count, i, i, i, i);

        printf("How many digits have bad correctly guessed:");

        scanf("%d", &p);          /*人输入包含几位数字*/

        for (j = 0; j < p; j++)

            a[k + j] = i;          /*a[]:存放已确定数字的数组*/

        k += p;             /*k:已确定的数字个数*/
    }

    if (k < 4)           /*自动算出四位中包的个数*/

        for (j = k; j < 4; j++)

            a[j] = 0;

    i = 0;

    printf("No.%d:your number may be:%d%d%d%d\n", ++count, a[0], a[1], a[2], a[3]);

    printf("How many are in exact positions:");    /*顺序显示四位数字*/

    scanf("%d", &b1);             /*人输入有几位位置是正确的*/

    if (b1 == 4) { prt(); exit(0); }     /*四位正确，打印结果。结束游戏*/

    for (flag = 1, j = 0; j < 3 && flag; j++)   /*实现四个数字的两两(a[j],a[k]交换*/

        for (k = j + 1; k < 4 && flag; k++)

            if (a[j] != a[k])

            {
                c = a[j]; a[j] = a[k]; a[k] = c;      /*交换a[j],a[k]*/

                printf("No.%d:Your number may be: %d%d%d%d\n", ++count, a[0], a[1], a[2], a[3]);

                printf("How many are in exact positins:");

                scanf("%d", &b2);          /*输入有几个位置正确*/

                if (b2 == 4) { prt(); flag = 0; }    /*若全部正确，结束游戏*/

                else if (b2 - b1 == 2)bhdy(j, k);  /*若上次与本次的差为2，则交换两
    个元素即可结束*/

                else if (b2 - b1 == -2)   /*若上次与本次的差为-2，则说明已交换的(
    a[j],a[k])是错误的

                                       将(a[j],a[k]还原后，只要交换另外两个元
    素即可结束游戏*/

                {
                    c = a[j]; a[j] = a[k]; a[k] = c;

                    bhdy(j, k);
                }

                else if (b2 <= b1)

                {
                    c = a[j]; a[j] = a[k]; a[k] = c;     /*恢复交换的两个数字*/
                }

                else b1 = b2;    /*其它情况则将新输入的位置信息作为上次的位置保
    存*/
            }

    if (flag) printf("You input error!\n");  /*交换结果仍没结果，只能是
人输入的信息错误*/
}

void prt()         /*打印结果，结束游戏*/

{
    printf("Now your number must be %d%d%d%d.\n", a[0], a[1], a[2], a[3]);

    printf("Game Over\n");
}

void bhdy(int s, int b)

{
    int i, c = 0, d[2];

    for (i = 0; i < 4; i++)             /*查找s和b以外的两个元素下标*/

        if (i != s && i != b) d[c++] = i;

    i = a[d[1]]; a[d[1]] = a[d[0]];  a[d[0]] = i;  /*交换除a[s]和a[b]以外的两个元素*/

    prt();        /*打印结果，结束游戏*/

    flag = 0;
}