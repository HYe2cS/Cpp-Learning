#include<iostream>
#include<string>
using namespace std;
class time;
class date {
public:
    date();
    date(int y, int m, int d);
    friend void show(date& dx, time& tx);
private:
    int year, month, day;
};

date::date() { cout << "不带参数的构造函数" << endl; }

date::date(int y, int m, int d) :day(d)
{
    year = y;
    month = m;
}

class time {
public:
    time(int ho, int mi, int se)
    {
        hour = ho;
        miniter = mi;
        second = se;
    }
    friend void show(date& dx, time& tx);
private:
    int hour;
    int miniter;
    int second;
};

void show(date& dx, time& tx)
{
    cout << dx.year << "-" << dx.month << endl;
    cout << tx.hour << ":" << tx.miniter << endl;
}

int main()
{
    date d1(2019, 12, 13);
    time t1(14, 42, 20);
    show(d1, t1);
    return 0;
}