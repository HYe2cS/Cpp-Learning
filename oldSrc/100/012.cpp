#include<stdio.h>
#include<math.h>
main()
{
	int i, j, k, c;
	for (i = 1; i <= 9; i++)                  /*i:����ǰ��λ��ȡֵ*/
		for (j = 0; j <= 9; j++)              /*j:���ź��λ��ȡֵ*/
			if (i != j)                   /*�ж϶�λ�����Ƿ�����*/
			{
				k = i * 1000 + i * 100 + j * 10 + j; /*��������ܵ�����*/
				for (c = 31; c * c < k; c++);   /*�жϸ����Ƿ�Ϊ��һ������ƽ��*/
				if (c * c == k) printf("Lorry--No. is %d.\n", k);     /*���ǣ���ӡ
���*/
			}
}