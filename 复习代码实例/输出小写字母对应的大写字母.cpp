/*
1����дһ������ʵ������һ��СдӢ����ĸ�������������Ӧ�Ĵ�д��ĸ��Ҫ������ظ����룬
ֱ������һ����Ӣ����ĸ���ַ������������ʾ��СдӢ����ĸ��ASCII��ֵ�ȴ�Щ��ĸ��32��
*/

#include <stdio.h>
int main()
{
	char ch;
	while (1)
	{
		while ((ch = getchar()) == '\n')
			printf("\n");
		if (ch >= 'a' && ch <= 'z')ch -= 32;
		if (ch >= 'A' && ch <= 'Z') printf("%c", ch);
		else break;
	}
	return 0;
}