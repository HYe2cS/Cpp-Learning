#include<iostream>
#include<string>
#include<fstream>
#include<io.h>
//张元节：排序，查找 preTop函数 printInfor函数 ,Student类成员及主函数的书写规范制定
using namespace std;
class Date {
public:
    Date(int y, int m, int d);
    void set(int y, int m, int d);
    void show();
    int getyear() { return year; }
    int getmonth() { return month; }
    int getday() { return day; }
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
    cout << year << "年" << month << "月" << day << "日";
}
class Student {
public:
    Student(int y = 2000, int m = 00, int d = 00,
        string name = "张三",
        string id = "340321200000000000",
        string number = "20000000000",
        string sex = "男",
        float chinese = 0,
        float math = 0,
        float english = 0);
    void set(int y = 2000, int m = 00, int d = 00,
        string name = "张三",
        string id = "340321200000000000",
        string number = "20000000000",
        string sex = "男",
        float chinese = 0,
        float math = 0,
        float english = 0);
    void show();

    //实现一个读取文件保存函数,
    static void readInformation(Student stu[], int& N);
    static void saveInformation(Student stu[], int& N);
    static void preMenu();
    static void preTop();//输出时的界面头部

    //实现一个对数组的添加(add)输出(printInfor)函数
    static void addInfor(Student stu[], int& N);
    static void printInfor(Student stu[], int N);

    //实现一个 冒泡排序,分别按照学号、姓名和个人平均分顺序排序
    static int sort(Student stu[], int& N);
    static int sortByNumber(Student stu[], int& N);
    static int sortByName(Student stu[], int& N);

    //实现一个对数组的查找函数
    static int search(Student stu[], int N);
    static int searchByNumber(Student stu[], int N);
    static int searchByName(Student stu[], int N);

    static int edit(Student stu[], int& N);
    static int del(Student stu[], int& N);

private:
    Date birthday;//生日
    string name;//姓名
    string id;//身份证号
    string number; //学号
    string sex;//性别
    float chinese;//语文成绩
    float math;//数学成绩
    float english;//英语成绩
};
Student::Student(int y, int m, int d,
    string name,
    string id,
    string number,
    string sex,
    float chinese,
    float math,
    float english) :birthday(y, m, d)
{
    this->name = name;
    this->id = id;
    this->number = number;
    this->sex = sex;
    this->chinese = chinese;
    this->math = math;
    this->english = english;
}
void Student::set(int y, int m, int d,
    string name,
    string id,
    string number,
    string sex,
    float chinese,
    float math,
    float english)
{
    birthday.set(y, m, d);
    this->name = name;
    this->id = id;
    this->number = number;
    this->sex = sex;
    this->chinese = chinese;
    this->math = math;
    this->english = english;
}
void Student::show()
{
    cout << name
        << "\t" << id
        << "\t" << number
        << "\t";
    birthday.show();
    cout << "\t" << sex
        << "\t" << chinese
        << "\t" << math
        << "\t" << english << endl;
}
inline void Student::preTop()
{
    cout << "姓名\t"
        << "身份证号\t\t"
        << "学号\t\t"
        << "出生年月日\t"
        << "性别\t"
        << "语文\t"
        << "数学\t"
        << "英语" << endl;
}

inline void Student::preMenu()
{
    cout << "                   欢迎使用学生信息管理系统" << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                       1.显示学生信息" << endl;
    cout << "                       2.添加学生信息" << endl;
    cout << "                       3.删除学生信息" << endl;
    cout << "                       4.查询学生信息" << endl;
    cout << "                       5.修改学生信息" << endl;
    cout << "                       6.排序学生信息" << endl;
    cout << "                       7.退出系统" << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "请选择:" << endl;
}

void Student::readInformation(Student stu[], int& N)//没完成
{
    char dir[] = { "TEST.txt" };
    if (_access(dir, 0) == -1) {//如果没有文件,创建文件
        fstream iofile(dir, ios::out);
        if (!iofile)
        {
            cout << "创建文件失败！" << "TEST.txt" << endl;
            exit(1);//失败退回操作系统
        }
        iofile << 0;
        N = 0;
        iofile.close();
    }
    else {//打开文件
        fstream iofile(dir, ios::in);
        if (!iofile)//如果不能打开
        {
            cout << "不能打开" << endl;
            exit(1);//失败退回操作系统
        }
        iofile >> N; //试图去读一个字符
        while (!iofile.eof()) //表示文件不为空
        {
            if (!N) {
                N = 0; break;
            }
            for (int i = 0; i < N; i++)
            {
                int year, month, day;
                iofile >> stu[i].name
                    >> stu[i].id
                    >> stu[i].number
                    >> year
                    >> month
                    >> day
                    >> stu[i].sex
                    >> stu[i].chinese
                    >> stu[i].math
                    >> stu[i].english;
                stu[i].birthday.set(year, month, day);
            }
        }
        iofile.close();
    }
}

