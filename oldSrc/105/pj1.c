﻿#include<stdio.h>
#include<stdlib.h>
#define BUFFERSIZE 1024  /*允许处理的最长行有1024个字符*/
int main()
{
	unsigned short a, b, sum;         /*将输入的两个数分别存储在变量a和b中，sum=a+b*/
	char buffer[BUFFERSIZE];
	printf("***********************************\n");
	printf("*  Welcome to use our counter     *\n");
	printf("*  Input two integers in one line *\n");
	printf("*  The sum will be printed        *\n");
	printf("*  Input the char '#' to quit  s  *\n");
	printf("***********************************\n");
	/*从标准输入（stdin）读取输入的数据，存储在buffer中.
	如果读取的第一个字符是'#'则推出程序*/
	while ((fgets(buffer, BUFFERSIZE, stdin) != NULL) && (buffer[0] != '#'))
	{
		if (sscanf(buffer, "%hd %hd", &a, &b) != 2)            /*处理存储在buffer中的一行数据*/
			fprintf(stderr, "The input is skipped:%s", buffer);
		sum = a + b;                                       /*计算a与b的和*/
		printf("The sum of %d and %d is %d\n", a, b, sum);/*输出计算结果*/
	}
	return 0;
}