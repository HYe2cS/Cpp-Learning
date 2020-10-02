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
	/*初始化随机数发生器*/

	if (rand() % 2 == 1)      /*取随机数决定机器和人谁先走第一步*/

		tol = input(tol);    /*若为1，则余元走第一步*/

	while (tol != 30)        /*游戏结束条件*/

		if ((tol = copu(tol)) == 30)       /*计算机取一个数，若为30则机器胜利*/

			printf("I lose! \n");

		else

			if ((tol = input(tol)) == 30)     /*人取一个数，若为30则人胜利*/

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

	return t + a;        /*返回当前的已经取走的数累加和*/
}

int copu(int s)

{
	int c;

	printf("Computer count:");

	if ((s + 1) % 3 == 0)          /*若剩余的数的模为1，则取1*/

		printf(" %d\n", ++s);

	else if ((s + 2) % 3 == 0)

	{
		s += 2;     /*若剩余的数的模为2，则取2*/

		printf(" %d\n", s);
	}

	else

	{
		c = rand() % 2 + 1;     /*否则随机取1或2*/

		s += c;

		printf(" %d\n", s);
	}

	return s;
}