#include<stdio.h>

main()

{
	int p, q, r, s, count = 0;

	printf("The 4 fractions which sum is equal 1 are:\n");

	for (p = 2; p < 5; p++)                /*穷举分母*/

		for (q = p; q < 7; q++)

			for (r = q; r < 13; r++)

				if (p * q * r - q * r - p * r - p * q != 0)

				{
					s = (p * q * r) / (p * q * r - q * r - p * r - p * q);        /*求出s的值*/

					if (!((p * q * r) % (p * q * r - q * r - p * r - p * q)) && s >= r)

						printf("[%2d]    1/%d+1/%d+1/%d+1/%d=1\n", ++count, p, q, r, s);

					/*输出结果*/
				}
}