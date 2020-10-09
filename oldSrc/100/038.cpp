#include<stdio.h>

main()

{
	int i, j, k, count = 1;

	printf("There are follwing small exchange plans for 1 Yuan note:\n")
		;

	for (i = 0; i <= 100; i++)         /*i为1分硬币钱数，可取值0,1，2...,100*/

		for (j = 0; j <= 100 - i; j += 2)     /*j为2分硬币钱数，可取0值，2，4，...，
100*/

for (k = 0; k <= 100 - i - 2 * j; k += 5)        /*k为5分硬币钱数*/

if (i + j + k == 100)

printf(count % 4 ? "%d:1*%d+2*%d+5*%d\t" : "%d:1*%d+2*%d+5*%d\n", count++, i, j / 2, k / 5);
}