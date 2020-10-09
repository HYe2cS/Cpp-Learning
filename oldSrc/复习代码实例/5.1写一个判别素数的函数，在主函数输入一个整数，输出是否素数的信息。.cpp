/*
1.写一个判别素数的函数，在主函数输入一个整数，输出是否素数的信息。
*/
#include<stdio.h>
int isPrime(int n)
{
	int i;
	for (i = 2; i < n; i++)
		if (n % i == 0)break;
	if (i == n)return 1;
	else return 0;
}
int main()
{
	int m;
	printf("input a number:");
	scanf("%d", &m);
	isPrime(m);
	if (isPrime(m))printf("%d is a prime number", m);
	else printf("%d is not a prime number", m);
	return 0;
}