//C语言：冒泡排序法：将若干字符串按字母顺序(由小到大)排序输出
#include<stdio.h>
#include<string.h>

void sort(char* a[]);
void print(char* a[]);

int main()
{
    char* a[] = { "ceo","define","basic","abc","empty" };
    printf("原来的序列是：\n");
    print(a);

    sort(a);

    printf("\n排序后的序列是：\n");
    print(a);

    printf("\n");
    return 0;
}
void sort(char* a[])
{
    int i, j;
    char* temp;
    for (i = 0; i < 4; i++)//注意是i<4
    {
        for (j = 0; j < 4; j++)//注意是j<4,因为下面要+1和后面的那个字符串比较
        {
            if (strcmp(a[j], a[j + 1]) > 0)//字符串比较:>0表示前面的字符串比后面的大则交换
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void print(char* a[])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("%s ", a[i]);
    }
}