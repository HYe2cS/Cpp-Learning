#include<stdio.h>
main()
{
	int a, i, m;
	printf("There are following perfect numbers smaller than 1000:\n");
	for (a = 1; a < 1000; a++)      /*ѭ������ѡȡ1~1000�еĸ��������ж�*/
	{
		for (m = 0, i = 1; i <= a / 2; i++)   /*����a�����ӣ�����������֮��m=a����a��
��ȫ�����*/
if (!(a % i))m += i;
		if (m == a)
			printf("%4d    ", a);
	}
	printf("\n");
}