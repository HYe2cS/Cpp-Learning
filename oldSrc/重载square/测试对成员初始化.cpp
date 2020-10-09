//测试能否对公有的对象成员和私有的对象成员在声明时初始化
#include<iostream>
using namespace std;
class test {
	int a1 = 0; //这种写法在c++11以后才被允许
public:
	int b1 = 3;//这种初始化的写法在c++11以后才被允许
	int b2;
}b2;
int main() {
	test t1;
	t1.b1 = 2;
	t1.b2 = 2;
	cout << t1.b1 << endl;
	cout << t1.b2 << endl;
}