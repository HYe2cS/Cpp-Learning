#include<stdio.h>

main()

{
	int a, b, c;

	for (a = 0; a <= 1; a++)       /*���ÿ������˵�ѻ��ǳ�ʵ��ȫ�����*/

		for (b = 0; b <= 1; b++)    /*˵�ѣ�0   ��ʵ��1*/

			for (c = 0; c <= 1; c++)

				if ((a && a + b + c == 2 || !a && a + b + c != 2)    /*�ж��Ƿ���������*/

					&& (b && a + b + c == 1 || !b && a + b + c != 1)

					&& (c && a + b + c == 1 || !c && a + b + c != 1))

				{
					printf("A is a %s.\n", a ? "honest" : "lier");    /*�����
�Ͻ��*/

					printf("B is a %s.\n", b ? "honest" : "lier");

					printf("C is a %s.\n", c ? "honest" : "lier");
				}
}