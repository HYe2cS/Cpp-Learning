//编写一个学生和教师的数据输入和显示程序。学生数据有编号、姓名、性别、年龄、系别和成绩，
//教师数据有编号、姓名、性别、年龄、职称和部门。要求将编号、姓名、性别、年龄的输入和显示设计成一个类Person，并作为学生类Student和教师类Teacher的基类。
#include<iostream>
#include<string>
using namespace std;
class Person {
public:

protected:
    string sno;
    string name;
    char sex;
    int age;
};
class Student :public Person {
public:
    void input()
    {
        cout << "请输入学生信息:" << endl;
        cout << "编号:";
        cin >> sno;
        cout << "姓名:";
        cin >> name;
        cout << "性别:";
        cin >> sex;
        cout << "年龄:";
        cin >> age;
        cout << "系别:";
        cin >> xibie;
        cout << "成绩:";
        cin >> score;
    }
    void output()
    {
        cout << "编号:" << sno << endl << "姓名:" << name << endl
            << "性别:" << sex << endl << "年龄:" << age << endl << "系别:" << xibie << endl << "成绩:" << score << endl;
    }
private:
    string xibie;//系别
    float score;//成绩
};
class Teacher :public Person {
private:
    string major;//职称
    string bumeng;//部门
public:
    void input()
    {
        cout << "请输入教师信息:" << endl;
        cout << "编号:";
        cin >> sno;
        cout << "姓名:";
        cin >> name;
        cout << "性别:";
        cin >> sex;
        cout << "年龄:";
        cin >> age;
        cout << "职称:";
        cin >> major;
        cout << "部门:";
        cin >> bumeng;
    }
    void output()
    {
        cout << "编号:" << sno << endl << "姓名:" << name << endl
            << "性别:" << sex << endl << "年龄:" << age << endl << "职称:" << major << endl << "部门:" << bumeng << endl;
    }
};
int main()
{
    int num;
    cout << "请输入学生人数:";
    cin >> num;
    Student s1[num];
    for (int i = 0; i < num; i++)
    {
        cout << "请输入第" << i + 1 << "位学生信息:" << endl;
        s1[i].input();
    }

    for (int i = 0; i < num; i++)
    {
        cout << "第" << i + 1 << "位学生信息:" << endl;
        s1[i].output();
    }

    cout << "请输入教师人数:";
    cin >> num;
    Teacher t2[num];
    for (int i = 0; i < num; i++)
    {
        cout << "请输入第" << i + 1 << "位教师信息:" << endl;
        t2[i].input();
    }

    for (int i = 0; i < num; i++)
    {
        cout << "第" << i + 1 << "位教师信息:" << endl;
        t2[i].output();
    }

    return 0;
}