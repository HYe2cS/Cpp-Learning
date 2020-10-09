#include<stdio.h>

main()

{
	int i;

	for (i = 1002; i < 1111; i++)        /*穷举四位数可能的值*/

		if (i % 10 * 1000 + i / 10 % 10 * 100 + i / 100 % 10 * 10 + i / 1000 == i * 9)

			/*判断反序数是否是原整数的9倍*/

			printf("The number satisfied stats condition is: %d\n", i);

	/*若是则输出*/
}