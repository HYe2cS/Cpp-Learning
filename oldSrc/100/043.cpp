#include<stdio.h>

int zxgb(int a, int b);

main()

{
	int i, j, k, l, m, n;

	printf("Input two FENSHU:\n");

	scanf("%d/%d,%d/%d", &i, &j, &k, &l);       /*������������*/

	m = zxgb(j, l) / j * i;                  /*�����һ������ͨ�ֺ�ķ���*/

	n = zxgb(j, l) / l * k;                  /*����ڶ�������ͨ�ֺ�ķ���*/

	if (m > n)   printf("%d/%d>%d/%d\n", i, j, k, l);    /*�ȽϷ��ӵĴ�С*/

	else if (m == n)   printf("%d/%d=%d/%d\n", i, j, k, l);    /*����ȽϵĽ��
*/

	else        printf("%d/%d<%d/%d\n", i, j, k, l);
}

int zxgb(int a, int b)

{
	long int c;

	int d;

	if (a < b) c = a, a = b, b = c;     /*��a<b,�򽻻���������ֵ*/

	for (c = a * b; b != 0;)

	{
		d = b;  b = a % b;  a = d;
	}

	return (int)c / a;
}