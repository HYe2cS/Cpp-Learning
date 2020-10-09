#include<stdio.h>
#include<stdlib.h>
#define BUFFERSIZE 1024
int main()
{
	unsigned int a, b, sum;
	char buffer[BUFFERSIZE];
	printf(" **********************************************\n");
	printf("* Welcome to use our counter *\n");
	printf("* Input two integers in one line *\n");
	printf("* The sum will be printed *\n");
	printf("* Input the char '#' to quit *\n");
	printf(" **********************************************\n");

	while ((fgets(buffer, BUFFERSIZE, stdin) != NULL) && (buffer[0] != '#'))
	{
		if (sscanf(buffer, "%d %d", &a, &b) != 2)
		{
			printf("*The input is skipped:%s", buffer);
			continue;
		}
		sum = a + b;
		printf("The sum of%d and %d is %d\N", a, b, sum);/*输出计算结果*/
	}
	return 0;
}