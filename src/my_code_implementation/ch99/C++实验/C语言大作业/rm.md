淮北师范大学电子版实验报告
姓名	张元节	学号	20181251215	实验日期	2019.1.4	成绩
学院	计算机科学与技术学院	班级	2018级计算机大类三班	实验场地	文源楼A207	
实验课程名称	高级语言程序设计	
实验项目名称	实验8、综合设计	
对于每一个实验项目，实验报告（含预习）一般应包含以下内容：
第一部分——预习后的书面汇报。其主要内容应包含：*1、实验目的；*2、实验内容。
第二部分——实验结果的书面汇报。其主要内容应包含： *3、实验源代码；*4、实验结果及分析（含实验测试输入数据，试验运行结果截图，用简洁的语言总结实验，汇报是否达到实验目的）；*5、实验体会、问题讨论（谈体会或感想、提出建议或意见、讨论与实验有关的且自己感兴趣的问题、回答课后思考题）。
要求：实验报告完成后将文件名命名为：学号-姓名-实验X报告.doc，如：20181209099-张三丰-实验1报告.doc，然后统一上缴或上传至实验报告系统。
一、实验目的
使学生掌握编写应用程序的方法，掌握使用C语言开发一个简单应用系统的方法和步骤，了解系统和项目的规划和设计，程序的调试等过程。
二、实验内容
1.
完成成绩输入（包括语文，数学，英语三门课）；
计算总分并排名
计算各科平均分
统计各科不及格的学生人数并输出不及格的学生的详细信息
将输入的学生信息及分析的数据存入磁盘文件
三、实验源程序（或实验步骤）
1. 程序编写如下:
#include<stdio.h>
#define N 3
struct student{
	int num;
	char name[20];
	int yuwen;
	int shuxue;
	int yingyu;
	int total;
};
typedef struct student STU;
void input_info(STU *s,int n)
{
	STU *p;
	printf("输入学生学号与姓名信息：\n");
	for(p=s;p<s+n;p++)
		scanf("%d%s",&p->num,&p->name);
}
void input_score(STU *s,int n)
{
	STU *p;
	printf("输入学生语文、数学、英语成绩：\n");
	for(p=s;p<s+n;p++)
	{
		printf("%d %s:",p->num,p->name);
		scanf("%d%d%d",&p->yuwen,&p->shuxue,&p->yingyu);
		p->total=p->yuwen+p->shuxue+p->yingyu;
	}
}
void output(STU *s,int n,FILE *fp)
{
	STU *p;
	printf("输出学生学号、姓名、语文、数学、英语、总分\n");
	fprintf(fp,"输出学生学号、姓名、语文、数学、英语、总分\n");
	for(p=s;p<s+n;p++)
	{
		printf("%d %9s %4d %4d %4d %4d\n",p->num,p->name,p->yuwen,p->shuxue,p->yingyu,p->total);
		fprintf(fp,"%d %9s %4d %4d %4d %4d\n",p->num,p->name,p->yuwen,p->shuxue,p->yingyu,p->total);
	}
}
void sort(STU *s,int n)
{
	STU t;
	int i,j,max;
	for(i=0;i<n-1;i++)
	{
		max=i;
		for(j=i+1;j<n;j++)
		{
			if(s[j].total>s[max].total)max=j;
		}
		if(max!=i)
		{
			t=s[max];
			s[max]=s[i];
			s[i]=t;
		}
	}
}
void avg_cnt(STU *s,int n,FILE *fp)
{
	STU *p;
	float avg_yuwen=0,avg_shuxue=0,avg_yingyu=0;
	int cnt_yuwen=0,cnt_shuxue=0,cnt_yingyu=0;
	printf("输出不及格学生学号、姓名、语文、数学、英语、总分：\n");
	fprintf(fp,"输出不及格学生学号、姓名、语文、数学、英语、总分：\n");
	for(p=s;p<s+n;p++)
	{
		avg_yuwen+=p->yuwen;avg_shuxue+=p->shuxue;avg_yingyu+=p->yingyu;
		if(p->yuwen<60)cnt_yuwen++;
		if(p->shuxue<60)cnt_shuxue++;
		if(p->yingyu<60)cnt_yingyu++;
		if(p->yuwen<60||p->shuxue<60||p->yingyu<60)
			printf("%d %9s %4d %4d %4d %4d\n",p->num,p->name,p->yuwen,p->shuxue,p->yingyu,p->total);
			fprintf(fp,"%d %9s %4d %4d %4d %4d\n",p->num,p->name,p->yuwen,p->shuxue,p->yingyu,p->total);
	}
	printf("语文平均分：%.1f\n",avg_yuwen/n);
	printf("数学平均分：%.1f\n",avg_shuxue/n);	
	printf("英语平均分：%.1f\n",avg_yingyu/n);
	printf("语文不及格人数：%d\n",cnt_yuwen);
	printf("数学不及格人数：%d\n",cnt_shuxue);
	printf("英语不及格人数：%d\n",cnt_yingyu);
	fprintf(fp,"语文平均分：%.1f\n",avg_yuwen/n);
	fprintf(fp,"数学平均分：%.1f\n",avg_shuxue/n);	
	fprintf(fp,"英语平均分：%.1f\n",avg_yingyu/n);
	fprintf(fp,"语文不及格人数：%d\n",cnt_yuwen);
	fprintf(fp,"数学不及格人数：%d\n",cnt_shuxue);
	fprintf(fp,"英语不及格人数：%d\n",cnt_yingyu);
}
int main()
{
	STU s[N];
	FILE *fp;
	fp=fopen("d:\\stud.txt","w");
	input_info(s,N);
	input_score(s,N);
	sort(s,N);
	output(s,N,fp);
	avg_cnt(s,N,fp);
	fclose(fp);
	return 0;
}


运行结果如下：
 

四、	实验结果及分析
1.	经过编译、链接后执行，得结果如下：
 

程序执行正确，结果符合要求。

五、实验体会、问题讨论
1. 自从拿到题目到完成整个编程，从理论到实践，可以学到很多很多的东西，同时不仅可以巩固了以前所学过的知识，而且学到了很多在书本上所没有学到过的知识。
2. 在编程之前要考虑好程序的算法，写出流程图，这样才能更加快速的、有效的编程。
3. 把运算符的优先顺序排列清楚，要分清楚哪个先运算，哪个后运算。
4. 结构体是常用的一种数据类型，它的功能也比较强大，相对于指针而言，结构体掌握起来比较容易理解和使用。
5. 课堂上要讲授许多关于c语言的语法规则，听起来十分枯燥无味，也不容易记住，死记硬背是不可取的。然而要使用c语言这个工具解决实际问题，又必须掌握它。通过多次上机练习，对于语法知识有了感性的认识，加深对它的理解。




教师签字：   张鹏飞   批改日期：  2019年 1  月  11 日

