/*��3������һ����Vehicle���࣬��run��stop�ȳ�Ա������
�ɴ����������г�Bicycle�ࡢ����Motorcar�࣬��Bicycle��Motorcar��������Ħ�г�Motorcycle�࣬
���Ƕ���run��stop�ȳ�Ա�������۲��麯�������á�*/
#include<iostream>
using namespace std;
class Vehicle {
public:
	virtual void run() = 0;
	virtual void stop() = 0;
};
class Bicycle :virtual public Vehicle {
public:
	void run();
	void stop();
};
void Bicycle::run() {
	cout << "���г�������" << endl;
}
void Bicycle::stop() {
	cout << "���г�ͣס��" << endl;
}

class Motorcar :virtual public Vehicle {
public:
	void run();
	void stop();
};
void Motorcar::run() {
	cout << "Ħ�г�������" << endl;
}
void Motorcar::stop() {
	cout << "Ħ�г�ͣס��" << endl;
}

class Motorcycle :public Bicycle, public Motorcar {
public:
	void run();
	void stop();
};
void Motorcycle::run() {
	cout << "Motorcycle������" << endl;
}
void Motorcycle::stop() {
	cout << "Motorcycleͣס��" << endl;
}
int main() {
	Vehicle* p;
	Bicycle ob1;
	Motorcar ob2;
	Motorcycle ob3;
	p = &ob1; p->run(); p->stop();
	p = &ob2; p->run(); p->stop();
	p = &ob3; p->run(); p->stop();
	return 0;
}