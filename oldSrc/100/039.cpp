#include<stdio.h>

main()

{
	int n, a, i;

	printf("The series with equal difference are:\n");

	for (n = 1; n <= 6; n++)                 /*����nȡֵΪ1~6*/

		for (a = 1; a <= 4; a++)             /*����aȡֵΪ1~4*/

			if (4 * n + 6 * a == 26 && n * (n + a) * (n + a + a) * (n + a + a + a) == 880)  /*�жϽ��*/

				for (i = 0; i < 20; i++)

					printf("%d  ", n + i * a);            /*���ǰ20��*/
}