//C���ԣ�ð�����򷨣��������ַ�������ĸ˳��(��С����)�������
#include<stdio.h>
#include<string.h>

void sort(char* a[]);
void print(char* a[]);

int main()
{
	char* a[] = { "ceo","define","basic","abc","empty" };
	printf("ԭ���������ǣ�\n");
	print(a);

	sort(a);

	printf("\n�����������ǣ�\n");
	print(a);

	printf("\n");
	return 0;
}
void sort(char* a[])
{
	int i, j;
	char* temp;
	for (i = 0; i < 4; i++)//ע����i<4
	{
		for (j = 0; j < 4; j++)//ע����j<4,��Ϊ����Ҫ+1�ͺ�����Ǹ��ַ����Ƚ�
		{
			if (strcmp(a[j], a[j + 1]) > 0)//�ַ����Ƚ�:>0��ʾǰ����ַ����Ⱥ���Ĵ��򽻻�
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
void print(char* a[])
{
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("%s ", a[i]);
	}
}