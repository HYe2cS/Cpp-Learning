#include<stdio.h>

main()

{
	int i = 1;                  /*iΪ����Ľ�����*/

	while (!((i % 2 == 1) && (i % 3 == 2) && (i % 5 == 4) && (i % 6 == 5) && (i % 7 == 0)))

		++i;                  /*����һ��ͬ��ʽ���б�*/

	printf("Staris_number=%d\n", i);
}