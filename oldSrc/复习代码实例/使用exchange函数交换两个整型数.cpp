//2. (1)��дһ������change( )ʵ���������ͱ�����ֵ������
//(2)д�����������Ӽ�����������������Ȼ����ú���change()����������������ֵ���������10�֣�
#include<stdio.h>
void change(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	change(&a, &b);
	printf("%d,%d\n", a, b);
	return 0;
}