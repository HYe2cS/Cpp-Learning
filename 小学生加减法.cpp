#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i;
	int j = 0;//j=10��ֹѭ����ʹ��ֻ����10�β���
	int number[100] = { 0 };
	int score = 0;//��¼����
	int sum;//��¼�ӻ������ȷ���
	int s;//��¼������
	printf("��������һ��������ʼ����\n");
	unsigned int seed;
	scanf("%d", &seed);/*�ֶ���������*/
	srand(seed);
	printf("����10����\n");
	printf("��һ�δ�Լ�10��\n");
	printf("�ڶ��δ�Լ�7��\n");
	printf("�����δ�Լ�5��\n");
	printf("��������δ��Բ��ӷ֣��������⿪ʼ��һ�����\n");
loop: for (i = 0; i < 10; i++)//���10��������Ŀ
{
	number[i] = (rand() % 100);//���������
	number[i + 1] = (rand() % 100);//���������
	if (number[i] + number[i + 1] > 50 || number[i] - number[i + 1] < 0)
		goto loop;//������֮�ʹ���50.�����������С��0������ѭ��
	j++;//��¼ѭ������
	printf("��������ȷ�𰸣�\n");
	if (number[i] % 2 == 0)//�����������Ӽ���
	{
		printf("%d + %d = ?\n", number[i], number[i + 1]); sum = number[i] + number[i + 1];
	}//��������ӷ�
	else
	{
		printf("%d - %d = ?\n", number[i], number[i + 1]); sum = number[i] - number[i + 1];
	}//�����������
	scanf("%d", &s);//s����������
	while (1)
	{
		if (s == sum)score += 10;
		else score += 0; printf("���ڵķ���Ϊ��%d\n", score); if (s == sum)break;//�����һ����������ȷ��������10��������ѭ��������ʼ�ڶ�������
		printf("��������ȷ�𰸣�\n"); scanf("%d", &s);
		if (s == sum)score += 7;
		else score += 0; printf("���ڵķ���Ϊ��%d\n", score); if (s == sum)break;//����ڶ�����������ȷ��������7��������ѭ��������ʼ����������
		printf("��������ȷ�𰸣�\n"); scanf("%d", &s);
		if (s == sum)score += 5;//������������ȷ��������5��ѭ������
		else score += 0; printf("��ȷ��Ϊ��%d\n", sum);
		printf("���ڵķ���Ϊ��%d\n", score); break;//������������󣬷�����0����������ܷ���������ѭ������ʼ��һ�����
	}
	if (j == 10)break;//��������10��֮����������forѭ������������
}
printf("����ܷ�Ϊ %d\n", score);
switch (score / 10)//�жϵȼ�
{
case 10:printf("smart \n"); break;
case 9:printf("smart \n"); break;
case 8:printf("good \n"); break;
case 7:printf("ok \n"); break;
case 6:printf("pass \n"); break;
default:printf("try again!!!\n"); break;
}
}