#include<stdio.h>

main()

{
	int a, b, c, d;

	printf("Please enter a number:");

	scanf("%d", &a);           /*��������*/

	b = a * a * a;                  /*�����������η�*/

	printf("%d*%d*%d=%d=", a, a, a, b);

	for (d = 0, c = 0; c < a; c++)       /*������У�����Ϊa*a-a+1,�Ȳ�ֵΪ2*/

	{
		d += a * a - a + 1 + c * 2;       /*�����е�ǰa��ĺ�*/

		printf(c ? "+%d" : "%d", a * a - a + 1 + c * 2);
	}

	if (d == b)printf(" Y\n");    /*���������������"Y"*/

	else printf(" N\n");       /*�������"N"*/
}