#include<stdio.h>
int main()
{
	int i, x, y, last = 1;    /*����last������X��Y�η������еĲ��ֳ˻��ĺ���λ*/
	printf("Input X and Y(X**Y):");
	scanf("%d**%d", &x, &y);
	for (i = 1; i <= y; i++)                /*X�Գ�Y��*/
		last = last * x % 1000;     /*��last��X���1000ȡģ��������ĺ���λ*/
	printf("The last 3 digits of %d**%d is:%d\n", x, y, last % 1000); /*��ӡ���*/
}