//student类的编写输入输出
#include<iostream>
#include<string>
using namespace std;
class Student {
public:
    Student(string na = "张三", string sn = "20190000000", char s = 'm', int ag = 20);//构造函数
    void set(string na, string sn, char s, int ag);
    void show();
private:
    string name;
    string sno;
    char sex;
    int age;
};
Student::Student(string na, string sn, char s, int ag)//构造函数
{
    name = na; sno = sn; sex = s; age = ag;
}
void Student::set(string na, string sn, char s, int ag)
{
    name = na; sno = sn; sex = s; age = ag;
}
void Student::show()
{
    cout << "姓名：" << name << "\t学号：" << sno << "\t性别：" << sex << "\t年龄：" << age << endl;
}

void Change(Student* p)	//对象指针作为函数参数:
{
    p->set("吴会宇", "20181251162", 'm', 20);
    cout << "在函数Change内，形参对象p的数据成员值为:" << endl;
    p->show();
}

int main()
{
    Student s1("张元节", "20181251215", 'm', 19);
    //对象指针作为函数参数
    cout << "对象指针作为函数参数:" << endl;
    cout << "在调用函数Change前，实参对象s1的数据成员值为:" << endl;
    s1.show();
    Change(&s1);
    cout << "在调用函数Change后，实参对象s1的数据成员值为:" << endl;
    s1.show();
    return 0;
}