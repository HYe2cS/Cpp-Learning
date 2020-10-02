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
		x = random(101);      /*x:坐标。产生0到100之间共101个的随机数*/

		y = random(101);      /*y:坐标。产生0到100之间共101个的随机数*/

		if (x * x + y * y <= 10000)     /*利用圆方程判断点是否落在圆内*/

			d++;
	}

	printf(" pi=%f\n", 4. * d / N);    /*输出求出的π值*/
}