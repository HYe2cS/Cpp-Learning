//�����ܷ�Թ��еĶ����Ա��˽�еĶ����Ա������ʱ��ʼ��
#include<iostream>
using namespace std;
class test {
	int a1 = 0; //����д����c++11�Ժ�ű�����
public:
	int b1 = 3;//���ֳ�ʼ����д����c++11�Ժ�ű�����
	int b2;
}b2;
int main() {
	test t1;
	t1.b1 = 2;
	t1.b2 = 2;
	cout << t1.b1 << endl;
	cout << t1.b2 << endl;
}