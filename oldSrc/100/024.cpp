#include<stdio.h>

main()

{
	int i, t, k, a[3];
	printf("There are follwing Armstrong number smaller than 1000:\n");
	for (i = 2; i < 1000; i++)         /*���Ҫ�ж�����i��ȡֵ��Χ2~1000*/
	{
		for (t = 0, k = 1000; k >= 10; t++)     /*��ȡ����i�ĸ�λ(�Ӹ����λ)*/
		{
			a[t] = (i % k) / (k / 10);        /*�ֱ���a[0]~a[2}*/
			k /= 10;
		}
		if (a[0] * a[0] * a[0] + a[1] * a[1] * a[1] + a[2] * a[2] * a[2] == i)
			/*�ж�i�Ƿ�Ϊ��ķ˹������*/
			printf("%5d", i);            /*�����������������*/
	}
	printf("\n");
}