/*
2��һ���ṹ������Ϊstruct student�����ĳ�ԱΪchar name[20],int score��
��̿�����һ�����ѧ�������ͳɼ�[�༶����������]�������ɼ��ߵ������������
*/
#include<stdio.h>
struct student {
	char name[20];
	int score;
};
void output(struct student* s, int n)
{
	FILE* fp;
	/*
		if((fp=fopen("stu.txt","w"))==NULL)
		{
			printf("cannot open flie");
			exit(0);
		}
	*/
	fp = fopen("stu.txt", "w");
	struct student* p;
	printf("���ѧ���������ɼ����ı��ļ�\n");
	for (p = s; p < s + n; p++)
		fprintf(fp, "%9s%5d\n", p->name, p->score);
	fclose(fp);
}
int main()
{
	int n, i, j, max;
	printf("������༶��������");
	scanf("%d", &n);
	struct student stu[n], t;
	printf("������ѧ���������ͳɼ���\n");
	//inpout
	for (i = 0; i < n; i++)
	{
		scanf("%s%d", &stu[i].name, &stu[i].score);
	}
	//sort
	for (i = 0; i < n - 1; i++)
	{
		max = i;
		for (j = i + 1; j < n; j++)
		{
			if (stu[j].score > stu[max].score)max = j;
		}
		if (max != i)
		{
			t = stu[max];
			stu[max] = stu[i];
			stu[i] = t;
		}
	}
	//output
	for (i = 0; i < n; i++)
	{
		printf("%9s%5d\n", stu[i].name, stu[i].score);
	}
	//ouput to stu
	output(stu, n);
	return 0;
}