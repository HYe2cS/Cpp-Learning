#include<iostream>
#include<string>
using namespace std;
class CPU {
public:
    CPU();
    ~CPU();
    string GetRank();
    int GetFrequency();
    float GetVoltage();
    void SetRank(string r = "P0");
    void SetFrequency(int f = 0);
    void SetVoltage(float v = 0);
    void Run();
    void Stop();
private:
    string rank;//等级
    int frequency;//频率
    float voltage;//电压
};
CPU::CPU()
{
    cout << "构造一个CPU" << endl;
}
CPU::~CPU()
{
    cout << "析构一个CPU" << endl;
}
string CPU::GetRank()
{
    return rank;
}
int CPU::GetFrequency()
{
    return frequency;
}
float CPU::GetVoltage()
{
    return voltage;
}
void CPU::SetRank(string r)
{
    rank = r;
}
void CPU::SetFrequency(int f)
{
    frequency = f;
}
void CPU::SetVoltage(float v)
{
    voltage = v;
}
void CPU::Run()
{
    cout << "CPU开始运行！" << endl;
}
void CPU::Stop()
{
    cout << "CPU停止运行！" << endl;
}

class Student {
public:
    void account(float s);
    static float sum();
    static float average();
private:
    float score;
    static float total_score;
    static int count;
};
void Student::account(float s)
{
    score = s;
    count++;
    total_score += s;
}
float Student::sum()
{
    return total_score;
}
float Student::average()
{
    return total_score / count;
}
float Student::total_score = 0;
int Student::count = 0;

class Car {
public:
    void Input();
    friend void Output(Car& x);
private:
    float speed;
    string color;
};
void Car::Input()
{
    cout << "请输入车的颜色:";
    cin >> color;
    cout << "请输入车的速度:";
    cin >> speed;
}
void  Output(Car& x)
{
    cout << "车的颜色是" << x.color << ",车的速度是" << x.speed << endl;
}

class Date {
public:
    Date(int y, int m, int d);
    void set(int y, int m, int d);
    void show();
private:
    int year;
    int month;
    int day;
};
Date::Date(int y, int m, int d)
{
    year = y; month = m; day = d;
}
void Date::set(int y, int m, int d)
{
    year = y; month = m; day = d;
}
void Date::show()
{
    cout << "生日：" << year << "年" << month << "月" << day << "日" << endl;
}
class Person {
public:
    Person(int y = 2000, int m = 00, int d = 00, string i = "20000000000", string na = "张三", char se = 'm');
    void set(int y, int m, int d, string i, string na, char se);
    void show();
private:
    Date birthday;
    string id;
    string name;
    char sex;
};
Person::Person(int y, int m, int d, string i, string na, char se) :birthday(y, m, d)
{
    id = i;
    name = na;
    sex = se;
}
void Person::set(int y, int m, int d, string i, string na, char se)
{
    id = i;
    name = na;
    sex = se;
    birthday.set(y, m, d);
}
void Person::show()
{
    cout << "编号：" << id << endl << "姓名：" << name << endl << "性别：" << sex << endl;
    birthday.show();
}
int main()
{
    /*
    CPU cpu1;
    cpu1.SetRank("P1");
    cpu1.SetFrequency(3000);
    cpu1.SetVoltage(220);
    cpu1.Run();
    cout<<"cpu1的等级是："<<cpu1.GetRank()<<endl;
    cout<<"cpu1的频率是："<<cpu1.GetFrequency()<<endl;
    cout<<"cpu1的电压是："<<cpu1.GetVoltage()<<endl;
    cpu1.Stop();
    */
    /*
    Student s[100];
    cout<<"请输入本班学生人数:";
    int n;
    cin>>n;
    float sc;
    for(int i=0;i<n;i++)
    {
        cout<<"请输入第"<<i+1<<"个学生的分数:";
        cin>>sc;
        s[i].account(sc);
    }
    cout<<"全班的总成绩是:"<<Student::sum()<<endl;
    cout<<"全班的平均成绩是:"<<Student::average()<<endl;
    */
    /*
    Car c1;
    c1.Input();
    Output(c1);
    */
    Person p[100];
    cout << "请输入人员个数:";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "请输入第" << i + 1 << "个人员信息:" << endl;
        int y; int m; int d; string id; string na; char se;
        cout << "编号："; cin >> id;
        cout << "姓名："; cin >> na;
        cout << "性别："; cin >> se;
        cout << "生日："; cin >> y >> m >> d;
        p[i].set(y, m, d, id, na, se);
    }
    for (int i = 0; i < n; i++)
    {
        if ((i / 5) == 0)cout << "=============================" << endl;
        p[i].show();
    }
    return 0;
}