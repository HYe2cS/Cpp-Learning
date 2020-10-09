/*
3． 编程序将一个指定文件复制到一个新文件中，新旧文件名均由键盘输入。
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE* fps, * fpd;
	char fsname[20], fdname[20], c;
	printf("输入源文件名\n");
	scanf("%s", fsname);
	if ((fps = fopen(fsname, "r")) == NULL)
	{
		printf("cannot open flie");
		exit(0);
	}
	printf("输入目标文件名\n");
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
	printf("复制文件完成\n");
	return 0;
}