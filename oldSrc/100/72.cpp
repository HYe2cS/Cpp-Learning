#include<stdio.h>

int a[27];

main()

{
	int i, j, k, s, n = 0;

	for (i = 0; i <= 4; i++)           /*i:ȡ������Ʊ������*/

		for (j = 0; j <= 3; j++)       /*j:ȡ5����Ʊ������*/

		{
			s = i * 3 + j * 5;        /*������ɵ���Ʊ��ֵ*/

			for (k = 0; a[k]; k++)     /*�����Ƿ�����ͬ������*/

				if (s == a[k])break;

			if (!a[k] && s)         /*û���ҵ���ͬ������������Ҫ���������*
/

			{
				a[k]=s; n++;
			}
		}

	printf("%d kinds:",n);      /*������*/

				for (k = 0; a[k]; k++)

					printf("%d ", a[k]);

			printf("\n");
		}
}