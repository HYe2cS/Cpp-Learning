#include<stdio.h>

main()

{
	int n, i, un1, un2, un;

	for (n = 2; n < 3;)

	{
		printf("Please enter required number of generation:");

		scanf("%d", &n);

		if (n < 3) printf("\n Enter error!\n");     /*����������ȷ��Nֵ*/
	}

	un = un2 = 1;

	printf("The repid increase of rabbits in first %d generation is as felow:\n", n);

	printf("l\tl\t");

	for (i = 3; i <= n; i++)

	{
		un1 = un2;

		un2 = un;

		un = un1 + un2;      /*����ͨ�ʽ���N���ֵ*/

		printf(i % 10 ? "%d\t" : "%d\n", un);
	}

	printf("\n");
}