#include<stdio.h>

main()

{
	int x, y, z;

	for (x = 1; x <= 3; x++)          /*���x��ȫ��������ż*/

		for (y = 1; y <= 3; y++)      /*���y��ȫ��������ż*/

			for (z = 1; z <= 3; z++)    /*���z��ȫ��������ż*/

				if (x != 1 && x != 3 && z != 3 && x != y && x != z && y != z)  /*�ж���ż�Ƿ���
������*/

				{
					printf("X will marry to %c.\n", 'A' + x - 1);    /*��ӡ��
�Ͻ��*/

					printf("Y will marry to %c.\n", 'A' + y - 1);

					printf("Z will marry to %c.\n", 'A' + z - 1);
				}
}