#include<stdio.h>

main()

{
	int i, j, a[4];

	for (i = 0; i < 4; i++)            /*假定只有第i个人为窃贱*/

	{
		for (j = 0; j < 4; j++)        /*将第i个人设置为1表示窃贱，其余为0*/

			if (j == i)a[j] = 1;

			else a[j] = 0;

		if (a[3] + a[1] == 1 && a[1] + a[2] == 1 && a[0] + a[1] == 1)   /*判断条件是否成立
*/

		{
			printf("The thief is  ");              /*成立*/

			for (j = 0; j <= 3; j++)                   /*输出计算结果*/

				if (a[j])printf("%c.", j + 'A');

			printf("\n");
		}
	}
}