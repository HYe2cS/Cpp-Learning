#include<iostream>
#include<string>
using namespace std;
class CPublication {
protected:
    string title;//标题
    float coat;//价格
public:
    CPublication(string ti, float co) {
        title = ti;
        coat = co;
    }
    GetData() {
        cout << "标题:";
        cin >> title;
        cout << "价格:";
        cin >> coat;
    }
    PutData() {
        cout << "标题:" << title << endl << "价格:" << coat << endl;
    }
};
class CBook :public CPublication {
public:
    CBook(string ti, float co, int ty) :CPublication(ti, co) {
        type = ty;
    }
    GetData() {
        CPublication::GetData();
        cout << "页数:";
        cin >> type;
    }
    PutData() {
        CPublication::PutData();
        cout << "页数" << type << endl;
    }
private:
    int type; //页数
};
class CTape :public CPublication {
public:
    CTape(string ti, float co, float mi) :CPublication(ti, co) {
        minutes = mi;
    }
    GetData() {
        CPublication::GetData();
        cout << "播放时间:";
        cin >> minutes;
    }
    PutData() {
        CPublication::PutData();
        cout << "播放时间:" << minutes << endl;
    }
private:
    float minutes;
};
int main() {
    CBook cb("少年pi", 33.42, 236);
    cb.GetData();
    cb.PutData();
    cout << "===================================" << endl;
    CTape ct("少年pi", 33.42, 2362);
    ct.GetData();
    ct.PutData();
    return 0;
}