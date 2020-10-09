#include"circle.h"
#include"iostream.h"
//类的实现

circle::circle(double r)
{
	re = r;
}

void circle::area()
{
	cout << 3.14 * re * re << endl;
}