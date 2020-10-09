#include<stdio.h>

main()

{
	int i, t, k, a[3];
	printf("There are follwing Armstrong number smaller than 1000:\n");
	for (i = 2; i < 1000; i++)         /*穷举要判定的数i的取值范围2~1000*/
	{
		for (t = 0, k = 1000; k >= 10; t++)     /*截取整数i的各位(从高向低位)*/
		{
			a[t] = (i % k) / (k / 10);        /*分别赋于a[0]~a[2}*/
			k /= 10;
		}
		if (a[0] * a[0] * a[0] + a[1] * a[1] * a[1] + a[2] * a[2] * a[2] == i)
			/*判断i是否为阿姆斯特朗数*/
			printf("%5d", i);            /*若满足条件，则输出*/
	}
	printf("\n");
}