void Student::saveInformation(Student stu[], int& N)//没完成
{
    fstream iofile("TEST.txt", ios::out);
    if (!iofile)
    {
        cout << "打开文件失败！" << "TEST.txt" << endl;
        exit(1);//失败退回操作系统
    }
    iofile << N;
    for (int i = 0; i < N; i++)
    {
        iofile << stu[i].name
            << " " << stu[i].id
            << " " << stu[i].number
            << " " << stu[i].birthday.getyear()
            << " " << stu[i].birthday.getmonth()
            << " " << stu[i].birthday.getday()
            << " " << stu[i].sex
            << " " << stu[i].chinese
            << " " << stu[i].math
            << " " << stu[i].english << endl;
    }
    iofile.close();
}

//实现一个对数组的添加(add)函数
void Student::addInfor(Student stu[], int& N)
{
    int k;
    int j = 1;//储存第多少位信息

    int year;
    int month;
    int day;
    string name;//姓名
    string id;//身份证号
    string number; //学号
    string sex;//性别
    float chinese;//语文成绩
    float math;//数学成绩
    float english;//英语成绩

    cout << "要添加的人数(整数)：";
    while (getchar() != '\n');                     //清空键盘缓冲区
    cin >> k;//输入数据
    for (int i = N; i < N + k; i++)
    {
        cout << "请输入第" << j << "位人员信息：" << endl;
        j++;
        cout << "姓名：";
        cin >> name;
        cout << "身份证号：";
        cin >> id;
        cout << "学号：";
        cin >> number;
        cout << "出生年月日：";
        cin >> year >> month >> day;
        cout << "性别：";
        cin >> sex;
        cout << "语文：";
        cin >> chinese;
        cout << "数学：";
        cin >> math;
        cout << "英语：";
        cin >> english;
        stu[i].set(year, month, day, name, id, number, sex, chinese, math, english);
        cout << "第" << j << "位人员信息:" << endl;
        preTop();
        stu[i].show();
    }
    N = N + k;
    saveInformation(stu, N);
}
//实现一个对数组的输出(printInfor)函数
void Student::printInfor(Student stu[], int N)
{
    if (N)preTop();
    for (int i = 0; i < N; i++)
    {
        stu[i].show();
    }

    cout << "全部输出完成!" << endl;
    system("pause");
}
//实现一个 冒泡排序(目录)
int Student::sort(Student stu[], int& N)
{
    int key;//键盘输入操作号
    while (getchar() != '\n');                     //清空键盘缓冲区

    while (1)
    {
        system("cls");
        cout << "------------------" << endl;
        cout << "-----1.按学号排序-----" << endl;
        cout << "-----2.按姓名排序-----" << endl;
        cout << "-----3.退出本菜单-----" << endl;
        cout << "------------------" << endl;
        cout << "请选择子菜单学号:" << endl;
        cin >> key;
        switch (key)
        {
        case 1:sortByNumber(stu, N); break;
        case 2:sortByName(stu, N); break;
        case 3:return 0;
        default:break;
        }
    }
}
//实现一个 冒泡排序,按照学号顺序排序
int Student::sortByNumber(Student stu[], int& N)
{
    Student temp;
    for (int i = 0; i < N - 1; i++)//冒泡排序，按照拼音顺序排序
    {
        int mint = i;
        for (int j = i + 1; j < N; j++)
        {
            if (stu[j].number < stu[mint].number)mint = j;
        }
        if (mint != i)
        {
            temp = stu[i]; stu[i] = stu[mint]; stu[mint] = temp;
        }
    }
    cout << "排序后结果：" << endl;
    //	preTop();
    printInfor(stu, N);
    saveInformation(stu, N);
    return 1;//排序成功返回
}
//实现一个 冒泡排序,按照拼音顺序排序
int Student::sortByName(Student stu[], int& N)
{
    Student temp;
    for (int i = 0; i < N - 1; i++)//冒泡排序，按照拼音顺序排序
    {
        int mint = i;
        for (int j = i + 1; j < N; j++)
        {
            if (stu[j].name < stu[mint].name)mint = j;
        }
        if (mint != i)
        {
            temp = stu[i]; stu[i] = stu[mint]; stu[mint] = temp;
        }
    }
    cout << "排序后结果：" << endl;
    //	preTop();
    printInfor(stu, N);
    saveInformation(stu, N);
    return 1;//排序成功返回
}

