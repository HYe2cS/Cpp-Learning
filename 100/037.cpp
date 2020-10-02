#include<stdio.h>

main()

{
	int i = 1;                  /*i为所设的阶梯数*/

	while (!((i % 2 == 1) && (i % 3 == 2) && (i % 5 == 4) && (i % 6 == 5) && (i % 7 == 0)))

		++i;                  /*满足一组同余式的判别*/

	printf("Staris_number=%d\n", i);
}