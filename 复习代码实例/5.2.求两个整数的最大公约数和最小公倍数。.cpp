/*
2.���������������Լ������С����������fmax���������Լ������fmin�������������С��������
���������������������ˣ������͸�fmax ����������Լ��������������Ȼ��������������һ����Ϊʵ�δ��ݸ�fmin ���������С���������ٷ��ص�������������Լ������С��������
*/
#include<stdio.h>
int fmax(int m, int n)
{
	int r;
	do
	{
		r = m % n;
		m = n;
		n = r;
	} while (r);
	return m;
}
int fmin(int a, int b, int c)
{
	return a * b / c;
}
int main()
{
	int x, y, z;
	printf("input two number:");
	scanf("%d %d", &x, &y);
	z = fmax(x, y);
	printf("zdgys is %d\n", z);
	printf("zxgbs is %d\n", fmin(x, y, z));
	return 0;
}