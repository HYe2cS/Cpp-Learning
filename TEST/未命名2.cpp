#include<iostream>
#include<string>
using namespace std;
class CPU {
public:
	CPU(string r = "P0", int f = 0, float v = 0);
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
	string rank;//�ȼ�
	int frequency;//Ƶ��
	float voltage;//��ѹ
};
CPU::CPU()
{
	cout << "����һ��CPU" << endl;
}
CPU::CPU(string r, int f, float v)
{
	cout << "����һ��CPU" << endl;
	rank = r;
	frequency = f;
	voltage = v;
}
CPU::~CPU()
{
	cout << "����һ��CPU" << endl;
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
/**/
//*****************************����set����
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
//******************************************
void CPU::Run()
{
	cout << "CPU��ʼ���У�" << endl;
}
void CPU::Stop()
{
	cout << "CPUֹͣ���У�" << endl;
}
int main()
{
	CPU cpu1;
	cpu1.SetRank("P1");
	cpu1.SetFrequency(3000);
	cpu1.SetVoltage(220);
	cpu1.Run();
	cout << "cpu1�ĵȼ���:" << cpu1.GetRank() << endl;
	cout << "cpu1��Ƶ����:" << cpu1.GetFrequency() << endl;
	cout << "cpu1�ĵ�ѹ��:" << cpu1.GetVoltage() << endl;
	cpu1.Stop();
	return 0;
}