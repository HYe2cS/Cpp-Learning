#include<stdio.h>
main()
{
	int i, num1, num2, temp;
	printf("The fraction serials with demominator 40 is:\n");
	for (i = 1; i <= 40; i++)                     /*���40���ڵ�ȫ������*/
	{
		num1 = 40;
		num2 = i;
		while (num2 != 0)              /*����շת�����������Լ��*/
		{
			temp = num1 % num2;
			num1 = num2;
			num2 = temp;
		}
		if (num1 == 1)           /*�����Լ��Ϊ1����Ϊ��������*/
			printf("%d/40  ", i);
	}
}