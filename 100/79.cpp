#include<time.h>

#include<stdlib.h>

#include<stdio.h>

#define N 30000

main()

{
	float x, y;

	int c = 0, d = 0;

	//randomsize();

	while (c++ <= N)

	{
		x = random(101);      /*x:���ꡣ����0��100֮�乲101���������*/

		y = random(101);      /*y:���ꡣ����0��100֮�乲101���������*/

		if (x * x + y * y <= 10000)     /*����Բ�����жϵ��Ƿ�����Բ��*/

			d++;
	}

	printf(" pi=%f\n", 4. * d / N);    /*�������Ħ�ֵ*/
}