#include<stdio.h>

#define N 6                /*ȷ��Nֵ*/

main()

{
	int i, j, k, t;

	printf("The possble Latin Squares of order %d are:\n", N);

	for (j = 0; j < N; j++)                /*����N����ͬ����������*/

	{
		for (i = 0; i < N; i++)

		{
			t = (i + j) % N;        /*ȷ�������������i �еĵ�һ��Ԫ�ص�ֵ*/

			for (k = 0; k < N; k++)  /*���ջ�����ʽ��������еĸ���Ԫ��*/

				printf("%d", (k + t) % N + 1);

			printf("\n");
		}

		printf("\n");
	}
}