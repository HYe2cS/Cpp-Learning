#include<stdio.h>

#include<math.h>

#define NUM 320

int number[NUM];      /*存放不超过1993的全部奇数*/

int fflag(int i);

main()

{
	int i, j, count = 0;

	printf("there are follwing primes sequences in first row:\n");

	for (j = 0, i = 3; i <= 1993; i += 2)       /*求出不超过1993的全部奇数*/

		if (fflag(i)) number[j++] = i;

	for (j--; number[j] > 1898; j--)     /*从最大的素数开始向1898搜索*/

	{
		for (i = 0; number[j] - number[i] > 1898; i++);  /*循环查找满足条件的素数
*/

		if (number[j] - number[i] == 1898)          /*若两个素数的差为1898，则
输出*/

printf("(%d).%3d,.....,%d\n", ++count, number[i], number[j]);
	}
}

int fflag(int i)

{
	int j;

	if (i <= 1) return 0;                /*判断是否为素数*/

	if (i == 2) return 1;

	if (!(i % 2)) return 0;              /*if no, return 0*/

	for (j = 3; j <= (int)(sqrt((double)i) + 1); j += 2)

		if (!(i % j)) return 0;

	return 1;
}