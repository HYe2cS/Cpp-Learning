#include<stdio.h>

int number;

void print(int a[]);

void change(int* n, int* m);
main()

{
	int t[7] = { 1,1,1,0,2,2,2 };   /*��ʼ������1������  2������  0���ո�*/

	int i, flag;

	print(t);

	while (t[0] + t[1] + t[2] != 6 || t[4] + t[5] + t[6] != 3)  /*�ж���Ϸ�Ƿ����

									 ����û��������ӵĽ������������ѭ��
 */

	{
		flag = 1;      /*flag Ϊ�����ƶ�һ���ı��1����δ�ƶ�����  0���Ѿ���
  ������*/

		for (i = 0; flag && i < 5; i++)      /*�����ӿ��������������ӣ������������
  */

			if (t[i] == 1 && t[i + 1] == 2 && t[i + 2] == 0)

			{
				change(&t[i], &t[i + 2]); print(t); flag = 0;
			}

		for (i = 0; flag && i < 5; i++)      /*�����ӿ��������������ӣ������������
  */

			if (t[i] == 0 && t[i + 1] == 1 && t[i + 2] == 2)

			{
				change(&t[i], &t[i + 2]);  print(t);  flag = 0;
			}

		for (i = 0; flag && i < 6; i++)   /*�������ƶ����Ӳ����������,�����������
  ��*/

			if (t[i] == 1 && t[i + 1] == 0 && (i == 0 || t[i - 1] != t[i + 2]))

			{
				change(&t[i], &t[i + 1]); print(t); flag = 0;
			}

		for (i = 0; flag && i < 6; i++)   /*�������ƶ����Ӳ�����������������������
  ��*/

			if (t[i] == 0 && t[i + 1] == 2 && (i == 5 || t[i - 1] != t[i + 2]))

			{
				change(&t[i], &t[i + 1]); print(t); flag = 0;
			}
	}
}

void print(int a[])

{
	int i;

	printf("No. %2d:.............................\n", number++);

	printf("      ");

	for (i = 0; i <= 6; i++)

		printf(" | %c", a[i] == 1 ? '*' : (a[i] == 2 ? '@' : ' '));

	printf(" |\n       .............................\n\n");
}

void change(int* n, int* m)

{
	int term;

	term = *n; *n = *m; *m = term;
}