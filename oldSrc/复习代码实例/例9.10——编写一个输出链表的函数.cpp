/*
例9.10——编写一个输出链表的函数
*/
#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct Student)
struct Student {
	long num;
	float score;
	struct Student* next;
};
int n;
void print(struct Student* head)
{
	struct Student* p;
	printf("\bNow,Thease %d record are:\n", n);
	p = head;
	if (head != NULL)
		do
		{
			printf("%ld %5.1f\n", p->num, p->score);
			p = p->next;
		} while (p != NULL);
}