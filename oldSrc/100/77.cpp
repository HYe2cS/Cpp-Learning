#include<stdio.h>

void getti(int a, int y, int z);

int i;           /*�����Ҫ�ֳ�������*/

main()

{
	int a, y, z;

	printf("input Full a,Empty b,c,Get i:"); /*a ��ƿ������  y:��һ����ƿ
 ������  z:�ڶ�����ƿ������*/

	scanf("%d%d%d%d", &a, &y, &z, &i);

	getti(a, y, z);           /*��a -> y -> z -> a�Ĳ�������*/

	getti(a, z, y);           /*��a -> z -> y -> a�Ĳ���*/
}

void getti(int a, int y, int z)   /*a:��ƿ������  y:��һ����ƿ������  z:��
������ƿ������*/

{
	int b = 0, c = 0;           /* b:��һƿʵ�ʵ�����  c:�ڶ�ƿʵ�ʵ�����*/

	printf("   a%d b%d c%d\n %4d%4d%4d\n", a, y, z, a, b, c);

	while (a != i || b != i && c != i)      /*����ƿ!=i������ƿ��!=i*/

	{
		if (!b)

		{
			a -= y; b = y;
		}    /*�����һƿΪ�գ�����ƿ�����һƿ��*/

		else if (c == z)

		{
			a += z; c = 0;
		}    /*����ڶ�ƿ�����򽫵ڶ�ƿ������ƿ��*/

		else if (b > z - c)    /*�����һƿ������>�ڶ�ƿ��ʣ��ռ�*/

		{
			b -= (z - c); c = z;
		}    /*��װ���ڶ�ƿ����һƿ�б���ʣ�ಿ��*/

		else { c += b; b = 0; }   /*���򣬽���һƿȫ������ڶ�ƿ��*/

		printf(" %4d %4d %4d\n", a, b, c);
	}
}