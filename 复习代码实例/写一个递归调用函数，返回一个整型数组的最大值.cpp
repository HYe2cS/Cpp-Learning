/*3、写一个递归调用函数，返回一个整型数组的最大值
*/
#include <stdio.h>
int main()
{
	int arr[10] = { 12,4,6,72,3,32,435,32,-324,34 }, max;
	int arrmax(int* p, int n);
	max = arrmax(arr, 10);
	printf("max=%d\n", max);
	return 0;
}

int arrmax(int* p, int n)
{
	int max, k;
	if (n == 1) max = k = *p;
	else
	{
		k = arrmax(p, n - 1);
		max = *(p + n - 1) > k ? *(p + n - 1) : k;
	}
	return(max);
}