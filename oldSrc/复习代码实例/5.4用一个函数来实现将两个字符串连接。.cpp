/*
4.用一个函数来实现将两个字符串连接。
*/
#include<stdio.h>
void join(char a[], char b[])
{
	int i = 0, j = 0;
	while (a[i] != '\0')i++;
	while (b[j] != '\0')
	{
		a[i] = b[j]; j++; i++;
	}
	a[i] = 0;
}

int main()
{
	char a[80], b[80];
	gets(a);
	gets(b);
	join(a, b);
	puts(a);
	return 0;
}