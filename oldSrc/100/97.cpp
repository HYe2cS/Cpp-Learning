#include<stdio.h>

#define NUM 10      /*允许分解的最大元素数量*/

int i[NUM];        /*记录分解出的数值的数组*/

main()

{
	int sum, n, total, k, flag, count = 0;

	printf("Please enter requried terms(<=10):");

	scanf("%d", &n);

	printf("            their sum:");

	scanf("%d", &total);

	sum = 0;                 /*当前从后向前k个元素的和*/

	k = n;                   /*从后向前正在处理的元素下标*/

	i[n] = 1;             /*将最后一个元素的值置为1作为初始值*/

	printf("There are following possible series:\n");

	while (1)

	{
		if (sum + i[k] < total)     /*若后k位的和小于指定的total*/

			if (k <= 1)            /*若正要处理的是第一个元素*/

			{
				i[1] = total - sum; flag = 1;
			}     /*则计算第一个元素的并置标记*/

			else {
				sum += i[k--];

				i[k] = i[k + 1];        /*置第k位的值后k-1*/

				continue;         /*继续向前处理其它元素*/
			}

		else if (sum + i[k] > total || k != 1)   /*若和已超过total或不是第一个元素*/

		{
			sum -= i[++k]; flag = 0;
		}      /*k向后回退一个元素*/

		else flag = 1;        /*sum+i[k]=total&&k=1 则设置flag标记*/

		if (flag)

		{
			printf("[%d]:", ++count);

			for (flag = 1; flag <= n; ++flag)

				printf("%d", i[flag]);

			printf("\n");
		}

		if (++k > n)     /*k向后回退一个元素后判断是否已退出最后一个元素*/

			break;

		sum -= i[k];

		i[k]++;        /*试验下一个分解*/
	}
}