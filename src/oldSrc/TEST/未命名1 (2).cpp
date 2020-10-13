#include<stdio.h>
int main()
{
    int a;
    printf("清輸入一个分数\n");
    scanf("%d", &a);
    if (a >= 0 && a <= 100)
        switch (a / 10) {
        case 10:
        case 9:
        case 8:printf("A\n");; break;
        case 7:printf("B\n"); break;
        case 6:printf("C\n"); break;
        default:printf("D\n");
        }
    else printf("error\n");

    return 0;
}