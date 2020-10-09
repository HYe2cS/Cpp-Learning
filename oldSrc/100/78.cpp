#include<stdio.h>

#include<math.h>

main()

{
	double e = 0.1, b = 0.5, c, d;

	long int i;                /*i: 正多边形边数*/

	for (i = 6;; i *= 2)            /*正多边形边数加倍*/

	{
		d = 1.0 - sqrt(1.0 - b * b);     /*计算圆内接正多边形的边长*/

		b = 0.5 * sqrt(b * b + d * d);

		if (2 * i * b - i * e < 1e-15) break;         /*精度达1e-15则停止计算*/

		e = b;      /*保存本次正多边形的边长作为下一次精度控制的依据*/
	}

	printf("pai=%.15lf\n", 2 * i * b);       /*输出π值和正多边形的边数*/

	printf("The number of edges of required polygon:%ld\n", i);
}