/*
项目一 小学生测验          16学时
问题描述：面向小学1~2年级学生，随机选择两个整数的加减法形成算式要求学生解答。
基本要求
（1）电脑随机出10道题，每题10分，程序结束时显示学生得分；
（2）确保算式没有超出1~2年级的水平，只允许进行50以内的加减法，不允许两数之和或差超出0~50的范围，负数更是不允许的；
（3）每道题学生有三次机会输入答案，当学生输入错误答案时，提醒学生重新输入，如果三次机会结束则输出正确答案；
（4）对于每道题，学生第一次输入正确答案得10分，第二次输入正确答案得7分，第三次输入正确答案得5分，否则不得分；
（5）总成绩90以上显示"SMART"，80-90显示"GOOD"，70-80显示"OK"，60-70显示"PASS"，60以下"TRY AGAIN"。
*/
#include<stdio.h>
#include<stdlib.h>/*用到了srand函数，所以要有这个头文件*/
#include<time.h> /*用到了time函数，所以要有这个头文件*/
void PrintScore(int score)
{
    switch (score / 10)//判断等级
    {
    case 10:
    case 9:printf("你的总得分是:%d,评价是:SMART \n", score); break;
    case 8:printf("你的总得分是:%d,评价是:GOOD \n", score); break;
    case 7:printf("你的总得分是:%d,评价是:OK \n", score); break;
    case 6:printf("你的总得分是:%d,评价是:PASS \n", score); break;
    default:printf("你的总得分是:%d,低于60分，评价是:TRY AGAIN \n", score); break;
    }
    printf("------------------------------\n");
}

int PD(int a, int b)//返回值为1使用加法，返回值为0使用减法
{
    int sum = 0;//初始化
    if (rand() % 2 == 1)
    {
        sum = a + b;
        printf("请输入%d+%d=?\n", a, b);
    }//返回值为1使用加法
    else
    {
        sum = a - b;
        printf("请输入%d-%d=?\n", a, b);
    }//返回值为0使用减法
    return sum;
}

int YunSuan(int sum, int& score)//接受学生输入结果，并判断正确错误
{
    int s = 0;//记录输入结果
    int k;//用来记录和判断输入错误的次数
    for (k = 0; k < 3;)
    {
        printf("请输入正确答案：");
        scanf("%d", &s);//s接收输入结果
        if (s == sum)//如果第一次输入结果错误，进行提示并开始第二次输入
        {
            printf("*********您答对了！*********\n"); break;
        }
        else
        {
            printf("*********您答错了！*********\n"); k++;
        }
    }
    switch (k)
    {
    case 0:score += 10; break;//如果第一次输入结果正确，分数加10
    case 1:score += 7; break;//如果第二次输入结果正确，分数加7
    case 2:score += 5; break;//如果第三次输入结果正确，分数加5
    default:break;
    }
    printf("现在的分数为：%d\n", score);
    printf("------------------------------\n");
    return score;
}

int main()
{
    int a = 0, b = 0;//用于生成随机数
    int sum = 0;//记录加或减的正确结果
    int i = 0;//记录第几题
    int score = 0;//记录分数
    printf("\t***********************************************\n");

    printf("\t*********欢迎使用小学生测验系统****************\n");
    printf("\t***********************************************\n");
    printf("\t任意输入一个数，开始测试\n");
    printf("\t测试10道题\n");
    printf("\t第一次答对加10分\n");
    printf("\t第二次答对加7分\n");
    printf("\t第三次答对加5分\n");
    printf("\t第三次若未答对不加分，跳过此题开始下一题测试\n");
    printf("\t***********************************************\n");
    srand(time(NULL));
    printf("------------------------------\n");
    for (i = 0; i < 10; i++)//用来记录第几题，并依次作答
    {
        printf("请回答第%d题:\n", i + 1);
        a = rand() % 51;
        b = rand() % 51;
        while (a + b > 50 || a - b < 0)
        {
            a = rand() % 51;
            b = rand() % 51;
        }
        //判断加法和减法，并算出结果

        sum = PD(a, b);
        YunSuan(sum, score);//接受学生输入结果，并判断正确错误
    }
    PrintScore(score);
    return 0;
}