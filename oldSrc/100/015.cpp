#include<stdio.h>
main()
{
	int n, i, x, flag = 1;          /*flag�����Ʊ��*/
	for (n = 6; flag; n++)          /*������̽�ķ���������ֵ̽n�𲽼Ӵ�*/
	{
		for (x = n, i = 1 && flag; i <= 5; i++)
			if ((x - 1) % 5 == 0) x = 4 * (x - 1) / 5;
			else  flag = 0;              /*�����ܷ������ñ��falg=0�˳�����
����*/
		if (flag) break;              /*��������������������ҵ�����˳���
̽�Ĺ���*/
		else flag = 1;                  /*���������̽��һ����*/
	}
	printf("Total number of fish catched=%d\n", n);     /*������*/
}