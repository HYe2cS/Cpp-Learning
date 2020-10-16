#include<stdio.h>

#include<math.h>

main()

{
    int d[6], m, i, j;

    long b[63], flag;

    float c[6], min, x;

    printf("Please enter the prices of 6 books:");

    for (i = 0; i < 6; i++)  scanf("%f", &c[i]);    /*输入六个浮点数*/

    for (i = 0, min = -1, d[0] = 0; d[0] < 2; d[0]++)    /*建立六个数的全部组合并处理*
 /

       for(d[1]=0;d[1]<2;d[1]++)           /*i:差值具有min组合的数量*/

        for (d[2] = 0; d[2] < 2; d[2]++)        /*min:与10的最小差值*/

            for (d[3] = 0; d[3] < 2; d[3]++)     /*d[]:组合时是否取该数的标志*/

                for (d[4] = 0; d[4] < 2; d[4]++)

                    for (d[5] = 0; d[5] < 2; d[5]++)

                    {
                        for (flag = 0, x = 0, j = 5; j >= 0; j--)

                            /*flag:将六个数的组合用对应的一个十进制位表示  x
    :对应六个数组合的和*/

                        {
                            x += c[j] * d[j];  flag = flag * 10 + d[j];
                        }

                        x = ((x - 10 > 0) ? x - 10 : 10 - x);     /*x: 组合的和与10的差
  */

                        if (min < 0)

                        {
                            min = x;         /*对第一次计算出的差min进行处理*
   /

                            b[i++]=flag;   /*b[]:有相同的min的flag的数组  i
   :b[]数组的下标*/
                        }

                        else if (min - x > 1.e-6)        /*对新的min的处理*/

                        {
                            min = x; b[0] = flag; i = 1;
                        }

                        else if (fabs((double)x - min) < 1.e-6)

                            b[i++] = flag;         /*对相等min的处理*/
                    }

    for (m = 0; m < i; m++)     /*输出全部i个与10的差值均为min的组合*/

    {
        printf("10(+ -)%.2f=", min);

        for (flag = b[m], j = 0; flag > 0; j++, flag /= 10)

            if (flag % 10)       /*将b[]中存的标记flag还原为各个数的组
合*/

if (flag > 1) printf("%.2f+", c[j]);

else printf("%.2f\n", c[j]);
    }
}