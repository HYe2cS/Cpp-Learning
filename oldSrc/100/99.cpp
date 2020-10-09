#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 4000/*数位上限*/
dd(char* a)
{
	char t[MAX];
	int i, j;
	for (i = 0; i < MAX; i++)
	{
		if (a[i] == NULL)
		{
			for (j = 0; i > 0; j++, i--)
			{
				t[j] = a[i - 1];
			}
			strncpy(a, t, j);
			break;
		}
	}
}
add1(char* a, char* b, int n, char* c)
{
	int N;
	if (*a != NULL && *b != NULL)
		N = *a - '0' + *b - '0' + n;
	else if (*a == NULL && *b != NULL)
		N = *b - '0' + n;
	else if (*a != NULL && *b == NULL)
		N = *a - '0' + n;
	else
		N = n;
	*c = (N % 10) + '0';
	N = N / 10;
	if (*(a + 1) != NULL || *(b + 1) != NULL || N != 0)
	{
		add1(a + 1, b + 1, N, c + 1);
	}
}
addab(char* a, char* b, char* c)
{
	dd(a); dd(b); dd(c);
	add1(a, b, 0, c);
	dd(a); dd(b); dd(c);
}
d_(char* a)
{
	int i;
	for (i = 0; a[i] != NULL; i++)
	{
		a[i] = a[i + 1];
	}
}
udg1(char* a, char* b, int n, char* c)
{
	int N;
	if (*b == NULL)
	{
		N = *a - '0' - n;
		n = 0;
	}
	else
	{
		if (*a >= (*b + n))
		{
			N = *a - *b - n;
			n = 0;
		}
		else
		{
			N = *a + 10 - *b - n;
			n = 1;
		}
	}
	*c = N + '0';
	if (*(a + 1) != NULL)
		udg1(a + 1, b + 1, n, c + 1);
}
udg(char* a, char* b, char* c)
{
	int i;
	if ((strcmp(a, b) > 0 && strlen(a) == strlen(b)) || strlen(a) > strlen(b))
		i = 1;
	else if ((strcmp(a, b) < 0 && strlen(a) == strlen(b)) || strlen(b) > strlen(a))
		i = -1;
	else
		i = 0;
	dd(a); dd(b); dd(c);
	if (i == 1)
		udg1(a, b, 0, c);
	else if (i == -1)
	{
		udg1(b, a, 0, c);
		for (i = 0; i < MAX; i++)
		{
			if (c[i] == NULL)
			{
				c[i] = '-';
				break;
			}
		}
	}
	else
		*c = '0';
	dd(a); dd(b); dd(c);
}
add_(char* c)
{
	int i;
	char t1, t2;
	t1 = c[0];
	t2 = c[1];
	c[0] = '-';
	for (i = 1; t1 != '\0'; i++)
	{
		c[i] = t1;
		t1 = t2;
		t2 = c[i + 1];
	}
}
ck(char* a)
{
	while (*a == '0' && *(a + 1) != NULL)
	{
		d_(a);
	}
}
main()
{
	char a[MAX] = { NULL }, b[MAX] = { NULL }, c[MAX] = { NULL };
	printf("输入两个数：\n");
	scanf("%s", a);
	getchar(); ck(a);
	scanf("%s", b);
	getchar(); ck(b);
	if (a[0] != '-' && b[0] != '-')
	{
		addab(a, b, c);
	}
	else
	{
		if (a[0] == '-' && b[0] != '-')
		{
			d_(a);
			ck(a);
			udg(b, a, c);
		}
		else if (a[0] != '-' && b[0] == '-')
		{
			d_(b);
			ck(b);
			udg(a, b, c);
		}
		else
		{
			d_(b);
			d_(a);
			ck(a);
			ck(b);
			addab(a, b, c);
			add_(c);
		}
	}
	printf("%s\n", c);
	getchar();
}