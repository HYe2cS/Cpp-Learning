#include <stdio.h>
#include <math.h>

void fun(int n, float* s);

int main()
{
	int i, t;
	float a[3], b[3];
	printf("The possible perfect squares combinations are:\n");

	for (i = 11; i <= 31; i++)
	{
		for (t = 11; t <= 31; t++)
		{
			fun(i * i, a);
			fun(t * t, b);

			if (sqrt(a[0] * 10 + b[0]) == (int)sqrt(a[0] * 10 + b[0])
				&& sqrt(a[1] * 10 + b[1]) == (int)sqrt(a[1] * 10 + b[1])
				&& sqrt(a[2] * 10 + b[2]) == (int)sqrt(a[2] * 10 + b[2]))
			{
				printf("%d and %d\n", i * i, t * t);
			}
		}
	}

	return 0;
}

void fun(int n, float* s)
{
	int k;

	for (k = 1000; k >= 10; s++)
	{
		*s = (n % k) / (k / 10);
		k /= 10;
	}
}