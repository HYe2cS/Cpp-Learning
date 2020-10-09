#include<stdio.h>

main()

{
	int n, count = 0;

	printf("Please enter number:");

	scanf("%d", &n);      /*输入任一整数*/

	do {
		if (n % 2)

		{
			n = n * 3 + 1;           /*若为奇数，n乘3加1*/

			printf("[%d]:%d*3+1=%d\n", ++count, (n - 1) / 3, n);
		}

		else

		{
			n /= 2;          /*若为偶数n除以2*/

			printf("[%d]:  %d/2=%d\n", ++count, 2 * n, n);
		}
	} while (n != 1);             /*n不等于1则继续以上过程*/
}