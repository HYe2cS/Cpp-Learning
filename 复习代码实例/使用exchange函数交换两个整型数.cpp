//2. (1)编写一个函数change( )实现两个整型变量的值交换；
//(2)写出主函数，从键盘上输入两个数，然后调用函数change()交换两个整型数的值并输出。（10分）
#include<stdio.h>
void change(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	change(&a, &b);
	printf("%d,%d\n", a, b);
	return 0;
}