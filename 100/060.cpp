#include<stdio.h>

int ok(int t, int* z);

int a[9];

main()

{
	int m, count = 0;

	for (m = 123; m <= 333; m++)           /*��̽���ܵ���λ��*/

		if (ok(m, a) && ok(2 * m, a + 3) && ok(3 * m, a + 6))      /*����������*/

			printf("No.%d:  %d %d %d\n", ++count, m, 2 * m, 3 * m);    /*������
*/
}

int ok(int t, int* z)     /*�ֽ�t��ֵ���������zָ�����������Ԫ�أ�������
Ҫ�󷵻�1*/

{
	int* p1, * p2;

	for (p1 = z; p1 < z + 3; p1++)

	{
		*p1 = t % 10;               /*�ֽ�����*/

		t /= 10;

		for (p2 = a; p2 < p1; p2++)     /*��ѯ�ֽ���������Ƿ��Ѿ����ֹ�*/

			if (*p1 == 0 || *p2 == *p1)return 0;    /*���ظ��򷵻�*/
	}

	return 1;                /*���򷵻�1*/
}