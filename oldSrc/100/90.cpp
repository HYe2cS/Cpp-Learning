﻿#include<stdio.h>

main()

{
	int n, k, x, y, cc, pc, g;

	printf("More Mountain Game\n");

	printf("Game Begin\n");

	pc = cc = 0;

	g = 1;

	for (;;)

	{
		printf("No.%2d game \n", g++);

		printf("---------------------------------------\n");

		printf("How many mpuntains are there?");

		scanf("%d", &n);

		if (!n) break;

		printf("How many mountains are allowed to each time?");

		do {
			scanf("%d", &k);

			if (k > n || k < 1) printf("Repeat again!\n");
		} while (k > n || k < 1);

		do {
			printf("How many mountains do you wish movw away?");

			scanf("%d", &x);

			if (x<1 || x>k || x > n)      /*判断搬山数是否符合要求*/

			{
				printf("IIIegal,again please!\n");

				continue;
			}

			n -= x;

			printf("There are %d mountains left now.\n", n);

			if (!n)

			{
				printf("...............I win. You are failure...............\n\
n"); cc++;
			}

			else

			{
				y = (n - 1) % (k + 1);      /*求出最佳搬山数*/

				if (!y) y = 1;

				n -= y;

				printf("Copmputer move %d mountains away.\n", y);

				if (n) printf(" There are %d mountains left now.\n", n);

				else

				{
					printf("...............I am failure. You win..................\n\n");

					pc++;
				}
			}
		} while (n);
	}

	printf("Games in total have been played %d.\n", cc + pc);

	printf("You score is win %d,lose %d.\n", pc, cc);

	printf("My score is win %d,lose %d.\n", cc, pc);
}