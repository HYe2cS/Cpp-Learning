#include<stdio.h>

main()

{
	int x, y, z, count = 0;

	printf("            Men           Women            Children\n");

	printf("........................................\n");

	for (x = 0; x <= 10; x++)

	{
		y = 20 - 2 * x;                     /*x��ֵ��(3)ʽ��y*/

		z = 30 - x - y;                     /*��(1)ʽ��z*/

		if (3 * x + 2 * y + z == 50)             /*��ǰ�õ���һ����Ƿ�����ʽ(2)*/

			printf(" %2d:         %d         %d         %d\n", ++count, x,
				y, z);
	}
}