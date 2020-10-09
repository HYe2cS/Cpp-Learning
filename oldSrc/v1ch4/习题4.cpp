#include<iostream>
using namespace std;
class CBuilding {
public:
	CBuilding(int bu, int ro, int ar)
	{
		Build = bu;
		Room = ro;
		Area = ar;
	}
	show()
	{
		cout << "¥������Ϊ" << Build << ",������Ϊ" << Room << ",�����Ϊ" << Area << endl;
	}
protected:
	int Build;//¥������
	int Room;//������
	float Area;//�����
};
class CHousing :public CBuilding {
public:
	CHousing(int bed, int bath, int bu, int ro, int ar) :CBuilding(bu, ro, ar)
	{
		BedRoom = bed;
		BathRoom = bath;
	}
	show()
	{
		CBuilding::show();
		cout << "��������Ϊ" << BedRoom << ",ԡ������Ϊ" << BathRoom << endl;
	}
private:
	int BedRoom;//��������
	int BathRoom;//ԡ������
};
class COfficBuilding :public CBuilding {
public:
	COfficBuilding(int IF, int ph, int bu, int ro, int ar) :CBuilding(bu, ro, ar)
	{
		InFire = IF;
		Phone = ph;
	}
	show()
	{
		CBuilding::show();
		cout << "���������Ϊ" << InFire << ",�绰����Ϊ" << Phone << endl;
	}
private:
	int InFire;//���������
	int Phone;//�绰����
};
int main()
{
	CHousing ch(3, 4, 5, 6, 7);
	ch.show();
	COfficBuilding cb(3, 4, 5, 6, 7);
	cb.show();
	return 0;
}