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
	string rank;//等级
	int frequency;//频率
	float voltage;//电压
};
CPU::CPU()
{
	cout << "构造一个CPU" << endl;
}
CPU::CPU(string r, int f, float v)
{
	cout << "构造一个CPU" << endl;
	rank = r;
	frequency = f;
	voltage = v;
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
/**/
//*****************************三个set函数
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
	cout << "CPU开始运行！" << endl;
}
void CPU::Stop()
{
	cout << "CPU停止运行！" << endl;
}
int main()
{
	CPU cpu1;
	cpu1.SetRank("P1");
	cpu1.SetFrequency(3000);
	cpu1.SetVoltage(220);
	cpu1.Run();
	cout << "cpu1的等级是:" << cpu1.GetRank() << endl;
	cout << "cpu1的频率是:" << cpu1.GetFrequency() << endl;
	cout << "cpu1的电压是:" << cpu1.GetVoltage() << endl;
	cpu1.Stop();
	return 0;
}