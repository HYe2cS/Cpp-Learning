#include<stdio.h>

main()

{
	int i, j, a[4];

	for (i = 0; i < 4; i++)            /*�ٶ�ֻ�е�i����Ϊ�Լ�*/

	{
		for (j = 0; j < 4; j++)        /*����i��������Ϊ1��ʾ�Լ�������Ϊ0*/

			if (j == i)a[j] = 1;

			else a[j] = 0;

		if (a[3] + a[1] == 1 && a[1] + a[2] == 1 && a[0] + a[1] == 1)   /*�ж������Ƿ����
*/

		{
			printf("The thief is  ");              /*����*/

			for (j = 0; j <= 3; j++)                   /*���������*/

				if (a[j])printf("%c.", j + 'A');

			printf("\n");
		}
	}
}