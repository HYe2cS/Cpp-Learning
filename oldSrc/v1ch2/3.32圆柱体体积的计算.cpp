//Բ��������ļ���
#include<iostream>
#define pi 3.14
using namespace std;
class cylinder {
public:
	cylinder(double r = 0, double h = 0);
	void set(double r, double h);
	void calculate();
	void vol();
private:
	double radius;
	double height;
	double V;
};
cylinder::cylinder(double r, double h)
{
	radius = r; height = h;
}
void cylinder::set(double r, double h)
{
	radius = r; height = h;
}
void cylinder::calculate()
{
	V = pi * radius * radius * height;
}
void cylinder::vol()
{
	cout << "Բ����������:" << V << endl;
}
int main()
{
	cylinder c1(30.5, 24.3);
	c1.calculate();
	c1.vol();
	return 0;
}