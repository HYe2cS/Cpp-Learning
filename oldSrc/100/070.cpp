#include<stdio.h>

int a[27];

main()

{
	int i, n, j = 1;

	a[1] = 1;                  /*��ʼ����һ����*/

	printf("The original order of cards is:(r:rad b:block):\n");

	for (i = 2; i <= 26; i++)

	{
		n = 1;

		do {
			if (j > 26) j = 1;       /*�������һ��Ԫ����ָ��1��Ԫ��*/

			if (a[j]) j++;        /*�����ǿյĺ��ӣ������м���*/

			else {
				if (n == 3) a[j] = i;    /*��������3���պ��ӣ����Ʒ���պ���
*/

				j++; n++;      /*�Կպм����������±�ָ����һ������*/
			}
		} while (n <= 3);       /*���ƿպм���Ϊ3*/
	}

	for (i = 1; i <= 26; i++)           /*����Ƶ�����˳��*/

	{
		printf("%c", a[i] > 13 ? 'r' : 'b');

		printf("%d ", a[i] > 13 ? a[i] - 13 : a[i]);

		if (i == 13) printf("\n");
	}

	printf("\n");
}