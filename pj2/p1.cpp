/*项目三 通讯录管理系统的设计          16学时
问题描述：设计一个操作简便、功能实用的个人通信信息管理系统。
1．基本要求
（1）存储内容：姓名、手机、家庭电话、办公电话、电子邮箱、地址等信息；
（2）具备创建、添加、删除、查询、修改、排序、显示等功能；
（3）界面美观、操作简便。
2．重点、难点
重点：结构体数组的增、删、改、查等操作。
难点：文件的读写操作。
*/
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int DataType;
struct Student
{
	char name[10];
	int phonenum;
	int homenum;
	int worknum;
	char email[20];
	char address[80];
} Info;

int Insert(Info& L, int i, DataType x)//插入运算
{
	int j;
	if (L.length == MAXSIZE)
	{
		printf("\n表满!");
		exit(1);
	}
	if (i<1 || i>L.length + 1)
	{
		printf("\n指定插入的位置不存在!");
		exit(1);
	}
	for (j = L.length - 1; j >= i - 1; j--)
}
void Delete(Information& S, int i)
{
}
int ChaXun()
{}
int Operate()
{}
int PaiXu()
{}
int Display()
{}

int JudgeNumorName()
{}

int main()
{
	int key = 0;
	Information S[1];
	printf("\t--------------------------------------------\n");
	printf("\t-----------欢迎使用通讯录管理系统-----------\n");
	printf("\t--------------------------------------------\n");
	printf("\n");
	printf("\t***********按下数字键使用对应功能***********\n");
	while (key != -1)
	{
		scanf("%d", &key);
		switch (key)
		{
			//		case 1:ChuangJian();break;
		case 1:TianJia(S); break;
		case 2:Delete(); break;
		case 3:ChaXun(); break;
		case 4:Operate(); break;
		case 5:Display(); break;
		}
	}
	//	S[0].num=-1;
	return 0;
}