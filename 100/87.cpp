#include<stdio.h>

int number;

void print(int a[]);

void change(int* n, int* m);
main()

{
	int t[7] = { 1,1,1,0,2,2,2 };   /*初始化数组1：白子  2：黑子  0：空格*/

	int i, flag;

	print(t);

	while (t[0] + t[1] + t[2] != 6 || t[4] + t[5] + t[6] != 3)  /*判断游戏是否结束

									 若还没有完成棋子的交换则继续进行循环
 */

	{
		flag = 1;      /*flag 为棋子移动一步的标记1：尚未移动棋子  0：已经移
  动棋子*/

		for (i = 0; flag && i < 5; i++)      /*若白子可以向右跳过黑子，则白子向右跳
  */

			if (t[i] == 1 && t[i + 1] == 2 && t[i + 2] == 0)

			{
				change(&t[i], &t[i + 2]); print(t); flag = 0;
			}

		for (i = 0; flag && i < 5; i++)      /*若黑子可以向左跳过白子，则黑子向左跳
  */

			if (t[i] == 0 && t[i + 1] == 1 && t[i + 2] == 2)

			{
				change(&t[i], &t[i + 2]);  print(t);  flag = 0;
			}

		for (i = 0; flag && i < 6; i++)   /*若向右移动白子不会产生阻塞,则白子向右移
  动*/

			if (t[i] == 1 && t[i + 1] == 0 && (i == 0 || t[i - 1] != t[i + 2]))

			{
				change(&t[i], &t[i + 1]); print(t); flag = 0;
			}

		for (i = 0; flag && i < 6; i++)   /*若向左移动黑子不会产生阻塞，则黑子向左移
  动*/

			if (t[i] == 0 && t[i + 1] == 2 && (i == 5 || t[i - 1] != t[i + 2]))

			{
				change(&t[i], &t[i + 1]); print(t); flag = 0;
			}
	}
}

void print(int a[])

{
	int i;

	printf("No. %2d:.............................\n", number++);

	printf("      ");

	for (i = 0; i <= 6; i++)

		printf(" | %c", a[i] == 1 ? '*' : (a[i] == 2 ? '@' : ' '));

	printf(" |\n       .............................\n\n");
}

void change(int* n, int* m)

{
	int term;

	term = *n; *n = *m; *m = term;
}