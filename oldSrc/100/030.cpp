#include<stdio.h>

main()

{
	int n1, nm, i, j, flag, count = 0;

	do {
		printf("Input START and END=?");

		scanf("%d%d", &n1, &nm);           /*�����������ķ�Χ*/
	} while (!(n1 > 0 && n1 < nm));               /*������ȷ�ķ�Χ*/

	printf("...........PRIME TABLE(%d--%d)............\n", n1, nm);

	if (n1 == 1 || n1 == 2)                  /*��������2*/

	{
		printf("%4d", 2);

		n1 = 3; count++;
	}

	for (i = n1; i <= nm; i++)              /*�ж�ָ����Χ�ڵ������Ƿ�Ϊ����*/

	{
		if (!(i % 2))continue;

		for (flag = 1, j = 3; flag && j < i / 2; j += 2)

			/*�ж��ܷ񱻴�3��������һ���е�ĳһ��
������*/

if (!(i % j))flag = 0;       /*����������������*/

		if (flag) printf(++count % 15 ? "%4d" : "%4d\n", i);
	}
}