#include<stdio.h>

main()

{
	int i;

	for (i = 1002; i < 1111; i++)        /*�����λ�����ܵ�ֵ*/

		if (i % 10 * 1000 + i / 10 % 10 * 100 + i / 100 % 10 * 10 + i / 1000 == i * 9)

			/*�жϷ������Ƿ���ԭ������9��*/

			printf("The number satisfied stats condition is: %d\n", i);

	/*���������*/
}