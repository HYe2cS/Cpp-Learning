#include<stdio.h>

#define N 6                /*确定N值*/

main()

{
	int i, j, k, t;

	printf("The possble Latin Squares of order %d are:\n", N);

	for (j = 0; j < N; j++)                /*构造N个不同的拉丁方阵*/

	{
		for (i = 0; i < N; i++)

		{
			t = (i + j) % N;        /*确定该拉丁方阵第i 行的第一个元素的值*/

			for (k = 0; k < N; k++)  /*按照环的形式输出该行中的各个元素*/

				printf("%d", (k + t) % N + 1);

			printf("\n");
		}

		printf("\n");
	}
}