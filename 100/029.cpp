#include<stdio.h>

main()

{
	int n, a, b;

	printf("There are following number with 4 digits satisfied condition\n");

	for (n = 1000; n < 10000; n++)             /*��λ��N��ȡֵ��Χ1000~9999*/

	{
		a = n / 100;                        /*��ȡN��ǰ��λ������a*/

		b = n % 100;                        /*��ȡN�ĺ���λ����b*/

		if ((a + b) * (a + b) == n)      /*�ж�N�Ƿ�Ϊ������Ŀ���涨�����ʵ���λ��
*/

printf("%d  ", n);
	}
}