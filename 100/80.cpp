#include<stdio.h>

main()

{
	long int a;

	for (a = 1001; a <= 3000; a += 2)

	{
		printf("%ld:", a);       /*�����������*/

		printf("(%ld*%ld-1)/8", a, a);      /*���(������ƽ����1)/8*/

		printf("=%ld", (a * a - 1) / 8);        /*�����8�������*/

		printf("+%ld\n", (a * a - 1) % 8);      /*�����8���������*/
	}
}