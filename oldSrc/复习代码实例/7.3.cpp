/*
3�� �����һ��ָ���ļ����Ƶ�һ�����ļ��У��¾��ļ������ɼ������롣
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE* fps, * fpd;
	char fsname[20], fdname[20], c;
	printf("����Դ�ļ���\n");
	scanf("%s", fsname);
	if ((fps = fopen(fsname, "r")) == NULL)
	{
		printf("cannot open flie");
		exit(0);
	}
	printf("����Ŀ���ļ���\n");
	scanf("%s", fdname);
	if ((fpd = fopen(fdname, "w")) == NULL)
	{
		printf("cannot open flie");
		exit(0);
	}
	while (!feof(fps))
	{
		c = fgetc(fps);
		fputc(c, fpd);
	}
	fclose(fps);
	fclose(fpd);
	printf("�����ļ����\n");
	return 0;
}