#include<stdio.h>

int remainder[101], quotient[101];    /*remainder:��ų����������� quotie
nt:���δ���̵�ÿһλ*/

main()

{
	int m, n, i, j;

	printf("Please input a fraction(m/n)(<0<m<n<=100):");

	scanf("%d/%d", &m, &n);      /*���뱻�����ͳ���*/

	printf("%d/%d it's accuracy value is:0.", m, n);

	for (i = 1; i <= 100; i++)             /*i: �̵�λ��*/

	{
		remainder[m] = i;       /*m:�������� remainder[m]:��������Ӧ���̵�
λ��*/

		m *= 10;                /*��������10λ*/

		quotient[i] = m / n;      /*��*/

		m = m % n;                /*������*/

		if (m == 0)              /*����Ϊ0 ���ʾ������С��*/

		{
			for (j = 1; j <= 1; j++) printf("%d", quotient[j]);    /*�����*/

			break;             /*�˳�ѭ��*/
		}

		if (remainder[m] != 0)     /*����������Ӧ��λ��ǰ���Ѿ����ֹ�*/

		{
			for (j = 1; j <= i; j++) printf("%d", quotient[j]);   /*�����ѭ��С
��*/

			printf("\n\tand it is a infinite cyclic fraction from %d\n",
				remainder[m]);

			printf("\tdigit to %d digit after decimal point.\n", i);

			/*���ѭ���ڵ�λ��*/

			break;                /*�˳�*/
		}
	}
}