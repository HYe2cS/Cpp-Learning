#include<stdio.h>

#include<stdlib.h>

int a[8];

char* day[] = { "","MONDAY","TUESDAY","WEDNESDAY","THURSDAYT",

				"FRIDAY","SATUDAY","SUNDAY" };       /*建 立星期表*/

main()

{
	int i, j, t;

	a[4] = 6;               /*星期四是F值班*/

	for (i = 1; i <= 3; i++)

	{
		a[i] = 2;           /*假设B值班的日期*/

		if (!a[i + 3]) a[i + 3] = 7;         /*若三天后无人值班则安排G值班*/

		else { a[i] = 0; continue; }      /*否则B值班的日期不断对*/

		for (t = 1; t <= 3; t++)             /*假设E值班的时间*/

		{
			if (!a[t]) a[t] = 5;         /*若当天无人值班则安排E值班*/

			else continue;

			if (!a[t + 2]) a[t + 2] = 4;     /*若E值班两天后无人值班则应为D*/

			else { a[t] = 0; continue; }   /*否则E值班的日期不对*/

			for (j = 5; j < 7; j++)

			{
				if (!a[j]) a[j] = 3;      /*若当天无人值班，则安排C值班*/

				else continue;

				if (!a[j + 1]) a[j + 1] = 1;  /*C之后一天无人值班则应当是A值班*
/

				else{ a[j]=0;continue;}   /*否则A值班日期不对*/

				for (i = 1; i <= 7; i++)         /*安排完毕，输出结果*/

					printf("Doctor %c is on duty %s.\n", 'A' + a[i] - 1, day[i
					]);

				exit(0);
			}
		}
	}
}