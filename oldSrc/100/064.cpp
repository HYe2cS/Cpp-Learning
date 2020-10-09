#include<stdio.h>

void print(long a, long b, long s1, long s2, long s3);

int jud(long q, char* pflag);

main()

{
    long i, j, k, l, m, n, term, t1, t2, t3;

    int flag;

    for (i = 0; i <= 4; ++i)           /*被乘数的第一位*/

        for (j = 5; j <= 9; ++j)        /*被乘数的第二位*/

            for (k = 0; k <= 4; ++k)     /*被乘数的第三位*/

            {
                term = 100 * i + 10 * j + k;   /*被乘数*/

                for (flag = 0, n = 0; n < 4 && !flag;)       /*乘数的第一位*/

                    flag = jud((t3 = ++n * 100 * term) / 100, "001"); /*判断第三个部分积
     */

                if (flag)

                {
                    for (flag = 0, m = 0; m < 4 && !flag;)     /*乘数的第二位*/

                        flag = jud((t2 = ++m * 10 * term) / 10, "1100");  /*判断第二个部分
      积*/

                    if (flag)

                    {
                        for (flag = 0, l = 5; l < 9 && !flag;)         /*乘数的第三位*/

                            flag = jud(t1 = ++l * term, "0000");    /*判断第一个部分积
       */

                        if (flag && jud(t1 + t2 + t3, "00101"))     /*判断乘式的积*/

                            print(term, n * 100 + m * 10 + l, t1, t2, t3);
                    }
                }
            }
}

void print(long a, long b, long s1, long s2, long s3)      /*打印结果*/

{
    printf("\n      %ld\n", a);

    printf("*)  %ld\n", b);

    printf("......................\n");

    printf("   %ld\n   %ld\n   %ld\n", s1, s2 / 10, s3 / 100);

    printf("......................\n");

    printf(" %ld\n", a * b);
}

int jud(long q, char* pflag)    /*判断一个数的每一位是否满足要求的判断函数
*/

/*q:需要判断的数。pflag:标志字符串，A用1表示，Z用0表示。标志串排
列顺序：个十百...*/

{
    while (q != 0 && *pflag != NULL)    /*循环判断对应位的取值范围是否正确*/

        if (*pflag - '0' != (q % 10 >= 5 ? 1 : 0))   /*标志位与对应的位不符，返回0*/

            return 0;

        else

        {
            q /= 10; ++pflag;         /*若相符则取下一位进行判断*/
        }

    if (q == 0 && *pflag == NULL)    /*q的位数与标志字符串的长度相同时，返回1*/

        return 1;

    else return 0;
}