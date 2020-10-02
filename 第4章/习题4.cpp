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
		cout << "楼房层数为" << Build << ",房间数为" << Room << ",总面积为" << Area << endl;
	}
protected:
	int Build;//楼房层数
	int Room;//房间数
	float Area;//总面积
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
		cout << "卧室数量为" << BedRoom << ",浴室数量为" << BathRoom << endl;
	}
private:
	int BedRoom;//卧室数量
	int BathRoom;//浴室数量
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
		cout << "灭火器数量为" << InFire << ",电话数量为" << Phone << endl;
	}
private:
	int InFire;//灭火器数量
	int Phone;//电话数量
};
int main()
{
	CHousing ch(3, 4, 5, 6, 7);
	ch.show();
	COfficBuilding cb(3, 4, 5, 6, 7);
	cb.show();
	return 0;
}