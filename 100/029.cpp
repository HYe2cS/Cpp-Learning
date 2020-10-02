#include<stdio.h>

main()

{
	int n, a, b;

	printf("There are following number with 4 digits satisfied condition\n");

	for (n = 1000; n < 10000; n++)             /*四位数N的取值范围1000~9999*/

	{
		a = n / 100;                        /*截取N的前两位数存于a*/

		b = n % 100;                        /*截取N的后两位存于b*/

		if ((a + b) * (a + b) == n)      /*判断N是否为符合题目所规定的性质的四位数
*/

printf("%d  ", n);
	}
}