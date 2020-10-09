#include<stdio.h>
int main()
{
	int a[10];
	int i, j, t;
	printf("input 10 number:\n");
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	printf("\n");
	n = 10;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - 1 - i; j++)
			if (a[j] > a[j + 1])
			{
				t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
			}
	printf("the sorted numbers:\n");
	for (i = 0; i < 10; i++)
		printf("%d", a[i]);
	printf("\n");
	return 0;
}