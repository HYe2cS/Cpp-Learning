#include<stdio.h>

#define NUM 9

int a[NUM + 1];

main()

{
	int i, k, flag, not_finish = 1;

	long sum;

	i = 1;

	/*i:正在处理的数组元素，表示前i-1个元素已经满足要求，正处理的是第
i个元素*/

	a[1] = 1;                     /*为元素a[1]设置初值*/

	while (not_finish)           /*not_finish=1:处理没有结束*/

	{
		while (not_finish && i <= NUM)

		{
			for (flag = 1, k = 1; flag && k < i; k++)

				if (a[k] == a[i])flag = 0;      /*判断第i个元素是否与前i-1个元
素重复*/

			for (sum = 0, k = 1; flag && k <= i; k++)

			{
				sum = 10 * sum + a[k];

				if (sum % k)flag = 0;       /*判断前k位组成的整数是否
能被k整除*/
			}

			if (!flag)        /*flag=0:表示第i位不满足要求，需要重新设
置*/

			{
				if (a[i] == a[i - 1])    /*若a[i]的值已经经过一圈追上a[i-
1]*/

				{
					i--;           /*i值减1，退回处理前一个元素*/

					if (i > 1 && a[i] == NUM)

						a[i] = 1;       /*当第i位的值达到NUM时，第i位的
值取1*/

					else if (i == 1 && a[i] == NUM)  /*当第1位的值达到NUM时
结束*/

not_finish = 0;        /*置程序结束标记*/

					else a[i]++;             /*第i位的值取下一个,加1
*/
				}

				else if (a[i] == NUM) a[i] = 1;

				else a[i]++;
			}

			else           /*第i位已经满足要求，处理第i+1位*/

				if (++i <= NUM)        /*i+1处理下一元素，当i没有处理完
毕时*/

if (a[i - 1] == NUM) a[i] = 1;      /*若i-1的值已为NUM，
则a[i]的值为1*/

else a[i] = a[i - 1] + 1;             /*否则，a[i]的初值为
a[i-1]值的"下一个"值*/
		}

		if (not_finish)

		{
			printf("\nThe progressire divisiable number is:");

			for (k = 1; k <= NUM; k++)               /*输出计算结果*/

				printf("%d", a[k]);

			if (a[NUM - 1] < NUM) a[NUM - 1]++;

			else a[NUM - 1] = 1;

			not_finish = 0;

			printf("\n");
		}
	}
}