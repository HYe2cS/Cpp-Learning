#include<iostream>
#include<string>
using namespace std;
class base {
protected:
	string name;
	int age;
public:
	base(string na, int ag) {
		name = na;
		age = ag;
	}
	show() {
		cout << "����:" << name << endl << "����:" << age << endl;
	}
};
class leader :virtual public base {
protected:
	string zhiwu;//ְ��
	string bumeng;//����
public:
	leader(string na, int ag, string zw, string bm) :base(na, ag)
	{
		zhiwu = zw;
		bumeng = bm;
	}
	show() {
		cout << "����:" << name << endl << "����:" << age << endl << "ְ��:" << zhiwu << endl << "����" << bumeng << endl;
	}
};
class engieer :virtual public base {
protected:
	string zhicheng;
	string zhuanye;
public:
	engieer(string na, int ag, string zc, string zy) :base(na, ag)
	{
		zhicheng = zc;
		zhuanye = zy;
	}
	show() {
	}
};
class chairman :public leader, public engieer {
public:
	chairman(string na, int ag, string zw, string bm, string zc, string zy) :base(na, ag), leader(na, ag, zw, bm), engieer(na, ag, zc, zy)
	{
	}
	show() {
		cout << "����:" << name << endl << "����:" << age << endl << "ְ��:" << zhiwu << endl << "����" << bumeng << endl
			<< "ְ��:" << zhicheng << endl << "רҵ" << zhuanye << endl;
	}
};
int main()
{
	chairman c1("��Ԫ��", 20, "ѧ��", "�ƿ�Ժ", "ѧ��", "�������");
	c1.show();
	return 0;
}