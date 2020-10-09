#include<stdio.h>

main()

{
	int i;

	for (i = 0;; i++)                 /*试探商的值*/

		if (((i * 8 + 7) * 8 + 1) * 8 + 1 == (34 * i + 15) * 17 + 4)

		{               /*逆推判断所取得的当前i值是否满足关系式*/

						/*若满足则输出结果*/

			printf("The required number is: %d\n", (34 * i + 15) * 17 + 4);

			break;            /*退出循环*/
		}
}