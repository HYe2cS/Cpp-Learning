#include<stdio.h>

void getti(int a, int y, int z);

int i;           /*最后需要分出的重量*/

main()

{
	int a, y, z;

	printf("input Full a,Empty b,c,Get i:"); /*a 满瓶的容量  y:第一个空瓶
 的容量  z:第二个空瓶的容量*/

	scanf("%d%d%d%d", &a, &y, &z, &i);

	getti(a, y, z);           /*按a -> y -> z -> a的操作步骤*/

	getti(a, z, y);           /*按a -> z -> y -> a的步骤*/
}

void getti(int a, int y, int z)   /*a:满瓶的容量  y:第一个空瓶的容量  z:第
二个空瓶的容量*/

{
	int b = 0, c = 0;           /* b:第一瓶实际的重量  c:第二瓶实际的重量*/

	printf("   a%d b%d c%d\n %4d%4d%4d\n", a, y, z, a, b, c);

	while (a != i || b != i && c != i)      /*当满瓶!=i或另两瓶都!=i*/

	{
		if (!b)

		{
			a -= y; b = y;
		}    /*如果第一瓶为空，则将满瓶倒入第一瓶中*/

		else if (c == z)

		{
			a += z; c = 0;
		}    /*如果第二瓶满，则将第二瓶倒入满瓶中*/

		else if (b > z - c)    /*如果第一瓶的重量>第二瓶的剩余空间*/

		{
			b -= (z - c); c = z;
		}    /*则将装满第二瓶，第一瓶中保留剩余部分*/

		else { c += b; b = 0; }   /*否则，将第一瓶全部倒入第二瓶中*/

		printf(" %4d %4d %4d\n", a, b, c);
	}
}