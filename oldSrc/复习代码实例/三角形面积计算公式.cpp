/*2. 从键盘输入三条边a、b和c，若能构成三角形则输出其面积，
否则输出不能构成三角形的提示信息"No triangle"。 三角形面积计算公式    其中：s=(a+b+c)／2。（10分）
*/
#include<stdio.h>
#include<math.h>
int main()
{
	float s, area, a, b, c;
	scanf("a=%f b=%f c=%f", &a, &b, &c);
	if (a + b > c && a + c > b && b + c > a)
	{
		s = (a + b + c) / 2;
		area = sqrt(s * (s - a) * (s - b) * (s - c));
		printf("area=%f\n", area);
	}
	else 	printf("no triangle!");
	return 0;
}