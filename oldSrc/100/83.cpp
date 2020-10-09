#include<stdio.h>

void vr6174(int);

void parse_sort(int num, int* each);

void max_min(int* each, int* max, int* min);

void parse_sort(int num, int* each);

int count = 0;
main()

{
	int n;

	printf("Enter a number:");

	scanf("%d", &n);        /*��������������*/

	vr6174(n);           /*���ú���������֤*/
}

void vr6174(int num)

{
	int each[4], max, min;

	if (num != 6174 && num)    /*��������74�Ҳ�����0����п����п�����*/

	{
		parse_sort(num, each);         /*�������ֽ⣬���ִ���each������*/

		max_min(each, &max, &min);      /*��������ɵ����ֵ����Сֵ*/

		num = max - min;          /*�����ֵ����Сֵ�Ĳ�*/

		printf("[%d]:  %d-%d=%d\n", ++count, max, min, num); /*����ò������
��*/

		vr6174(num);         /*�ݹ��������������п����п�����*/
	}
}

void parse_sort(int num, int* each)

{
	int i, * j, * k, temp;

	for (i = 0; i <= 4; i++)         /*��NUM�ֽ�Ϊ����*/

	{
		j = each + 3 - i;

		*j = num % 10;

		num /= 10;
	}

	for (i = 0; i < 3; i++)     /*�Ը������ִ�С�����������*/

		for (j = each, k = each + 1; j < each + 3 - i; j++, k++)

			if (*j > * k) { temp = *j; *j = *k; *k = temp; }

	return;
}

void max_min(int* each, int* max, int* min)    /*���ֽ�����ֻ�ԭΪ�������
����С����*/

{
	int* i;

	*min = 0;

	for (i = each; i < each + 4; i++)     /*��ԭΪ��С������*/

		*min = *min * 10 + *i;

	*max = 0;

	for (i = each + 3; i >= each; i--)    /*��ԭΪ��������*/

		*max = *max * 10 + *i;

	return;
}