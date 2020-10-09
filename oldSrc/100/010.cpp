#include<stdio.h>
void printb(int, int);
main()
{
	int x; printf("Input number:");
	scanf("%d", &x);
	printf("number of decimal form:%d\n", x);
	printf("      it's binary form:");
	printb(x, sizeof(int) * 8);  /*x:整数  sizeof(int):int型在内存中所占的字节数
								 sizeof(int)*8:int型对应的位数*/
	putchar('\n');
}

void printb(int x, int n)
{
	if (n > 0)
	{
		putchar('0' + ((unsigned)(x & (1 << (n - 1))) >> (n - 1)));  /*输出第n位*/
		printb(x, n - 1);      /*归调用，输出x的后n-1位*/
	}
}