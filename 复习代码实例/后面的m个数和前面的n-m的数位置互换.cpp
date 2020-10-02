/*3.（15分） 用指针处理：有n个整数，使后面的m个数和前面的n-m的数位置互换。编写4个函数：
(1)	main()中调用其它函数；
(2)	input()：输入n个数；
(3)	change()：进行处理；
(4)	output()：输出10个数。
*/
void change(int* p, int n, int m)
{
	int i, j, t;
	for (j = 1; j <= m; j++)
	{
		t = *(p + n - 1);
		for (i = n - 1; i > 0; i--)
			*(p + i) = *(p + i - 1);
		*p = t;
	}
}