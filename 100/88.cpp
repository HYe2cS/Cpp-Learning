#include<stdio.h>

main()

{
	int a = 21, i;

	printf("Game begin:\n");

	while (a > 0)

	{
		do {
			printf("How many stick do you wish to take(1~%d)?", a > 4 ? 4 : a);

			scanf("%d", &i);
		} while (i > 4 || i<1 || i>a);      /*接收正在确的输入*/

		if (a - i > 0) printf(" %d stick left in the pile.\n", a - i);

		if ((a - i) <= 0)

		{
			printf(" You have taken the last stick.\n");

			printf(" * * * You lose! \nGame Over.\n");     /*输出取胜标记*/

			break;
		}

		else

			printf(" Compute take %d stick.\n", 5 - i);    /*输出计算机取的子数
   */

		a -= 5;

		printf(" %d stick left in the pile.\n", a);
	}
}