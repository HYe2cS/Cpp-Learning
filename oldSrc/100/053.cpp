#include<stdio.h>

main()

{
	int a, b, c;

	for (a = 0; a <= 1; a++)       /*穷举每个人是说谎还是诚实的全部情况*/

		for (b = 0; b <= 1; b++)    /*说谎：0   诚实：1*/

			for (c = 0; c <= 1; c++)

				if ((a && a + b + c == 2 || !a && a + b + c != 2)    /*判断是否满足题意*/

					&& (b && a + b + c == 1 || !b && a + b + c != 1)

					&& (c && a + b + c == 1 || !c && a + b + c != 1))

				{
					printf("A is a %s.\n", a ? "honest" : "lier");    /*输出判
断结果*/

					printf("B is a %s.\n", b ? "honest" : "lier");

					printf("C is a %s.\n", c ? "honest" : "lier");
				}
}