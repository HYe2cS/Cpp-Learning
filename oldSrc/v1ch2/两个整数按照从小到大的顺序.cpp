//两个整数按照从小到大的顺序
#include<iostream>
using namespace std;
void F(int& a, int& b)
{
	int temp;
	if (a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}
}
class AB {
};
int main()
{
	//	int m,n;
	//	cout<<"请输入两个整数a b:";
	//	cin>>m>>n;
	//	F(m,n);
	//	cout<<"按照从小到大的顺序是:"<<m<<" "<<n<<endl;

	//	int *p = new int[10];
	//	delete[] p;
	//	cout<<(*p);
	//	int &*a;
	//	int i;
	//	int &j=i;
	//	i=30;
	//	cout<<&i<<endl<<&j<<endl;
	return 0;
}