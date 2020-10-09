#include<stdio.h>

#include<time.h>

#include<stdlib.h>

main()

{
	int stime, a, z, t, i, c, m, g, s, j, k, l[4];    /*j:数字正确的位数  k:位置正确
 的位数*/

	long ltime;

	ltime = time(NULL);       /*l:数字相同时，人所猜中数字的正确位置*/

	stime = (unsigned int)ltime / 2;

	srand(stime);

	z = rand(9999);        /*计算机想一个随机数*/

	printf("I have a number with 4 digits in mind,please guess.\n");

	for (c = 1;; c++)         /*c: 猜数次数计数器*/

	{
		printf("Enter a number with 4 digits:");

		scanf("%d", &g);           /*请人猜*/

		a = z; j = 0; k = 0; l[0] = l[1] = l[2] = l[3] = 0;

		for (i = 1; i < 5; i++)      /*i:原数中的第i位数。个位为第一位，千位为第4
  位*/

		{
			s = g; m = 1;

			for (t = 1; t < 5; t++)     /*人所猜想的数*/

			{
				if (a % 10 == s % 10)     /*若第i位与人猜的第t位相同*/

				{
					if (m && t != l[0] && t != l[1] && t != l[2] && t != l[3])

					{
						j++; m = 0; l[j - 1] = t;    /*若该位置上的数字尚未与其它数字"
	  相同"*/
					}                       /*记录相同数字时，该数字在所猜数字
	 中的位置*/

					if (i == t) k++;         /*若位置也相同，则计数器k加1*/
				}

				s /= 10;
			}

			a /= 10;
		}

		printf("You hane correctly guessed %d digits,\n", j);

		printf("and correctly guessed %d digits in exact position.\n", k);

		if (k == 4) break;         /*若位置全部正确，则人猜对了，退出*/
	}

	printf("Now you have correctly guessed the whole number after %d times.\n", c);
}