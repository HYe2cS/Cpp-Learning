#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i;
	int j = 0;//j=10终止循环，使得只进行10次测试
	int number[100] = { 0 };
	int score = 0;//记录分数
	int sum;//记录加或减的正确结果
	int s;//记录输入结果
	printf("任意输入一个数，开始测试\n");
	unsigned int seed;
	scanf("%d", &seed);/*手动输入种子*/
	srand(seed);
	printf("测试10道题\n");
	printf("第一次答对加10分\n");
	printf("第二次答对加7分\n");
	printf("第三次答对加5分\n");
	printf("第三次若未答对不加分，跳过此题开始下一题测试\n");
loop: for (i = 0; i < 10; i++)//输出10个测试题目
{
	number[i] = (rand() % 100);//生成随机数
	number[i + 1] = (rand() % 100);//生成随机数
	if (number[i] + number[i + 1] > 50 || number[i] - number[i + 1] < 0)
		goto loop;//若两数之和大于50.或者两数相减小于0，重新循环
	j++;//记录循环次数
	printf("请输入正确答案：\n");
	if (number[i] % 2 == 0)//用于随机输出加减法
	{
		printf("%d + %d = ?\n", number[i], number[i + 1]); sum = number[i] + number[i + 1];
	}//用于输出加法
	else
	{
		printf("%d - %d = ?\n", number[i], number[i + 1]); sum = number[i] - number[i + 1];
	}//用于输出减法
	scanf("%d", &s);//s接收输入结果
	while (1)
	{
		if (s == sum)score += 10;
		else score += 0; printf("现在的分数为：%d\n", score); if (s == sum)break;//如果第一次输入结果正确，分数加10，且跳出循环，否则开始第二次输入
		printf("请输入正确答案：\n"); scanf("%d", &s);
		if (s == sum)score += 7;
		else score += 0; printf("现在的分数为：%d\n", score); if (s == sum)break;//如果第二次输入结果正确，分数加7，且跳出循环，否则开始第三次输入
		printf("请输入正确答案：\n"); scanf("%d", &s);
		if (s == sum)score += 5;//第三次输入正确，分数加5，循环结束
		else score += 0; printf("正确答案为：%d\n", sum);
		printf("现在的分数为：%d\n", score); break;//第三次输入错误，分数加0，输出现在总分数，跳出循环，开始下一题测试
	}
	if (j == 10)break;//当测试了10题之后，跳出整个for循环，结束测试
}
printf("你的总分为 %d\n", score);
switch (score / 10)//判断等级
{
case 10:printf("smart \n"); break;
case 9:printf("smart \n"); break;
case 8:printf("good \n"); break;
case 7:printf("ok \n"); break;
case 6:printf("pass \n"); break;
default:printf("try again!!!\n"); break;
}
}