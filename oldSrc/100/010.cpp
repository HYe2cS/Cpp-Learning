#include<stdio.h>
void printb(int, int);
main()
{
	int x; printf("Input number:");
	scanf("%d", &x);
	printf("number of decimal form:%d\n", x);
	printf("      it's binary form:");
	printb(x, sizeof(int) * 8);  /*x:����  sizeof(int):int�����ڴ�����ռ���ֽ���
								 sizeof(int)*8:int�Ͷ�Ӧ��λ��*/
	putchar('\n');
}

void printb(int x, int n)
{
	if (n > 0)
	{
		putchar('0' + ((unsigned)(x & (1 << (n - 1))) >> (n - 1)));  /*�����nλ*/
		printb(x, n - 1);      /*����ã����x�ĺ�n-1λ*/
	}
}