#include<stdio.h>

#define NUM 9

int a[NUM + 1];

main()

{
	int i, k, flag, not_finish = 1;

	long sum;

	i = 1;

	/*i:���ڴ��������Ԫ�أ���ʾǰi-1��Ԫ���Ѿ�����Ҫ����������ǵ�
i��Ԫ��*/

	a[1] = 1;                     /*ΪԪ��a[1]���ó�ֵ*/

	while (not_finish)           /*not_finish=1:����û�н���*/

	{
		while (not_finish && i <= NUM)

		{
			for (flag = 1, k = 1; flag && k < i; k++)

				if (a[k] == a[i])flag = 0;      /*�жϵ�i��Ԫ���Ƿ���ǰi-1��Ԫ
���ظ�*/

			for (sum = 0, k = 1; flag && k <= i; k++)

			{
				sum = 10 * sum + a[k];

				if (sum % k)flag = 0;       /*�ж�ǰkλ��ɵ������Ƿ�
�ܱ�k����*/
			}

			if (!flag)        /*flag=0:��ʾ��iλ������Ҫ����Ҫ������
��*/

			{
				if (a[i] == a[i - 1])    /*��a[i]��ֵ�Ѿ�����һȦ׷��a[i-
1]*/

				{
					i--;           /*iֵ��1���˻ش���ǰһ��Ԫ��*/

					if (i > 1 && a[i] == NUM)

						a[i] = 1;       /*����iλ��ֵ�ﵽNUMʱ����iλ��
ֵȡ1*/

					else if (i == 1 && a[i] == NUM)  /*����1λ��ֵ�ﵽNUMʱ
����*/

not_finish = 0;        /*�ó���������*/

					else a[i]++;             /*��iλ��ֵȡ��һ��,��1
*/
				}

				else if (a[i] == NUM) a[i] = 1;

				else a[i]++;
			}

			else           /*��iλ�Ѿ�����Ҫ�󣬴����i+1λ*/

				if (++i <= NUM)        /*i+1������һԪ�أ���iû�д�����
��ʱ*/

if (a[i - 1] == NUM) a[i] = 1;      /*��i-1��ֵ��ΪNUM��
��a[i]��ֵΪ1*/

else a[i] = a[i - 1] + 1;             /*����a[i]�ĳ�ֵΪ
a[i-1]ֵ��"��һ��"ֵ*/
		}

		if (not_finish)

		{
			printf("\nThe progressire divisiable number is:");

			for (k = 1; k <= NUM; k++)               /*���������*/

				printf("%d", a[k]);

			if (a[NUM - 1] < NUM) a[NUM - 1]++;

			else a[NUM - 1] = 1;

			not_finish = 0;

			printf("\n");
		}
	}
}