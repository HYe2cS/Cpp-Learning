#include<malloc.h>
#include<stdio.h>
#include<iostream>
using namespace std;
typedef struct node
{
	int exp;
	int data;
	node* next;
}Node;
int create(Node*& L)
{
	int x;
	int y;
	Node* p, * q;
	L = (Node*)malloc(sizeof(Node));
	L->next = NULL;
	q = L;
	scanf("%d,%d", &x, &y);
	while (x != 0 || y != 0)
	{
		p = (Node*)malloc(sizeof(Node));
		p->exp = x;
		p->data = y;
		p->next = NULL;
		q->next = p;
		q = p;
		scanf("%d,%d", &x, &y);
	}
	return 0;
}
void print(Node* L)
{
	Node* p;
	p = L->next;
	while (p)
	{
		if (p->next != NULL)
			cout << p->exp << "x" << "^" << p->data << "+";
		else
			cout << p->exp << "x" << "^" << p->data;
		p = p->next;
	}
}
int add(Node*& A, Node*& B)
{
	Node* p, * q, * p1, * m;
	p = A->next;
	p1 = A;
	q = B->next;
	while (p && q)
	{
		if (p->data < q->data)
		{
			p = p->next;
			p1 = p1->next;
		}
		else
		{
			if (p->data > q->data)
			{
				m = q;
				q = q->next;
				m->next = p;

				p1->next = m;
				p1 = m;
			}
			else
			{
				p->exp = p->exp + q->exp;
				if (p->exp != 0)
				{
					p = p->next;
					p1 = p1->next;
					m = q;
					q = q->next;
					free(m);
				}
				else
				{
					p1->next = p->next;
					free(p);
					p = p1->next;
					m = q;
					q = q->next;
					free(m);
				}
			}
		}
	}
	return 0;
}
int main()
{
	Node* head1, * head2;
	create(head1);
	create(head2);
	add(head1, head2);
	print(head1);
	return 0;
}