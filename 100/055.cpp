#include<stdio.h>

#include<stdlib.h>

int a[8];

char* day[] = { "","MONDAY","TUESDAY","WEDNESDAY","THURSDAYT",

				"FRIDAY","SATUDAY","SUNDAY" };       /*�� �����ڱ�*/

main()

{
	int i, j, t;

	a[4] = 6;               /*��������Fֵ��*/

	for (i = 1; i <= 3; i++)

	{
		a[i] = 2;           /*����Bֵ�������*/

		if (!a[i + 3]) a[i + 3] = 7;         /*�����������ֵ������Gֵ��*/

		else { a[i] = 0; continue; }      /*����Bֵ������ڲ��϶�*/

		for (t = 1; t <= 3; t++)             /*����Eֵ���ʱ��*/

		{
			if (!a[t]) a[t] = 5;         /*����������ֵ������Eֵ��*/

			else continue;

			if (!a[t + 2]) a[t + 2] = 4;     /*��Eֵ�����������ֵ����ӦΪD*/

			else { a[t] = 0; continue; }   /*����Eֵ������ڲ���*/

			for (j = 5; j < 7; j++)

			{
				if (!a[j]) a[j] = 3;      /*����������ֵ�࣬����Cֵ��*/

				else continue;

				if (!a[j + 1]) a[j + 1] = 1;  /*C֮��һ������ֵ����Ӧ����Aֵ��*
/

				else{ a[j]=0;continue;}   /*����Aֵ�����ڲ���*/

				for (i = 1; i <= 7; i++)         /*������ϣ�������*/

					printf("Doctor %c is on duty %s.\n", 'A' + a[i] - 1, day[i
					]);

				exit(0);
			}
		}
	}
}