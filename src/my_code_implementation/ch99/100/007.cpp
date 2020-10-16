#include<stdio.h>
main()
{
    int a, count = 0;
    {
        for (a = 5; a <= 100; a += 5)
            count++;
        if (!(a % 25))count++;
    }
    printf("The number of 0 in the end of 100! is：%d.\n", count);
}