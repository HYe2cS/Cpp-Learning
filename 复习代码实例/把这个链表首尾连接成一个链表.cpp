/*
2、有两个链表，结点均为struct student类型。且每个链表至少有一个结点，最后一个结点的next指针为0,
现已知这两个链表的头结点地址分别为head_A,head_B,试编写一个函数，把这个链表首尾连接成一个链表，并返回这个链表的头结点地址。
*/
struct student* connect(struct student* head1, struct student* head2)
{
	struct student* p1, * p2;
	for (p1 = head1; p1 != NULL; p1 = p1->next)
		p2 = p1;
	p2->next = head2;
	return(head1);
}