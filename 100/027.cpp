#include<stdio.h>
main()

{
	long mul, number, k, ll, kk;

	printf("It exists following automorphic nmbers small than 200000:\n"
	);

	for (number = 0; number < 200000; number++)

	{
		for (mul = number, k = 1; (mul /= 10) > 0; k *= 10);

		/*��number��λ��ȷ����ȡ���ֽ��г˷�ʱ��ϵ��k*/

		kk = k * 10;      /*kkΪ��ȡ���ֻ�ʱ��ϵ��*/

		mul = 0;        /*�������nλ*/

		ll = 10;        /*llΪ��ȡ������Ӧλʱ��ϵ��*/

		while (k > 0)

		{
			mul = (mul + (number % (k * 10)) * (number % ll - number % (ll / 10))) % kk;

			/*(���ֻ�+��ȡ�������ĺ�Nλ*��ȡ�����ĵ�Mλ)��%kk�ٽ�ȡ
���ֻ�*/

			k /= 10;               /*kΪ��ȡ������ʱ��ϵ��*/

			ll *= 10;
		}

		if (number == mul)         /*�ж���Ϊ�����������*/

			printf("%ld   ", number);
	}
}