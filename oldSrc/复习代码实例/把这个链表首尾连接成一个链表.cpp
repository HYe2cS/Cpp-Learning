/*
2����������������Ϊstruct student���͡���ÿ������������һ����㣬���һ������nextָ��Ϊ0,
����֪�����������ͷ����ַ�ֱ�Ϊhead_A,head_B,�Ա�дһ�������������������β���ӳ�һ��������������������ͷ����ַ��
*/
struct student* connect(struct student* head1, struct student* head2)
{
	struct student* p1, * p2;
	for (p1 = head1; p1 != NULL; p1 = p1->next)
		p2 = p1;
	p2->next = head2;
	return(head1);
}