/*��ҵ���ŵĽ������������ɣ����Ź������£�
  ����(I)���ڻ����10��Ԫʱ���������10%��
  �������10��Ԫ������20��Ԫʱ������10��Ԫ�Ĳ��ְ�10%��ɣ�����10��Ԫ�Ĳ��֣��ɿ����7.5%��
  20��40��֮��ʱ������20��Ԫ�Ĳ��֣������5%��
  40��60��֮��ʱ����40��Ԫ�Ĳ��֣������3%��
  60��100��֮��ʱ������60��Ԫ�Ĳ��֣������1.5%������100��Ԫʱ������100��Ԫ�Ĳ��ְ�1%��ɡ�
  �Ӽ������뵱������I����Ӧ���Ž���������*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	long int gain;
	int prize1, prize2, prize4, prize6, prize10, prize = 0;
	puts("*************************************");
	puts("*      The program will solve       *");
	puts("* the problem of prize distribution *");
	puts("*************************************");
	puts("please input the num of gain:");
	scanf("%ld", &gain);
	prize1 = 100000 * 0.1;
	prize2 = prize1 + 100000 * 0.075;
	prize4 = prize2 + 200000 * 0.05;
	prize6 = prize4 + 200000 * 0.03;
	prize10 = prize6 + 400000 * 0.015;
	if (gain <= 100000)
		prize = gain * 0.1;
	else if (gain <= 200000)
		prize = prize1 + (gain - 100000) * 0.075;
	else if (gain <= 400000)
		prize = prize2 + (gain - 200000) * 0.05;
	else if (gain <= 600000)
		prize = prize4 + (gain - 400000) * 0.03;
	else if (gain <= 1000000)
		prize = prize6 + (gain - 600000) * 0.015;
	else
		prize = prize10 + (gain - 1000000) * 0.01;
	printf("The prize is :%d\n", prize);
	getchar();
	return 0;
}