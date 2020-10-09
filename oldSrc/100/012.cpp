#include<stdio.h>
#include<math.h>
main()
{
	int i, j, k, c;
	for (i = 1; i <= 9; i++)                  /*i:车号前二位的取值*/
		for (j = 0; j <= 9; j++)              /*j:车号后二位的取值*/
			if (i != j)                   /*判断二位数字是否相异*/
			{
				k = i * 1000 + i * 100 + j * 10 + j; /*计算出可能的整数*/
				for (c = 31; c * c < k; c++);   /*判断该数是否为另一整数的平方*/
				if (c * c == k) printf("Lorry--No. is %d.\n", k);     /*若是，打印
结果*/
			}
}