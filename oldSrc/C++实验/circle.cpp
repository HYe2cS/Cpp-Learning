#include"circle.h"
#include"iostream.h"
//���ʵ��

circle::circle(double r)
{
	re = r;
}

void circle::area()
{
	cout << 3.14 * re * re << endl;
}