/*（3）声明一个车Vehicle基类，有run、stop等成员函数，
由此派生出自行车Bicycle类、汽车Motorcar类，从Bicycle、Motorcar类派生出摩托车Motorcycle类，
它们都有run、stop等成员函数，观察虚函数的作用。*/
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
    cout << "自行车运行中" << endl;
}
void Bicycle::stop() {
    cout << "自行车停住了" << endl;
}

class Motorcar :virtual public Vehicle {
public:
    void run();
    void stop();
};
void Motorcar::run() {
    cout << "摩托车运行中" << endl;
}
void Motorcar::stop() {
    cout << "摩托车停住了" << endl;
}

class Motorcycle :public Bicycle, public Motorcar {
public:
    void run();
    void stop();
};
void Motorcycle::run() {
    cout << "Motorcycle运行中" << endl;
}
void Motorcycle::stop() {
    cout << "Motorcycle停住了" << endl;
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