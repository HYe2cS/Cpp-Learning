#include<stdio.h>

int jud1(int s[]);

void print(int u[]);

int count;                /*������*/

main()

{
	static int a[] = { 1,2,3,4,5,6 };    /*��ʼ������*/

	printf("The possble table satisfied above conditions are:\n");

	for (a[1] = a[0] + 1; a[1] <= 5; ++a[1])          /*a[1]�������a[0]*/

		for (a[2] = a[1] + 1; a[2] <= 5; ++a[2])      /*a[2]�������a[1]*/

			for (a[3] = a[0] + 1; a[3] <= 5; ++a[3])   /*�ڶ��е�a[3]�������a[0]
*/

for (a[4] = a[1] > a[3] ? a[1] + 1 : a[3] + 1; a[4] <= 5; ++a[4])

/*�ڶ��е�a[4]����������
a[3]���ϱ�a[1]*/

if (jud1(a)) print(a);       /*����������⣬��ӡ���
*/
}

int jud1(int s[])

{
	int i, l;

	for (l = 1; l < 4; l++)

		for (i = l + 1; i < 5; ++i)

			if (s[l] == s[i])  return 0;    /*�������е��������ظ��ģ�����0
*/

	return 1;                            /*�������е�����û���ظ��ģ�����
1*/
}

void print(int u[])

{
	int k;

	printf("\nNo.:%d", ++count);

	for (k = 0; k < 6; k++)

		if (k % 3 == 0)           /*��������ǰ����Ԫ����Ϊ��һ��*/

			printf("\n%d", u[k]);

		else                 /*�������ĺ�����Ԫ����Ϊ�ڶ���*/

			printf("%d", u[k]);
}