#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[10];
	long long num; //�绰����
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
			printf("�޷��򿪴��ļ�!\n");
			exit(0);
		}
	if ((fp2 = fopen(numfile, "r+")) == NULL)
		if ((fp1 = fopen(filename, "w+")) == NULL)
		{
			printf("�޷��򿪴��ļ�!\n");
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
	printf("�ı��ļ���Ϊ��%s\n", filename);

	if ((fp1 = fopen(filename, "w+")) == NULL)
	{
		printf("�޷��򿪴��ļ�!\n");
		exit(0);
	}
	if ((fp2 = fopen(numfile, "w+")) == NULL)
	{
		printf("�޷��򿪴��ļ�!\n");
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
	printf("������ϣ�\n");
	system("pause");
}
void Pre_top()
{
	printf("����\t\t�绰����\t��������\t\t��ַ\n");
}
void Pre_title()          //��ӡ����
{
	printf("-------------------------------------------------\n");
	printf("|\t\t��ӭʹ��ѧ����Ϣ����ϵͳ\t|\n");
	printf("|\t1�������������\t\t2.����ѧ������\t|\n");
	printf("|\t3��ɾ��ѧ������\t\t4.�༭ѧ������\t|\n");
	printf("|\t5��������������\t\t6.��ѯѧ������\t|\n");
	printf("|\t7.�˳�                           \t|\n");
	printf("-------------------------------------------------\n");
	printf("������������:");
}

int Print(STU stu[], int N)     //���ȫ����¼����
{
	int i;
	if (N)Pre_top();
	for (i = 0; i < N; i++)
		printf("%-10s\t%-12lld\t%-20s\t%-15s\n", stu[i].name, stu[i].num, stu[i].email, stu[i].addr);
	//Prt(stu[i]);
	printf("ȫ��������!\n");
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
	printf("���������\n");
	Print(stu, N);
	Save(stu, N);
	return 1;
}

int Search(STU stu[], int N)
{
	char name[10];
	int result;
	int i;
	while (getchar() != '\n');                     //��ռ��̻�����
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
	{//û�ҵ�ѧ����Ϣ
		printf("û���ҵ���ѧ����Ϣ��\n");
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
int Del(STU stu[], int N)//��������ɾ��
{
	int result;
	char key;
	int i;
	result = Search(stu, N);
	if (result >= 0)
	{
		system("cls");
		printf("��ȷ��Ҫɾ����?y-yes,n-no\n");
		while (getchar() != '\n');                     //��ռ��̻�����
		scanf("%c", &key);
		if (key == 'y')
		{
			for (i = result; i < N - 1; i++)
				stu[i] = stu[i + 1];
			N--;
			printf("ɾ����ɣ�\n");
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
		printf("��ȷ��Ҫ�޸���?y-yes,n-no\n");
		while (getchar() != '\n');                     //��ռ��̻�����
		scanf("%c", &key);
		if (key == 'y')
		{
			printf("�����������ѧ����Ϣ��\n������������");
			while (getchar() != '\n');                     //��ռ��̻�����
			scanf("%s", &stu[result].name);
			printf("������绰���룺");
			while (getchar() != '\n');                     //��ռ��̻�����
			scanf("%lld", &stu[result].num);
			printf("������Email��");
			while (getchar() != '\n');                     //��ռ��̻�����
			scanf("%s", &stu[result].email);
			printf("�������ͥסַ��");
			while (getchar() != '\n');                     //��ռ��̻�����
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
	printf("Ҫ��ӵ�����(����)��");
	while (getchar() != '\n');                     //��ռ��̻�����
	scanf("%d", &k);//��������
	for (i = N; i < N + k; i++)
	{
		printf("�������%dλѧ����Ϣ\n", j);
		j++;
		printf("������������");
		while (getchar() != '\n');                     //��ռ��̻�����
		scanf("%s", &stu[i].name);
		printf("������绰���룺");
		while (getchar() != '\n');                     //��ռ��̻�����
		scanf("%lld", &stu[i].num);
		printf("������Email��");
		while (getchar() != '\n');                     //��ռ��̻�����
		scanf("%s", &stu[i].email);
		printf("�������ͥסַ��");
		while (getchar() != '\n');                     //��ռ��̻�����
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
		case 3:	printf("��������ɾ����������"); Del(stu, N); break;
		case 4:	printf("���������༭��������"); Edit(stu, N); break;
		case 5:Sort(stu, N); break;
		case 6:	printf("�������������˵�������"); Search(stu, N); break;
		case 7:system("pause"); return 0;
		default:break;
		}
	}
}