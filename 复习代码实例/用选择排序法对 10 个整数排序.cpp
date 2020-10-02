/*
用选择排序法对 10 个整数排序。 10 个整数用 scanf 函数输入。
*/
#include<stdio.h>
int main()
{
	int a[10], i, j, min, t;
	printf("input 10 numbers:\n");
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < 9; i++)
	{
		min = i;
		for (j = i + 1; j < 10; j++)
		{
			if (a[j] < a[min])min = j;
		}
		if (min != i)
		{
			t = a[i];
			a[i] = a[min];
			a[min] = t;
		}
	}
	for (i = 0; i < 10; i++)
		printf("%5d", a[i]);

	return 0;
}