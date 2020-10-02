#include<stdio.h>

int a[27];

main()

{
	int i, j, k, s, n = 0;

	for (i = 0; i <= 4; i++)           /*i:取三分邮票的张数*/

		for (j = 0; j <= 3; j++)       /*j:取5分邮票的张数*/

		{
			s = i * 3 + j * 5;        /*计算组成的邮票面值*/

			for (k = 0; a[k]; k++)     /*查找是否有相同的邮资*/

				if (s == a[k])break;

			if (!a[k] && s)         /*没有找到相同的邮资则满足要求存入数组*
/

			{
				a[k]=s; n++;
			}
		}

	printf("%d kinds:",n);      /*输出结果*/

				for (k = 0; a[k]; k++)

					printf("%d ", a[k]);

			printf("\n");
		}
}