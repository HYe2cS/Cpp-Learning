#include<stdio.h>

#include<time.h>

#include<stdlib.h>

int input(int t);

int copu(int s);

main()

{
	int tol = 0;

	printf("\n* * * * * * * *catch thirty* * * * * * * \n");

	printf("Game Begin\n");

	srand(time(0));
	/*��ʼ�������������*/

	if (rand() % 2 == 1)      /*ȡ�����������������˭���ߵ�һ��*/

		tol = input(tol);    /*��Ϊ1������Ԫ�ߵ�һ��*/

	while (tol != 30)        /*��Ϸ��������*/

		if ((tol = copu(tol)) == 30)       /*�����ȡһ��������Ϊ30�����ʤ��*/

			printf("I lose! \n");

		else

			if ((tol = input(tol)) == 30)     /*��ȡһ��������Ϊ30����ʤ��*/

				printf("I lose! \n");

	printf(" * * * * * * *  *Game Over * * * * * * * *\n");
}

int input(int t)

{
	int a;

	do {
		printf("Please count:");

		scanf("%d", &a);

		if (a > 2 || a < 1 || t + a>30)

			printf("Error input,again!");

		else

			printf("You count:%d\n", t + a);
	} while (a > 2 || a < 1 || t + a>30);

	return t + a;        /*���ص�ǰ���Ѿ�ȡ�ߵ����ۼӺ�*/
}

int copu(int s)

{
	int c;

	printf("Computer count:");

	if ((s + 1) % 3 == 0)          /*��ʣ�������ģΪ1����ȡ1*/

		printf(" %d\n", ++s);

	else if ((s + 2) % 3 == 0)

	{
		s += 2;     /*��ʣ�������ģΪ2����ȡ2*/

		printf(" %d\n", s);
	}

	else

	{
		c = rand() % 2 + 1;     /*�������ȡ1��2*/

		s += c;

		printf(" %d\n", s);
	}

	return s;
}