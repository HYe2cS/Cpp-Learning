#include<stdio.h>
int main()
{
	printf("-----------------------------------------\n");
	printf("            �� �� ��\n\n");
	printf("   1. ��Ӽ�¼   2. ��ʾ��¼ \n");
	printf("   3. ��ȡ��¼   4. �����¼\n");
	printf("-----------------------------------------\n");
	printf("  ��ѡ�� 1-4 �� 0 �˳���\n");

	int x;
	//x=getchar();
	scanf("%d", &x);
	switch (x)
	{
	case 0:printf("��ѡ����0\n"); break;
	case 1:printf("��ѡ����1\n"); break;
	case 2:printf("��ѡ����2\n"); break;
	case 3:printf("��ѡ����3\n"); break;
	case 4:printf("��ѡ����4\n"); break;
	default:printf("ѡ�����");
	}
	return 0;
}