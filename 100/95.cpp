#include<stdio.h>
main()

{
	static char* a[][10] = { "","I","II","III","IV","V","VI","VII","VIII","IX"

						 "","X","XX","XXX","XL","L","LX","LXX","LXXX","XCC",

						 "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"
	};           /*�������ձ�*/

	int n, t, i, m;

	printf("Please enter number:");

	scanf("%d", &n);           /*��������*/

	printf("%d=", n);

	for (m = 0, i = 1000; m < 3; m++, i /= 10)

	{
		t = (n % i) / (i / 10);        /*�Ӹ�λ���λ����ȡ��λ������*/

		printf("%s", a[2 - m][t]);      /*ͨ�����ձ������*/
	}

	printf("\n");
}