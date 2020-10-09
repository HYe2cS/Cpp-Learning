/*
完成成绩输入（包括语文，数学，英语三门课）；
计算总分并排名
计算各科平均分
统计各科不及格的学生人数并输出不及格的学生的详细信息
将输入的学生信息及分析的数据存入磁盘文件
*/
#include<stdio.h>
#define N 3
struct student {
	int num;
	char name[20];
	int yuwen;
	int shuxue;
	int yingyu;
	int total;
};
typedef struct student STU;
void input_info(STU* s, int n)
{
	STU* p;
	printf("输入学生学号与姓名信息：\n");
	for (p = s; p < s + n; p++)
		scanf("%d%s", &p->num, &p->name);
}
void input_score(STU* s, int n)
{
	STU* p;
	printf("输入学生语文、数学、英语成绩：\n");
	for (p = s; p < s + n; p++)
	{
		printf("%d %s:", p->num, p->name);
		scanf("%d%d%d", &p->yuwen, &p->shuxue, &p->yingyu);
		p->total = p->yuwen + p->shuxue + p->yingyu;
	}
}
void output(STU* s, int n, FILE* fp)
{
	STU* p;
	printf("输出学生学号、姓名、语文、数学、英语、总分\n");
	fprintf(fp, "输出学生学号、姓名、语文、数学、英语、总分\n");
	for (p = s; p < s + n; p++)
	{
		printf("%d %9s %4d %4d %4d %4d\n", p->num, p->name, p->yuwen, p->shuxue, p->yingyu, p->total);
		fprintf(fp, "%d %9s %4d %4d %4d %4d\n", p->num, p->name, p->yuwen, p->shuxue, p->yingyu, p->total);
	}
}
void sort(STU* s, int n)
{
	STU t;
	int i, j, max;
	for (i = 0; i < n - 1; i++)
	{
		max = i;
		for (j = i + 1; j < n; j++)
		{
			if (s[j].total > s[max].total)max = j;
		}
		if (max != i)
		{
			t = s[max];
			s[max] = s[i];
			s[i] = t;
		}
	}
}
void avg_cnt(STU* s, int n, FILE* fp)
{
	STU* p;
	float avg_yuwen = 0, avg_shuxue = 0, avg_yingyu = 0;
	int cnt_yuwen = 0, cnt_shuxue = 0, cnt_yingyu = 0;
	printf("输出不及格学生学号、姓名、语文、数学、英语、总分：\n");
	fprintf(fp, "输出不及格学生学号、姓名、语文、数学、英语、总分：\n");
	for (p = s; p < s + n; p++)
	{
		avg_yuwen += p->yuwen; avg_shuxue += p->shuxue; avg_yingyu += p->yingyu;
		if (p->yuwen < 60)cnt_yuwen++;
		if (p->shuxue < 60)cnt_shuxue++;
		if (p->yingyu < 60)cnt_yingyu++;
		if (p->yuwen < 60 || p->shuxue < 60 || p->yingyu < 60)
			printf("%d %9s %4d %4d %4d %4d\n", p->num, p->name, p->yuwen, p->shuxue, p->yingyu, p->total);
		fprintf(fp, "%d %9s %4d %4d %4d %4d\n", p->num, p->name, p->yuwen, p->shuxue, p->yingyu, p->total);
	}
	printf("语文平均分：%.1f\n", avg_yuwen / n);
	printf("数学平均分：%.1f\n", avg_shuxue / n);
	printf("英语平均分：%.1f\n", avg_yingyu / n);
	printf("语文不及格人数：%d\n", cnt_yuwen);
	printf("数学不及格人数：%d\n", cnt_shuxue);
	printf("英语不及格人数：%d\n", cnt_yingyu);
	fprintf(fp, "语文平均分：%.1f\n", avg_yuwen / n);
	fprintf(fp, "数学平均分：%.1f\n", avg_shuxue / n);
	fprintf(fp, "英语平均分：%.1f\n", avg_yingyu / n);
	fprintf(fp, "语文不及格人数：%d\n", cnt_yuwen);
	fprintf(fp, "数学不及格人数：%d\n", cnt_shuxue);
	fprintf(fp, "英语不及格人数：%d\n", cnt_yingyu);
}
int main()
{
	STU s[N];
	FILE* fp;
	fp = fopen("d:\\stud.txt", "w");
	input_info(s, N);
	input_score(s, N);
	sort(s, N);
	output(s, N, fp);
	avg_cnt(s, N, fp);
	fclose(fp);
	return 0;
}