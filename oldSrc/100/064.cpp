#include<stdio.h>

void print(long a, long b, long s1, long s2, long s3);

int jud(long q, char* pflag);

main()

{
	long i, j, k, l, m, n, term, t1, t2, t3;

	int flag;

	for (i = 0; i <= 4; ++i)           /*�������ĵ�һλ*/

		for (j = 5; j <= 9; ++j)        /*�������ĵڶ�λ*/

			for (k = 0; k <= 4; ++k)     /*�������ĵ���λ*/

			{
				term = 100 * i + 10 * j + k;   /*������*/

				for (flag = 0, n = 0; n < 4 && !flag;)       /*�����ĵ�һλ*/

					flag = jud((t3 = ++n * 100 * term) / 100, "001"); /*�жϵ��������ֻ�
	 */

				if (flag)

				{
					for (flag = 0, m = 0; m < 4 && !flag;)     /*�����ĵڶ�λ*/

						flag = jud((t2 = ++m * 10 * term) / 10, "1100");  /*�жϵڶ�������
	  ��*/

					if (flag)

					{
						for (flag = 0, l = 5; l < 9 && !flag;)         /*�����ĵ���λ*/

							flag = jud(t1 = ++l * term, "0000");    /*�жϵ�һ�����ֻ�
	   */

						if (flag && jud(t1 + t2 + t3, "00101"))     /*�жϳ�ʽ�Ļ�*/

							print(term, n * 100 + m * 10 + l, t1, t2, t3);
					}
				}
			}
}

void print(long a, long b, long s1, long s2, long s3)      /*��ӡ���*/

{
	printf("\n      %ld\n", a);

	printf("*)  %ld\n", b);

	printf("......................\n");

	printf("   %ld\n   %ld\n   %ld\n", s1, s2 / 10, s3 / 100);

	printf("......................\n");

	printf(" %ld\n", a * b);
}

int jud(long q, char* pflag)    /*�ж�һ������ÿһλ�Ƿ�����Ҫ����жϺ���
*/

/*q:��Ҫ�жϵ�����pflag:��־�ַ�����A��1��ʾ��Z��0��ʾ����־����
��˳�򣺸�ʮ��...*/

{
	while (q != 0 && *pflag != NULL)    /*ѭ���ж϶�Ӧλ��ȡֵ��Χ�Ƿ���ȷ*/

		if (*pflag - '0' != (q % 10 >= 5 ? 1 : 0))   /*��־λ���Ӧ��λ����������0*/

			return 0;

		else

		{
			q /= 10; ++pflag;         /*�������ȡ��һλ�����ж�*/
		}

	if (q == 0 && *pflag == NULL)    /*q��λ�����־�ַ����ĳ�����ͬʱ������1*/

		return 1;

	else return 0;
}