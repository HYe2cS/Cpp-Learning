#include<stdio.h>

main()

{
	int a, i, b, n;

	printf("There are following friendly--numbers pair smaller than 3000:\n");

	for (a = 1; a < 3000; a++)        /*���1000���ڵ�ȫ������*/

	{
		for (b = 0, i = 1; i <= a / 2; i++)    /*������a�ĸ����ӣ�������֮�ʹ����b*
/

			if(!(a%i))b+=i;        /*����b�ĸ����ӣ�������֮�ʹ���n*/

			for (n = 0, i = 1; i <= b / 2; i++)

				if (!(b % i))n += i;

		if (n == a && a < b)

			printf("%4d..%4d    ", a, b);     /*��n=a����a��b��һ����������
���*/
	}
}