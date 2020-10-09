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
		cout << "姓名:" << name << endl << "年龄:" << age << endl;
	}
};
class leader :virtual public base {
protected:
	string zhiwu;//职务
	string bumeng;//部门
public:
	leader(string na, int ag, string zw, string bm) :base(na, ag)
	{
		zhiwu = zw;
		bumeng = bm;
	}
	show() {
		cout << "姓名:" << name << endl << "年龄:" << age << endl << "职务:" << zhiwu << endl << "部门" << bumeng << endl;
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
		cout << "姓名:" << name << endl << "年龄:" << age << endl << "职务:" << zhiwu << endl << "部门" << bumeng << endl
			<< "职称:" << zhicheng << endl << "专业" << zhuanye << endl;
	}
};
int main()
{
	chairman c1("张元节", 20, "学生", "计科院", "学生", "计算机类");
	c1.show();
	return 0;
}