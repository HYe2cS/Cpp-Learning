#include<stdio.h>

main()

{
	int n, count = 0;

	printf("Please enter number:");

	scanf("%d", &n);      /*������һ����*/

	do {
		if (n % 2)

		{
			n = n * 3 + 1;           /*��Ϊ������n��3��1*/

			printf("[%d]:%d*3+1=%d\n", ++count, (n - 1) / 3, n);
		}

		else

		{
			n /= 2;          /*��Ϊż��n����2*/

			printf("[%d]:  %d/2=%d\n", ++count, 2 * n, n);
		}
	} while (n != 1);             /*n������1��������Ϲ���*/
}