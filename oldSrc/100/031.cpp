#include<stdio.h>

#include<math.h>

int fflag(int n);

main()

{
	int i, n;

	for (i = 4; i <= 2000; i += 2)

	{
		for (n = 2; n < i; n++)         /*��ż��i�ֽ�Ϊ��������*/

			if (fflag(n))         /*�ֱ��ж����������Ƿ��Ϊ����*/

				if (fflag(i - n))

				{
					printf("%14d=%d+%d\n", i, n, i - n);        /*������������
���*/

					break;
				}

		if (n == i)  printf("error %d\n", i);
	}
}

int fflag(int i)           /*�ж��Ƿ�Ϊ����*/

{
	int j;

	if (i <= 1)return 0;

	if (i == 2)return 1;

	if (!(i % 2))return 0;     /*if no,return 0*/

	for (j = 3; j <= (int)(sqrt((double)i) + 1); j += 2)

		if (!(i % j))return 0;

	return 1;              /*if yes,return 1*/
}