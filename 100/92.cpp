#include<stdio.h>

#include<stdlib.h>

void bhdy(int s, int b);

void prt();

int a[4], flag, count;

main()

{
	int b1, b2, i, j, k = 0, p, c;

	printf("Game guess your number in mind is # # # #.\n");

	for (i = 1; i < 10 && k < 4; i++)    /*�ֱ���ʾ�ĸ�1~9ȷ���ĸ����ֵ����*/

	{
		printf("No.%d:your number may be:%d%d%d%d\n", ++count, i, i, i, i);

		printf("How many digits have bad correctly guessed:");

		scanf("%d", &p);          /*�����������λ����*/

		for (j = 0; j < p; j++)

			a[k + j] = i;          /*a[]:�����ȷ�����ֵ�����*/

		k += p;             /*k:��ȷ�������ָ���*/
	}

	if (k < 4)           /*�Զ������λ�а��ĸ���*/

		for (j = k; j < 4; j++)

			a[j] = 0;

	i = 0;

	printf("No.%d:your number may be:%d%d%d%d\n", ++count, a[0], a[1], a[2], a[3]);

	printf("How many are in exact positions:");    /*˳����ʾ��λ����*/

	scanf("%d", &b1);             /*�������м�λλ������ȷ��*/

	if (b1 == 4) { prt(); exit(0); }     /*��λ��ȷ����ӡ�����������Ϸ*/

	for (flag = 1, j = 0; j < 3 && flag; j++)   /*ʵ���ĸ����ֵ�����(a[j],a[k]����*/

		for (k = j + 1; k < 4 && flag; k++)

			if (a[j] != a[k])

			{
				c = a[j]; a[j] = a[k]; a[k] = c;      /*����a[j],a[k]*/

				printf("No.%d:Your number may be: %d%d%d%d\n", ++count, a[0], a[1], a[2], a[3]);

				printf("How many are in exact positins:");

				scanf("%d", &b2);          /*�����м���λ����ȷ*/

				if (b2 == 4) { prt(); flag = 0; }    /*��ȫ����ȷ��������Ϸ*/

				else if (b2 - b1 == 2)bhdy(j, k);  /*���ϴ��뱾�εĲ�Ϊ2���򽻻���
	��Ԫ�ؼ��ɽ���*/

				else if (b2 - b1 == -2)   /*���ϴ��뱾�εĲ�Ϊ-2����˵���ѽ�����(
	a[j],a[k])�Ǵ����

									   ��(a[j],a[k]��ԭ��ֻҪ������������Ԫ
	�ؼ��ɽ�����Ϸ*/

				{
					c = a[j]; a[j] = a[k]; a[k] = c;

					bhdy(j, k);
				}

				else if (b2 <= b1)

				{
					c = a[j]; a[j] = a[k]; a[k] = c;     /*�ָ���������������*/
				}

				else b1 = b2;    /*����������������λ����Ϣ��Ϊ�ϴε�λ�ñ�
	��*/
			}

	if (flag) printf("You input error!\n");  /*���������û�����ֻ����
���������Ϣ����*/
}

void prt()         /*��ӡ�����������Ϸ*/

{
	printf("Now your number must be %d%d%d%d.\n", a[0], a[1], a[2], a[3]);

	printf("Game Over\n");
}

void bhdy(int s, int b)

{
	int i, c = 0, d[2];

	for (i = 0; i < 4; i++)             /*����s��b���������Ԫ���±�*/

		if (i != s && i != b) d[c++] = i;

	i = a[d[1]]; a[d[1]] = a[d[0]];  a[d[0]] = i;  /*������a[s]��a[b]���������Ԫ��*/

	prt();        /*��ӡ�����������Ϸ*/

	flag = 0;
}