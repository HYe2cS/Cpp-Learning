#include<stdio.h>
int main()
{
	int integer, i, max, min, sum;
	max = -32768;                  /*�ȼ��赱ǰ�����ֵmaxΪC��������������Сֵ
*/
	min = 32767;                   /*�ȼ��赱ǰ����СֵminΪC���������������ֵ
*/
	sum = 0;                       /*�����ۼӺͱ����ĳ�ֵ��Ϊ0*/
	for (i = 1; i <= 10; i++)
	{
		printf("Input number %d=", i);
		scanf("%d", &integer);          /*������ί������*/
		sum += integer;                  /*�����ܷ�*/
		if (integer > max)max = integer;    /*ͨ���Ƚ�ɸѡ�����е���߷�*/
		if (integer < min)min = integer;    /*ͨ���Ƚ�ɸѡ�����е���ͷ�*/
	}
	printf("Canceled max score:%d\nCanceled min score:%d\n", max, min);
	printf("Average score:%d\n", (sum - max - min) / 8);     /*������*/
}