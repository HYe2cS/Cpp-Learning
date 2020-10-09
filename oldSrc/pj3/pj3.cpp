#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[10];
	long long num; //电话号码
	char email[20];
	char addr[15];
} STU;

int Read(STU stu[], int& N)
{
	FILE* fp1, * fp2;
	int i;

	char filename[20] = { "stu.txt" }, numfile[20] = { "num.txt" };
	if ((fp1 = fopen(filename, "r+")) == NULL)
		if ((fp1 = fopen(filename, "w+")) == NULL)
		{
			printf("无法打开此文件!\n");
			exit(0);
		}
	if ((fp2 = fopen(numfile, "r+")) == NULL)
		if ((fp1 = fopen(filename, "w+")) == NULL)
		{
			printf("无法打开此文件!\n");
			exit(0);
		}

	fscanf(fp2, "%d", &N);
	for (i = 0; i < N; i++)
		fscanf(fp1, "%s\t%lld\t%s\t%s\n", &stu[i].name, &stu[i].num, &stu[i].email, &stu[i].addr);
	fclose(fp1);
	fclose(fp2);
	return 1;
}

void Save(STU stu[], int N)
{
	FILE* fp1, * fp2;
	int i;
	char filename[20] = { "stu.txt" }, numfile[20] = { "num.txt" };;
	printf("文本文件名为：%s\n", filename);

	if ((fp1 = fopen(filename, "w+")) == NULL)
	{
		printf("无法打开此文件!\n");
		exit(0);
	}
	if ((fp2 = fopen(numfile, "w+")) == NULL)
	{
		printf("无法打开此文件!\n");
		exit(0);
	}
	for (i = 0; i < N; i++)
	{
		fprintf(fp1, "%s\t%lld\t%s\t%s\n",
			stu[i].name, stu[i].num, stu[i].email, stu[i].addr);
	}
	fprintf(fp2, "%d", N);
	fclose(fp1);
	fclose(fp2);
	printf("保存完毕！\n");
	system("pause");
}
void Pre_top()
{
	printf("姓名\t\t电话号码\t电子邮箱\t\t地址\n");
}
void Pre_title()          //打印标题
{
	printf("-------------------------------------------------\n");
	printf("|\t\t欢迎使用学生信息管理系统\t|\n");
	printf("|\t1：输出所有数据\t\t2.增加学生数据\t|\n");
	printf("|\t3：删除学生数据\t\t4.编辑学生数据\t|\n");
	printf("|\t5：排序所有数据\t\t6.查询学生数据\t|\n");
	printf("|\t7.退出                           \t|\n");
	printf("-------------------------------------------------\n");
	printf("请输入操作序号:");
}

int Print(STU stu[], int N)     //输出全部记录数据
{
	int i;
	if (N)Pre_top();
	for (i = 0; i < N; i++)
		printf("%-10s\t%-12lld\t%-20s\t%-15s\n", stu[i].name, stu[i].num, stu[i].email, stu[i].addr);
	//Prt(stu[i]);
	printf("全部输出完成!\n");
	system("pause");
	return 1;
}
int Sort(STU stu[], int N)
{
	int i, j, maxt;
	STU temp;
	for (i = 0; i < N - 1; i++)
	{
		maxt = i;
		for (j = i + 1; j < N; j++)
		{
			if (strcmp(stu[j].name, stu[maxt].name) < 0)maxt = j;
		}

		if (maxt != i)
		{
			temp = stu[i]; stu[i] = stu[maxt]; stu[maxt] = temp;
		}
	}
	printf("排序后结果：\n");
	Print(stu, N);
	Save(stu, N);
	return 1;
}

int Search(STU stu[], int N)
{
	char name[10];
	int result;
	int i;
	while (getchar() != '\n');                     //清空键盘缓冲区
	scanf("%s", &name);
	result = -1;
	for (i = 0; i < N; i++)
	{
		if (strcmp(name, stu[i].name) == 0)
		{
			result = i;
			break;
		}
	}
	if (result == -1)
	{//没找到学生信息
		printf("没有找到该学生信息！\n");
		system("pause");
		return -1;
	}
	else
	{
		Pre_top();
		printf("%-10s\t%-12lld\t%-20s\t%-15s\n", stu[result].name, stu[result].num, stu[result].email, stu[result].addr);
		//	Prt(stu[result]);
		system("pause");
		return result;
	}
}
int Del(STU stu[], int N)//按照姓名删除
{
	int result;
	char key;
	int i;
	result = Search(stu, N);
	if (result >= 0)
	{
		system("cls");
		printf("您确认要删除吗?y-yes,n-no\n");
		while (getchar() != '\n');                     //清空键盘缓冲区
		scanf("%c", &key);
		if (key == 'y')
		{
			for (i = result; i < N - 1; i++)
				stu[i] = stu[i + 1];
			N--;
			printf("删除完成！\n");
			Save(stu, N);
		}
	}
	return 1;
}

int Edit(STU stu[], int N)
{
	int result;
	char key;
	result = Search(stu, N);
	if (result >= 0)
	{
		system("cls");
		printf("您确认要修改吗?y-yes,n-no\n");
		while (getchar() != '\n');                     //清空键盘缓冲区
		scanf("%c", &key);
		if (key == 'y')
		{
			printf("请重新输入该学生信息：\n请输入姓名：");
			while (getchar() != '\n');                     //清空键盘缓冲区
			scanf("%s", &stu[result].name);
			printf("请输入电话号码：");
			while (getchar() != '\n');                     //清空键盘缓冲区
			scanf("%lld", &stu[result].num);
			printf("请输入Email：");
			while (getchar() != '\n');                     //清空键盘缓冲区
			scanf("%s", &stu[result].email);
			printf("请输入家庭住址：");
			while (getchar() != '\n');                     //清空键盘缓冲区
			scanf("%s", &stu[result].addr);
			Save(stu, N);
			return 1;
		}
	}
	return 0;
}
void Add(STU stu[], int N)
{
	int i, k;
	int j = 1;
	printf("要添加的人数(整数)：");
	while (getchar() != '\n');                     //清空键盘缓冲区
	scanf("%d", &k);//输入数据
	for (i = N; i < N + k; i++)
	{
		printf("请输入第%d位学生信息\n", j);
		j++;
		printf("请输入姓名：");
		while (getchar() != '\n');                     //清空键盘缓冲区
		scanf("%s", &stu[i].name);
		printf("请输入电话号码：");
		while (getchar() != '\n');                     //清空键盘缓冲区
		scanf("%lld", &stu[i].num);
		printf("请输入Email：");
		while (getchar() != '\n');                     //清空键盘缓冲区
		scanf("%s", &stu[i].email);
		printf("请输入家庭住址：");
		while (getchar() != '\n');                     //清空键盘缓冲区
		scanf("%s", &stu[i].addr);
	}
	N = N + k;
	Save(stu, N);
}

int main()
{
	int N = 0, key;
	STU stu[100];
	while (1)
	{
		system("cls");
		Pre_title();
		scanf("%d", &key);
		Read(stu, N);
		//		printf("%d",N);
		switch (key)
		{
		case 1:Print(stu, N); break;
		case 2:	Add(stu, N); break;
		case 3:	printf("请输入欲删除的姓名："); Del(stu, N); break;
		case 4:	printf("请输入欲编辑的姓名："); Edit(stu, N); break;
		case 5:Sort(stu, N); break;
		case 6:	printf("请输入欲查找人的姓名："); Search(stu, N); break;
		case 7:system("pause"); return 0;
		default:break;
		}
	}
}