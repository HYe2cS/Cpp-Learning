#include<stdio.h>

main()

{
	long int a;

	for (a = 1001; a <= 3000; a += 2)

	{
		printf("%ld:", a);       /*输出奇数本身*/

		printf("(%ld*%ld-1)/8", a, a);      /*输出(奇数的平方减1)/8*/

		printf("=%ld", (a * a - 1) / 8);        /*输出被8除后的商*/

		printf("+%ld\n", (a * a - 1) % 8);      /*输出被8除后的余数*/
	}
}