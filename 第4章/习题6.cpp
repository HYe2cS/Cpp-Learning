#include<iostream>
#include<string>
using namespace std;
class CPublication {
protected:
	string title;//����
	float coat;//�۸�
public:
	CPublication(string ti, float co) {
		title = ti;
		coat = co;
	}
	GetData() {
		cout << "����:";
		cin >> title;
		cout << "�۸�:";
		cin >> coat;
	}
	PutData() {
		cout << "����:" << title << endl << "�۸�:" << coat << endl;
	}
};
class CBook :public CPublication {
public:
	CBook(string ti, float co, int ty) :CPublication(ti, co) {
		type = ty;
	}
	GetData() {
		CPublication::GetData();
		cout << "ҳ��:";
		cin >> type;
	}
	PutData() {
		CPublication::PutData();
		cout << "ҳ��" << type << endl;
	}
private:
	int type; //ҳ��
};
class CTape :public CPublication {
public:
	CTape(string ti, float co, float mi) :CPublication(ti, co) {
		minutes = mi;
	}
	GetData() {
		CPublication::GetData();
		cout << "����ʱ��:";
		cin >> minutes;
	}
	PutData() {
		CPublication::PutData();
		cout << "����ʱ��:" << minutes << endl;
	}
private:
	float minutes;
};
int main() {
	CBook cb("����pi", 33.42, 236);
	cb.GetData();
	cb.PutData();
	cout << "===================================" << endl;
	CTape ct("����pi", 33.42, 2362);
	ct.GetData();
	ct.PutData();
	return 0;
}