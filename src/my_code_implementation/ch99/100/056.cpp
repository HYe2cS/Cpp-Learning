#include<stdio.h>

char* m[7] = { " ","U.S","U.K","FRANCE","GER","ITALI","EUSSIAN" };    /*国名
*/

main()

{
    int a[7][7], i, j, t, e, x, y;

    for (i = 0; i < 7; i++)           /*初始化条件矩阵*/

        for (j = 0; j < 7; j++)      /*行为人，列为国家，元素的值表示某人是该国
人*/

a[i][j] = j;

    for (i = 1; i < 7; i++)   /*条件矩阵每一列的第0号元素作为该列数据处理的
标记*/

a[0][i] = 1;                 /*标记该列尚未处理*/

    a[1][1] = a[2][1] = a[3][1] = a[5][1] = 0;         /*输入条件矩阵中的各种
条件*/

    a[1][3] = a[2][3] = a[3][3] = 0;             /*0表示不是该国的人*/

    a[1][4] = a[2][4] = a[3][4] = a[5][4] = a[6][4] = 0;

    a[3][5] = 0;

    a[1][6] = a[3][6] = a[5][6] = 0;

    while (a[0][1] + a[0][2] + a[0][3] + a[0][4] + a[0][5] + a[0][6] > 0)

    {                            /*当所有六列均处理完毕后退出循环*/

        for (i = 1; i < 7; i++)             /*i:列坐标*/

            if (a[0][i])              /*若该列尚未处理，则进行处理*/

            {
                for (e = 0, j = 1; j < 7; j++)     /*j:行坐标 e:该列中非0元素计
数器*/

if (a[j][i]) { x = j; y = i; e++; }

                if (e == 1)         /*若该列只有一个元素为非零，则进行消
去操作*/

                {
                    for (t = 1; t < 7; t++)

                        if (t != i)a[x][t] = 0;   /*将非零元素所在的行的其
它元素置0*/

                    a[0][y] = 0;                /*设置该列已处理完毕的
标记*/
                }
            }
    }

    for (i = 1; i < 7; i++)                          /*输出推理结果*/

    {
        printf("%c is coming from ", 'A' - 1 + i);

        for (j = 1; j < 7; j++)

            if (a[i][j] != 0)

            {
                printf("%s.\n", m[a[i][j]]);  break;
            }
    }
}