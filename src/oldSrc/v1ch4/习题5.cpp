#include<iostream>
#include<string>
using namespace std;
class person {
protected:
    string name;
    int age;
    char sex;
    string address;
    int phone;
public:
    person(string na, int ag, char se, string add, int ph);
    void show();
};

person::person(string na, int ag, char se, string add, int ph) {
    name = na;
    age = ag;
    sex = se;
    address = add;
    phone = ph;
}
void person::show()
{
    cout << "姓名:" << name << endl << "年龄:" << age << endl << "性别:" << sex << endl
        << "地址:" << address << endl << "电话号码:" << phone << endl;
}

class Teacher :virtual public person {
protected:
    string position;//职称
    float salary;//工资
public:
    Teacher(string na, int ag, char se, string add, int ph, string po, float sa);
    void show();
};
Teacher::Teacher(string na, int ag, char se, string add, int ph, string po, float sa) :person(na, ag, se, add, ph) {
    position = po;
    salary = sa;
}
void Teacher::show() {
    person::show();
    cout << "职称:" << position << endl << "工资:" << salary << endl;
}

class Cadre :virtual public person {
protected:
    string job;//职务
public:
    Cadre(string na, int ag, char se, string add, int ph, string jo);
    void show();
};
Cadre::Cadre(string na, int ag, char se, string add, int ph, string jo) :person(na, ag, se, add, ph) {
    job = jo;
}
void Cadre::show() {
    person::show();
    cout << "职务:" << job << endl;
}

class Teacher_Cadre :public Teacher, public Cadre {
public:
    Teacher_Cadre(string na, int ag, char se, string add, int ph, string jo, string po, float sa) :person(na, ag, se, add, ph),
        Teacher(na, ag, se, add, ph, po, sa),
        Cadre(na, ag, se, add, ph, jo) {
    };
    void show();
};

void Teacher_Cadre::show() {
    person::show();
    cout << "职务:" << job << endl;
    cout << "职称:" << position << endl << "工资:" << salary << endl;
}

int main()
{
    Teacher_Cadre tc("张元节", 19, 'm', "安徽省", 13155299590, "学生", "高级", 1);
    tc.show();
    return 0;
}