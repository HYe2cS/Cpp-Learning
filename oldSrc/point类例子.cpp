#include<iostream>
using namespace std;
#include<math.h>
//��point
class point {
public:
	point(double x1 = 0.0, double y1 = 0.0);
	//point(){}
	//point(double x1,double y1);
	//��Ĭ��ֵ�ĺ͹��캯�������صȼ۵�����ͬʱʹ��
	void show();
	~point() { cout << "Dstructing" << endl; }
	int getx() { return x; }
	int gety() { return y; }
	//�������캯��
	point(point& opx) { x = 2 * opx.x; y = 2 * opx.y; ++count; }
	//��̬��Ա��������̬���ݳ�Ա
	static void shoucount() { cout << "�ܵ���:" << count << endl; }
private:
	double x, y;
	static int count;
};

//���ⶨ���Ա����
//���ڳ������ͺ��������ͱ���ʹ�ó�Ա��ʼ���б�ʽ
point::point(double x1, double y1) :x(x1)
{
	y = y1;
	++count;
}
//��Ĭ��ֵ��������ʱ���Ĭ��ֵ�������ʱ��Ͳ���Ҫ
//��ͨ��Ա����
void point::show()
{
	cout << "x������Ϊ:" << x << "," << "y������Ϊ:" << y << endl;
}
//������Ϊ�������д���
void distance1(point& p1, point& p2)
{
	cout << "����Ϊ:" << sqrt(((p1.getx() - p2.getx()) * (p1.getx() - p2.getx())) +
		((p1.gety() - p2.gety()) * (p1.gety() - p2.gety()))) << endl;
}

int point::count = 0;

int main()
{
	//��Ķ����ָ��
	cout << "��Ķ����ָ��****************************" << endl;
	point p1(2.1, 3.2);
	p1.show();

	point p2;
	p2.show();

	point* p = &p1;
	p->show();
	(*p).show();

	point* px = new point(3.4, 5.2);
	px->show();
	(*px).show();
	delete px;
	//��new����������Ķ�����delete�����ͷŵ�ʱ��������������
	//��������Ͷ���ָ��
	cout << "��������****************************" << endl;
	point ob[3];
	//��������ob[0]��ob[1]��ob[2]
	for (int i = 0; i < 3; i++)
		ob[i].show();
	point* pp = ob;
	for (i = 0; i < 3; i++)
	{
		pp->show();
		pp++;
	}
	point os[3] = { point(4.1,2.3),point(5.3,6.1),point(7.2,4.3) };
	for (int j = 0; j < 3; j++)
		os[j].show();
	point* pps = os;
	for (j = 0; j < 3; j++)
	{
		pps->show();
		pps++;
	}
	cout << "����******************************" << endl;
	//�������������ĵ�
	point ss1(5.3, 4.2), ss2(2.1, 3.2);

	distance1(ss1, ss2);
	//�������캯��
	cout << "�������캯��*********************" << endl;
	p2 = p1;//��Ĭ�ϸ�ֵ�����
	point p3 = p1;
	point p4;
	p4 = p1;
	p3.show();
	p4.show();
	cout << "�ܵ���:********************************" << endl;
	point::shoucount();

	return 0;
}