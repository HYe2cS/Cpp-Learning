/*2. �Ӽ�������������a��b��c�����ܹ���������������������
����������ܹ��������ε���ʾ��Ϣ"No triangle"�� ������������㹫ʽ    ���У�s=(a+b+c)��2����10�֣�
*/
#include<stdio.h>
#include<math.h>
int main()
{
	float s, area, a, b, c;
	scanf("a=%f b=%f c=%f", &a, &b, &c);
	if (a + b > c && a + c > b && b + c > a)
	{
		s = (a + b + c) / 2;
		area = sqrt(s * (s - a) * (s - b) * (s - c));
		printf("area=%f\n", area);
	}
	else 	printf("no triangle!");
	return 0;
}