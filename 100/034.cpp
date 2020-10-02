#include<stdio.h>

#include<math.h>

#define NUM 320

int number[NUM];      /*��Ų�����1993��ȫ������*/

int fflag(int i);

main()

{
	int i, j, count = 0;

	printf("there are follwing primes sequences in first row:\n");

	for (j = 0, i = 3; i <= 1993; i += 2)       /*���������1993��ȫ������*/

		if (fflag(i)) number[j++] = i;

	for (j--; number[j] > 1898; j--)     /*������������ʼ��1898����*/

	{
		for (i = 0; number[j] - number[i] > 1898; i++);  /*ѭ��������������������
*/

		if (number[j] - number[i] == 1898)          /*�����������Ĳ�Ϊ1898����
���*/

printf("(%d).%3d,.....,%d\n", ++count, number[i], number[j]);
	}
}

int fflag(int i)

{
	int j;

	if (i <= 1) return 0;                /*�ж��Ƿ�Ϊ����*/

	if (i == 2) return 1;

	if (!(i % 2)) return 0;              /*if no, return 0*/

	for (j = 3; j <= (int)(sqrt((double)i) + 1); j += 2)

		if (!(i % j)) return 0;

	return 1;
}