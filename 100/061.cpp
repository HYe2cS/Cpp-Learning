#include<stdio.h>

main()

{
	int a[20], num[20][3], b[10];     /*a:存放满足条件的三位数*/

									/*若不是10 的倍数，则分解三位数*/

									/*分解该三位数中的每一个数字*/

	int i, j, k, m, n, t, flag;

	printf("The 3 squares with 3 different digits each are:\n");

	for (j = 0, i = 11; i <= 31; i++)      /*求出是平方数的三位数*/

		if (i % 10 != 0)            /*若不是10的倍数，则分解三位数*/

		{
			k = i * i;             /*分解该三位数中的每一个数字*/

			num[j + 1][0] = k / 100;   /*百位*/

			num[j + 1][1] = k / 10 % 10;    /*十位*/

			num[j + 1][2] = k % 10;      /*个位*/

			if (!(num[j + 1][0] == num[j + 1][1] || num[j + 1][0] == num[j + 1][2] ||

				num[j + 1][1] == num[j + 1][2]))     /*若分解的三位
数字均不相等*/

a[++j] = k;      /*j:计数器，统计已找到的满足要求的三位数*/
		}

	for (i = 1; i <= j - 2; ++i)     /*从满足条件的三位数中选出三个进行组合*/

	{
		b[1] = num[i][0];

		b[2] = num[i][1];

		b[3] = num[i][2];

		for (t = i + 1; t <= j - 1; ++t)

		{
			b[4] = num[t][0];           /*取第t个数的三位数字*/

			b[5] = num[t][1];

			b[6] = num[t][2];

			for (flag = 0, m = 1; !flag && m <= 3; m++)     /*flag:出现数字重复的标记
*/

for (n = 4; !flag && n <= 6; n++)      /*判断两个数的数字是否有重
复*/

if (b[m] == b[n])flag = 1;      /*flag=1:数字有重复*/

			if (!flag)

				for (k = t + 1; k <= j; k++)

				{
					b[7] = num[k][0];         /*取第k个数的三位数字*/

					b[8] = num[k][1];

					b[9] = num[k][2];

					for (flag = 0, m = 1; !flag && m <= 6; m++)  /*判断前两个数字是否
*/

for (n = 7; !flag && n <= 9; n++)     /*与第三个数的数字重
复*/

if (b[m] == b[n])flag = 1;

					if (!flag)             /*若均不重复则打印结果*/

						printf("%d,%d,%d\n", a[i], a[t], a[k]);
				}
		}
	}
}