#include<stdio.h>

main()

{
	long int i;

	int count = 0;               /*count:ͳ��������������λ���ĸ���*/

	for (i = 1000; i < 9999; i++)

		if (!((i * 10 + 6) % 3))      /*�ж���ѡ�����ܷ�3����*/

			count++;           /*���������������*/

	printf("count=%d\n", count);
}