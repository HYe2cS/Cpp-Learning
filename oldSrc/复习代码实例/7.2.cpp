/*
2�� �����ʾstu.txt�ļ������ݡ�
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE* fp;
	char c;
	if ((fp = fopen("d:\\stu.txt", "r")) == NULL)
	{
		printf("cannot open flie");
		exit(0);
	}
	while (!feof(fp))
	{
		c = fgetc(fp);
		putchar(c);
	}
	fclose(fp);
	return 0;
}