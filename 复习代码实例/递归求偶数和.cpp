/*
3�����һ���ݹ���ú�������1��n��ż���͡�
*/
#include<stdio.h>
int sum(int n)
{
	if (n <= 1)return 0;
	if (n % 2 == 0)return n + sum(n - 2);
	else return n - 1 + sum(n - 3);
}

int main()
{
	int n;
	printf("input n:");
	scanf("%d", &n);
	printf("sum is %d", sum(n));
	return 0;
}