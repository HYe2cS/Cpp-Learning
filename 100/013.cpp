#include<stdio.h>
main()
{
	int i;
	float total = 0;
	for (i = 0; i < 5; i++)                     /*i Ϊ������ȡֵΪ0~4��*/
		total = (total + 1000) / (1 + 0.0063 * 12);  /*�ۼ�����������������εļ�
��
											 �����Ϊ���*/
	printf("He must save %.2f at first.\n", total);
}