#include<stdio.h>

#define NUM 10      /*����ֽ�����Ԫ������*/

int i[NUM];        /*��¼�ֽ������ֵ������*/

main()

{
	int sum, n, total, k, flag, count = 0;

	printf("Please enter requried terms(<=10):");

	scanf("%d", &n);

	printf("            their sum:");

	scanf("%d", &total);

	sum = 0;                 /*��ǰ�Ӻ���ǰk��Ԫ�صĺ�*/

	k = n;                   /*�Ӻ���ǰ���ڴ����Ԫ���±�*/

	i[n] = 1;             /*�����һ��Ԫ�ص�ֵ��Ϊ1��Ϊ��ʼֵ*/

	printf("There are following possible series:\n");

	while (1)

	{
		if (sum + i[k] < total)     /*����kλ�ĺ�С��ָ����total*/

			if (k <= 1)            /*����Ҫ������ǵ�һ��Ԫ��*/

			{
				i[1] = total - sum; flag = 1;
			}     /*������һ��Ԫ�صĲ��ñ��*/

			else {
				sum += i[k--];

				i[k] = i[k + 1];        /*�õ�kλ��ֵ��k-1*/

				continue;         /*������ǰ��������Ԫ��*/
			}

		else if (sum + i[k] > total || k != 1)   /*�����ѳ���total���ǵ�һ��Ԫ��*/

		{
			sum -= i[++k]; flag = 0;
		}      /*k������һ��Ԫ��*/

		else flag = 1;        /*sum+i[k]=total&&k=1 ������flag���*/

		if (flag)

		{
			printf("[%d]:", ++count);

			for (flag = 1; flag <= n; ++flag)

				printf("%d", i[flag]);

			printf("\n");
		}

		if (++k > n)     /*k������һ��Ԫ�غ��ж��Ƿ����˳����һ��Ԫ��*/

			break;

		sum -= i[k];

		i[k]++;        /*������һ���ֽ�*/
	}
}