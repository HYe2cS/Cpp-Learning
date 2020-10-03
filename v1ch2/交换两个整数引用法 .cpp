//交换两个整数 引用法
#include<iostream>
using namespace std;
void Swap(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
int main()
{
	int m = 3, n = 4;
	cout << m << "," << n << endl;
	Swap(m, n);
	cout << m << "," << n << endl;
	return 0;
}