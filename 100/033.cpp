#include<stdio.h>

int fun(int n);

int main()

{
	int i, j, k, n, m;

	printf("������1000�Ļ�����:\n");

	for (i = 0; i <= 9; ++i)  /*��ٵ�һλ*/

		for (j = 0; j <= 9; ++j)  /*��ٵڶ�λ*/

			for (k = 0; k <= 9; ++k)  /*��ٵ���λ*/

			{
				n = i * 100 + j * 10 + k;  /*������ɵ�����*/

				m = k * 100 + j * 10 + i;  /*�����Ӧ�ķ�����*/

				if (i == 0 && j == 0)  /*����������ǰ��λΪ0�����*/

				{
					m = m / 100;
				}

				else if (i == 0)  /*���������ĵ�һλΪ0�����*/

				{
					m = m / 10;
				}

				if (n > 10 && n == m && fun(n))  /*������10��Ϊ���������������*/

				{
					printf("%d\t", n);
				}
			}

	printf("\n");

	return 0;
}

/*�жϲ���n�Ƿ�Ϊ����*/

int fun(int n)

{
	int i;

	for (i = 2; i < (n - 1) / 2; ++i)

	{
		if (n % i == 0)

			return 0;
	}

	return 1;
}