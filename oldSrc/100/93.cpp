﻿#include<stdio.h>

void movedisc(unsigned n, char fromneedle, char toneedle, char usingneedle)
;

int i = 0;

main()

{
	unsigned n;

	printf("please enter the number of disc:");

	scanf("%d", &n);               /*输入N值*/

	printf("\tneedle:\ta\t b\t c\n");

	movedisc(n, 'a', 'c', 'b');        /*从A上借助B将N个盘子移动到C上*/

	printf("\t Total: %d\n", i);
}

void movedisc(unsigned n, char fromneedle, char toneedle, char usingneedle)

{
	if (n > 0)

	{
		movedisc(n - 1, fromneedle, usingneedle, toneedle);

		/*从fromneedle上借助toneedle将N-1个盘子移动到usingn
eedle上*/

		++i;

		switch (fromneedle)     /*将fromneedle 上的一个盘子移到toneedle上*/

		{
		case 'a': switch (toneedle)

		{
		case 'b': printf("\t[%d]:\t%2d.........>%2d\n", i, n, n);

			break;

		case 'c': printf("\t[%d]:\t%2d...............>%2d\n", i, n, n);

			break;
		}

				break;

		case 'b': switch (toneedle)

		{
		case 'a': printf("\t[%d]:\t%2d<...............>%2d\
n", i, n, n);

			break;

		case 'c': printf("\t[%d]:\t        %2d........>%2d\
n", i, n, n);

			break;
		}

				break;

		case 'c': switch (toneedle)

		{
		case 'a': printf("\t[%d]:\t%2d<............%2d\n", i
			, n, n);

			break;

		case 'b': printf("\t[%d]:\t%2d<........%2d\n", i, n, n
		);

			break;
		}

				break;
		}

		movedisc(n - 1, usingneedle, toneedle, fromneedle);

		/*从usingneedle上借助fromneedle将N-1个盘子移动到toneedle上
*/
	}
}