#include<stdio.h>

int a[27];

main()

{
	int i, n, j = 1;

	a[1] = 1;                  /*初始化第一张牌*/

	printf("The original order of cards is:(r:rad b:block):\n");

	for (i = 2; i <= 26; i++)

	{
		n = 1;

		do {
			if (j > 26) j = 1;       /*超过最后一个元素则指向1号元素*/

			if (a[j]) j++;        /*跳过非空的盒子，不进行计数*/

			else {
				if (n == 3) a[j] = i;    /*若数到第3个空盒子，则将牌放入空盒中
*/

				j++; n++;      /*对空盒计数，数组下标指向下一个盒子*/
			}
		} while (n <= 3);       /*控制空盒计数为3*/
	}

	for (i = 1; i <= 26; i++)           /*输出牌的排列顺序*/

	{
		printf("%c", a[i] > 13 ? 'r' : 'b');

		printf("%d ", a[i] > 13 ? a[i] - 13 : a[i]);

		if (i == 13) printf("\n");
	}

	printf("\n");
}