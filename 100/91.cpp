#include<stdio.h>

#include<time.h>

#include<stdlib.h>

main()

{
	int stime, a, z, t, i, c, m, g, s, j, k, l[4];    /*j:������ȷ��λ��  k:λ����ȷ
 ��λ��*/

	long ltime;

	ltime = time(NULL);       /*l:������ͬʱ�������������ֵ���ȷλ��*/

	stime = (unsigned int)ltime / 2;

	srand(stime);

	z = rand(9999);        /*�������һ�������*/

	printf("I have a number with 4 digits in mind,please guess.\n");

	for (c = 1;; c++)         /*c: ��������������*/

	{
		printf("Enter a number with 4 digits:");

		scanf("%d", &g);           /*���˲�*/

		a = z; j = 0; k = 0; l[0] = l[1] = l[2] = l[3] = 0;

		for (i = 1; i < 5; i++)      /*i:ԭ���еĵ�iλ������λΪ��һλ��ǧλΪ��4
  λ*/

		{
			s = g; m = 1;

			for (t = 1; t < 5; t++)     /*�����������*/

			{
				if (a % 10 == s % 10)     /*����iλ���˲µĵ�tλ��ͬ*/

				{
					if (m && t != l[0] && t != l[1] && t != l[2] && t != l[3])

					{
						j++; m = 0; l[j - 1] = t;    /*����λ���ϵ�������δ����������"
	  ��ͬ"*/
					}                       /*��¼��ͬ����ʱ������������������
	 �е�λ��*/

					if (i == t) k++;         /*��λ��Ҳ��ͬ���������k��1*/
				}

				s /= 10;
			}

			a /= 10;
		}

		printf("You hane correctly guessed %d digits,\n", j);

		printf("and correctly guessed %d digits in exact position.\n", k);

		if (k == 4) break;         /*��λ��ȫ����ȷ�����˲¶��ˣ��˳�*/
	}

	printf("Now you have correctly guessed the whole number after %d times.\n", c);
}