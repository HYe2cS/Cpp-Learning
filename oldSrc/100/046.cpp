#include<stdio.h>
main()
{
	int i, num1, num2, temp;
	printf("The fraction serials with demominator 40 is:\n");
	for (i = 1; i <= 40; i++)                     /*穷举40以内的全部分子*/
	{
		num1 = 40;
		num2 = i;
		while (num2 != 0)              /*采用辗转相除法求出最大公约数*/
		{
			temp = num1 % num2;
			num1 = num2;
			num2 = temp;
		}
		if (num1 == 1)           /*若最大公约数为1，则为最简真分数*/
			printf("%d/40  ", i);
	}
}