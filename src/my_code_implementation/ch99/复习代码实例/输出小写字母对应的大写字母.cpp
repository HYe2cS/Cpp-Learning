/*
1、编写一个程序。实现输入一个小写英文字母，程序输出它对应的大写字母。要求可以重复输入，
直到输入一个非英文字母的字符程序结束（提示：小写英文字母的ASCII码值比大些字母大32）
*/

#include <stdio.h>
int main()
{
    char ch;
    while (1)
    {
        while ((ch = getchar()) == '\n')
            printf("\n");
        if (ch >= 'a' && ch <= 'z')ch -= 32;
        if (ch >= 'A' && ch <= 'Z') printf("%c", ch);
        else break;
    }
    return 0;
}