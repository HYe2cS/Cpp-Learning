#include<stdio.h>

main()

{
	long int i;

	int count = 0;               /*count:统计满足条件的五位数的个数*/

	for (i = 1000; i < 9999; i++)

		if (!((i * 10 + 6) % 3))      /*判断所选的数能否被3整除*/

			count++;           /*若满足条件则计数*/

	printf("count=%d\n", count);
}