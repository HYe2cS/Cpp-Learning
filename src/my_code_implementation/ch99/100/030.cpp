#include<stdio.h>

main()

{
    int n1, nm, i, j, flag, count = 0;

    do {
        printf("Input START and END=?");

        scanf("%d%d", &n1, &nm);           /*输入求素数的范围*/
    } while (!(n1 > 0 && n1 < nm));               /*输入正确的范围*/

    printf("...........PRIME TABLE(%d--%d)............\n", n1, nm);

    if (n1 == 1 || n1 == 2)                  /*处理素数2*/

    {
        printf("%4d", 2);

        n1 = 3; count++;
    }

    for (i = n1; i <= nm; i++)              /*判定指定范围内的整数是否为素数*/

    {
        if (!(i % 2))continue;

        for (flag = 1, j = 3; flag && j < i / 2; j += 2)

            /*判定能否被从3到整数的一半中的某一数
所整除*/

if (!(i % j))flag = 0;       /*若能整除则不是素数*/

        if (flag) printf(++count % 15 ? "%4d" : "%4d\n", i);
    }
}