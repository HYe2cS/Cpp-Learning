/*
3������xnֵ��Ҫ�����һ����������������x ��n ��ֵ����ӡ��������һ��power(x,n)������xn��ֵ��power(x,n)������ʹ�õݹ���÷�����
*/
#include<stdio.h>
float power(float x, int n)
{
	if (n == 1)return x;
	else return x * power(x, n - 1);
}

int main()
{
	float x, p;
	int n;
	printf("input x and n:");
	scanf("%f %d", &x, &n);
	p = power(x, n);
	printf("%.2f (%d)=%.2f\n", x, n, p);
	return 0;
}