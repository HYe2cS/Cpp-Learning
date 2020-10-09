#include<iostream>
using namespace std;
class N {
public:
	N(int a);
	static void f1(N m);
private:
	int A;
	static int B;
};
N::N(int a)
{
	A = a;
	B += a;
}
void N::f1(N m)
{
	cout << "A=" << m.A << endl;
	cout << "B=" << B << endl;
}
int N::B = 0;
int main()
{
	N P(5), Q(9);
	N::f1(P);
	N::f1(Q);
	return 0;
}