#include<stdio.h>
int main()
{
	int a, b, c, count = 0;
	printf("There are diffrent methods for XM to distribute books to 3 readers:\n");
	for (a = 1; a <= 5; a++)             /*��ٵ�һ���˽�5�����е�1����ȫ�����*/
		for (b = 1; b <= 5; b++)         /*��ٵڶ����˽�5�����е�һ����ȫ�����*/
			for (c = 1; a != b && c <= 5; c++)    /*��ǰ�����˽費ͬ����ʱ����ٵ������˽�5�����е�1����ȫ�����*/
				if (c != a && c != b)         /*�жϵ�������ǰ�����˽�����Ƿ�ͬ*/
					printf(count % 8 ? "%2d:%d,%d,%d  " : "%2d:%d,%d,%d\n  ", ++count, a, b, c);
	/*��ӡ���ܵĽ��ķ���*/
}