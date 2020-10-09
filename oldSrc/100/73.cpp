#include<stdio.h>
main()

{
	int a, b, c, d, e, i, j, k, l, m, x, count = 0, f = 0;  /*f:分解的5个数可以表示出1~23
 的标记*/

	printf("There are following possble result:\n");

	for (a = 1; a <= 23; a++)         /*将23分解为a,b,c,d,e五个数*/

		for (b = 1 + a; b <= 23 - a; b++)

			for (c = 1 + b; c <= 23 - a - b; c++)

				for (d = 1 + c; d <= 23 - a - b - c; d++)

				{
					f = 1;

					if ((e = 23 - a - b - c - d) > d)

						for (f = 0, x = 1; x < 24 && !f; x++)     /*判断5个数可否表示1~23*
	  /

						   for(f=1,i=0;i<2&&f;i++)    /*穷举5个数的全部取舍*/

							for (j = 0; j < 2 && f; j++)

								for (k = 0; k < 2 && f; k++)

									for (l = 0; l < 2 && f; l++)

										for (m = 0; m < 2 && f; m++)

											if (x == a * i + b * j + c * k + d * l + e * m) f = 0;

					if (!f) printf("[%d]: %d %d %d %d %d\n", ++count, a, b, c, d, e)
						;
				}
}