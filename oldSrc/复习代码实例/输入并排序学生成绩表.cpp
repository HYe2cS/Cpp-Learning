/*
2、一个结构体类型为struct student，它的成员为char name[20],int score。
编程可输入一个班的学生姓名和成绩[班级的人数不定]，并按成绩高到低排序输出。
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
	printf("输出学生姓名、成绩到文本文件\n");
	for (p = s; p < s + n; p++)
		fprintf(fp, "%9s%5d\n", p->name, p->score);
	fclose(fp);
}
int main()
{
	int n, i, j, max;
	printf("请输入班级的人数：");
	scanf("%d", &n);
	struct student stu[n], t;
	printf("请输入学生的姓名和成绩：\n");
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