#include<stdio.h>

#define MAX 2147483647

long re(long int);

int nonres(long int s);

main()

{
	long int n, m;

	int count = 0;

	printf("Please enetr a number optionaly:");

	scanf("%ld", &n);

	printf("The generation process of palindrome:\n");

	while (!nonres((m = re(n)) + n))     /*�ж��������䷴������Ӻ��Ƿ�Ϊ����
��*/

	{
		if (m + n >= MAX)

		{
			printf(" input error,break.\n");

			break;
		}

		else

		{
			printf("[%d]:%ld+%ld=%ld\n", ++count, n, m, m + n);

			n += m;
		}
	}

	printf("[%d]:%ld+%ld=%ld\n", ++count, n, m, m + n);     /*������õ��Ļ�
����*/

	printf("Here we reached the aim at last!\n");
}

long re(long int a)     /*�����������ķ�����*/

{
	long int t;

	for (t = 0; a > 0; a /= 10)    /*����������*/

		t = t * 10 + a % 10;

	return t;
}

int nonres(long int s)   /*�жϸ����������Ƿ��ǻ�����*/

{
	if (re(s) == s) return 1;       /*���ǻ������򷵻أ�*/

	else return 0;               /*���򷵻ء���*/
}