/*��Ŀ�� ͨѶ¼����ϵͳ�����          16ѧʱ
�������������һ��������㡢����ʵ�õĸ���ͨ����Ϣ����ϵͳ��
1������Ҫ��
��1���洢���ݣ��������ֻ�����ͥ�绰���칫�绰���������䡢��ַ����Ϣ��
��2���߱���������ӡ�ɾ������ѯ���޸ġ�������ʾ�ȹ��ܣ�
��3���������ۡ�������㡣
2���ص㡢�ѵ�
�ص㣺�ṹ�����������ɾ���ġ���Ȳ�����
�ѵ㣺�ļ��Ķ�д������
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

int Insert(Info& L, int i, DataType x)//��������
{
	int j;
	if (L.length == MAXSIZE)
	{
		printf("\n����!");
		exit(1);
	}
	if (i<1 || i>L.length + 1)
	{
		printf("\nָ�������λ�ò�����!");
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
	printf("\t-----------��ӭʹ��ͨѶ¼����ϵͳ-----------\n");
	printf("\t--------------------------------------------\n");
	printf("\n");
	printf("\t***********�������ּ�ʹ�ö�Ӧ����***********\n");
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