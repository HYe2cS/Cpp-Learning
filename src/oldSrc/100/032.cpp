#include<stdio.h>
int sushu(int n)
{
    int i, k;
    if (n % 2 == 0)
        return 0;
    else {
        k = int(n / 2);
        for (i = 3; i <= k; i++)
        {
            if (n % i == 0) return 0;
            else return 1;
        }
    }
}
main()
{
    int m, n, k = 0;
    int ge, shi, bai, qian;
    for (m = 1000; m < 10000; m++)
        if (sushu(m))
        {
            ge = m % 10;
            shi = m / 10 % 10;
            bai = m / 100 % 10;
            qian = m / 1000;
            n = ge * 1000 + shi * 100 + bai * 10 + qian;
            if (sushu(n))
            {
                printf("%5d ", m);
                k++;
                if (k % 10 == 0)printf("\n");
            }
        }
}