#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void p(int*, char*);
int comp(const void* j, const void* i);

int main()
{
	static char n[] = { '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };
	int a[53], b1[13], b2[13], b3[13], b4[13];
	int b11 = 0, b22 = 0, b33 = 0, b44 = 0, t = 1, m, flag, i;

	srand((unsigned)time(NULL));
	while (t <= 52)                               /*控制发52张牌*/
	{
		m = rand() % 52;                   /*产生0~51之间的随机数*/
		for (flag = 1, i = 1; i <= t && flag; i++)
		{                           /*查找新产生的随机数是否已经存在*/
			if (m == a[i])
			{
				flag = 0;
			}
		}
		if (flag)
		{
			a[t++] = m;
			if (0 == t % 4)            /*根据t的模值，判断当前的牌*/
			{                                  /*应存入哪个数组中*/
				b1[b11++] = a[t - 1];
			}
			else
			{
				if (1 == t % 4)
				{
					b2[b22++] = a[t - 1];
				}
				else
				{
					if (2 == t % 4)
					{
						b3[b33++] = a[t - 1];
					}
					else
					{
						if (3 == t % 4)
						{
							b4[b44++] = a[t - 1];
						}
					}
				}
			}
		}
	}
	qsort(b1, 13, sizeof(b1[0]), comp);     /*将每个人的牌进行排序*/
	qsort(b2, 13, sizeof(b2[0]), comp);
	qsort(b3, 13, sizeof(b3[0]), comp);
	qsort(b4, 13, sizeof(b4[0]), comp);

	printf("No.1");                          /*分别打印每个人的牌*/
	p(b1, n);
	printf("\nNo.2");
	p(b2, n);
	printf("\nNo.3");
	p(b3, n);
	printf("\nNo.4");
	p(b4, n);

	printf("\n");
	return 0;
}
void p(int* b, char* n)
{
	int i;
	printf("\n%c ", 'S');
	for (i = 0; i < 13; i++)
	{
		if (0 == b[i] / 13)
		{
			printf("%c", n[b[i] % 13]);
		}
	}
	printf("\n%c ", 'H');
	for (i = 0; i < 13; i++)
	{
		if (1 == b[i] / 13)
		{
			printf("%c", n[b[i] % 13]);
		}
	}
	printf("\n%c ", 'D');
	for (i = 0; i < 13; i++)
	{
		if (2 == b[i] / 13)
		{
			printf("%c", n[b[i] % 13]);
		}
	}
	printf("\n%c ", 'C');
	for (i = 0; i < 13; i++)
	{
		if (3 == b[i] / 13 || 4 == b[i] / 13)
		{
			printf("%c", n[b[i] % 13]);
		}
	}
}
int comp(const void* j, const void* i)
{
	return(*(char*)i - *(char*)j);
}