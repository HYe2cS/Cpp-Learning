#include<stdio.h>

main()

{
	long int a, b, c;

	printf("Please enter a optional fraction(a/b):");

	scanf("%ld/%ld", &a, &b);           /*�������a�ͷ�ĸb*/

	printf("It can be decomposed to:");

	while (1)

	{
		if (b % a)              /*�����Ӳ���������ĸ*/

			c = b / a + 1;         /*��ֽ��һ����ĸΪb/a+1�İ�������*/

		else { c = b / a; a = 1; }   /*������������������(��������)*/

		if (a == 1)

		{
			printf("1/%ld\n", c);

			break;              /*aΪ1��־����*/
		}

		else

			printf("1/%ld + ", c);

		a = a * c - b;               /*��������ķ���*/

		b = b * c;                 /*��������ķ�ĸ*/

		if (a == 3)               /*������Ϊ3��������������������*/

		{
			printf("1/%ld + 1/%ld\n", b / 2, b);  break;
		}
	}
}