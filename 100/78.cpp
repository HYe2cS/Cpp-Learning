#include<stdio.h>

#include<math.h>

main()

{
	double e = 0.1, b = 0.5, c, d;

	long int i;                /*i: ������α���*/

	for (i = 6;; i *= 2)            /*������α����ӱ�*/

	{
		d = 1.0 - sqrt(1.0 - b * b);     /*����Բ�ڽ�������εı߳�*/

		b = 0.5 * sqrt(b * b + d * d);

		if (2 * i * b - i * e < 1e-15) break;         /*���ȴ�1e-15��ֹͣ����*/

		e = b;      /*���汾��������εı߳���Ϊ��һ�ξ��ȿ��Ƶ�����*/
	}

	printf("pai=%.15lf\n", 2 * i * b);       /*�����ֵ��������εı���*/

	printf("The number of edges of required polygon:%ld\n", i);
}