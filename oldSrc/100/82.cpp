#include<stdio.h>

#include<stdlib.h>
main()

{
	int number, i, j, k, l;

	printf("Please enter a number=");

	scanf("%d", &number);                /*��������*/

	for (i = 1; i < number / 2; i++)         /*��̽������̽i,j,k,k�Ĳ�ֵͬ*/

		for (j = 0; j <= i; j++)

			for (k = 0; k <= j; k++)

				for (l = 0; l <= k; l++)

					if (number == i * i + j * j + k * k + l * l)    /*�����㶨��Ҫ�������
���*/

					{
						printf(" %d=%d*%d+%d*%d+%d*%d+%d*%d\n", number, i,
							i, j, j, k, k, l, l);

						exit(0);
					}
}