//3.从键盘输入5位员工信息（工号、姓名、年薪），输出年薪最高的员工信息，同时保存到文件max.txt中（要求用结构体）。（14分）
#include<stdio.h>
struct student {
    int num;
    char name[10];
    int money;
};
int cmp(student* s, int n)
{
    int maxindex = 0, i;
    for (i = 0; i < n; i++)
    {
        if (s[i].money > s[maxindex].money)maxindex = i;
    }
    return maxindex;
}

int main()
{
    FILE* fp;
    student a[5];
    fp = fopen("max.txt", "w+");
    int i, max;
    for (i = 0; i < 5; i++)
    {
        scanf("%d%s%d", &a[i].num, &a[i].name, &a[i].money);
    }
    max = cmp(a, 5);
    fprintf(fp, "%d%s%d", a[max].num, a[max].name, a[max].money);
    return 0;
}