#include<stdio.h>

main()

{
	int t, a[5];            /*����a��ŷֽ������λ*/

	long int k, i;

	for (i = 95860;; i++)      /*��95860Ϊ��ֵ��ѭ����̽*/

	{
		for (t = 0, k = 100000; k >= 10; t++)   /*�Ӹߵ��ͷֽ���ȡiֵ��ÿλ��*/

		{                               /* �֣����δ����a[0]~a[5]��*/

			a[t] = (i % k) / (k / 10);

			k /= 10;
		}

		if ((a[0] == a[4]) && (a[1] == a[3]))

		{
			printf("The new symmetrical number kelometers is:%d%d%d%d%d\
n",

a[0], a[1], a[2], a[3], a[4]);

			printf("The velocity of the car is: %.2f\n", (i - 95859) / 2.0);

			break;
		}
	}
}