//实现一个对数组的查找函数(目录)
int Student::search(Student stu[], int N)
{
    int key;//键盘输入操作号
    while (getchar() != '\n');                     //清空键盘缓冲区

    while (1)
    {
        system("cls");
        cout << "------------------" << endl;
        cout << "-----1.按学号查询-----" << endl;
        cout << "-----2.按姓名查询-----" << endl;
        cout << "-----3.退出本菜单-----" << endl;
        cout << "------------------" << endl;
        cout << "请选择子菜单学号:" << endl;
        cin >> key;
        switch (key)
        {
        case 1:cout << "请输入要查找学生的学号:" << endl; searchByNumber(stu, N); break;
        case 2:cout << "请输入要查找学生的姓名：" << endl; searchByName(stu, N); break;
        case 3:return 0;
        default:break;
        }
    }
}

//实现一个对数组的查找函数(通过学号)
int Student::searchByNumber(Student stu[], int N)
{
    string number;//键盘输入姓名
    int result;//返回搜索结果
    while (getchar() != '\n');                     //清空键盘缓冲区
    cin >> number;
    result = -1;
    for (int i = 0; i < N; i++)
    {
        if (number == stu[i].number)
        {
            result = i;
            break;
        }
    }

    if (result == -1)
    {//没找到个人信息
        cout << "没有找到该个人信息！" << endl;
        system("pause");
        return -1;
    }
    else //找到了个人信息则show出来
    {
        preTop();//界面函数
        stu[result].show();
        system("pause");
        return result;
    }
}

//实现一个对数组的查找函数(通过姓名)
int Student::searchByName(Student stu[], int N)
{
    string name;//键盘输入姓名
    int result;//返回搜索结果

    while (getchar() != '\n');                     //清空键盘缓冲区
    cin >> name;
    result = -1;
    for (int i = 0; i < N; i++)
    {
        if (name == stu[i].name)
        {
            result = i;
            break;
        }
    }

    if (result == -1)
    {//没找到个人信息
        cout << "没有找到该个人信息！" << endl;
        system("pause");
        return -1;
    }
    else //找到了个人信息则show出来
    {
        preTop();//界面函数
        stu[result].show();
        system("pause");
        return result;
    }
}

//实现一个对数组的编辑函数
int Student::edit(Student stu[], int& N)
{
    int result;//搜索结果
    char key; //key储存键盘输入操作号
    int year;
    int month;
    int day;
    string name;//姓名
    string id;//身份证号
    string number; //学号
    string sex;//性别
    float chinese;//语文成绩
    float math;//数学成绩
    float english;//英语成绩
    cout << "请输入需要编辑学生的姓名：" << endl;
    result = searchByName(stu, N);
    if (result >= 0)
    {
        system("cls");
        printf("您确认要修改吗?y-yes,n-no\n");
        while (getchar() != '\n');                     //清空键盘缓冲区
        cin >> key;
        if (key == 'y')
        {
            cout << "请重新输入该个人信息：" << endl;
            cout << "姓名：";
            cin >> name;
            cout << "身份证号：";
            cin >> id;
            cout << "学号：";
            cin >> number;
            cout << "出生年月日：";
            cin >> year >> month >> day;
            cout << "性别：";
            cin >> sex;
            cout << "语文：";
            cin >> chinese;
            cout << "数学：";
            cin >> math;
            cout << "英语：";
            cin >> english;
            stu[result].set(year, month, day, name, id, number, sex, chinese, math, english);
            cout << "修改完成，结果如下:" << endl;
            preTop();
            stu[result].show();
            saveInformation(stu, N);
            return 1;
        }
    }
    return 0;
}
//实现一个对数组的删除函数
int Student::del(Student stu[], int& N)
{
    int j;
    int  flag = 0;//是否删除成功的标志
    string s1;
    cout << "请输入要删除学生的姓名:";
    cin >> s1;
    for (int i = 0; i < N; i++)
        if (stu[i].name == s1)
        {
            flag = 1;
            for (j = i; j < N - 1; j++)
                stu[j] = stu[j + 1];
        }
    if (flag == 0)
        cout << "该学生不存在！" << endl;
    if (flag == 1)
    {
        cout << "删除成功,显示结果请选择菜单\n" << endl;
        N--;
        saveInformation(stu, N);
    }
    system("pause");
    return 1;//删除成功返回1
}
//int Student::count =0;
int main()
{
    Student stu[100];
    int N = 0;
    while (1)
    {
        system("cls");
        Student::readInformation(stu, N);
        Student::preMenu();
        int key;//key存储键盘输入的操作号
        cin >> key;
        switch (key)
        {
        case 1:Student::printInfor(stu, N); break;
        case 2:Student::addInfor(stu, N); break;
        case 3:Student::del(stu, N); break;
        case 4:Student::search(stu, N); break;
        case 5:Student::edit(stu, N); break;
        case 6:Student::sort(stu, N); break;
        case 7:return 0;
        default:break;
        }
    }

    return 0;
}