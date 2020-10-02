#include<iostream>
using namespace std;
class Sample {
	int m;
	Sample(int i, int j)
	{
		m = i;
		n = j;
	}
	void setvalue(int i)
	{
		n = i;
	}
	void display()
	{
		cout << "m=" << m << endl;
		cout << "n=" << n << endl;
	}
private:
};