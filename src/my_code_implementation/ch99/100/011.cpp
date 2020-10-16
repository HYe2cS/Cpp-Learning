#include<stdio.h>
int days(struct date day);
struct date {
    int year;
    int month;
    int day;
};

main()
{
    struct date today, term;
    int yearday, year, day;
    printf("Enter year/month/day:");
    scanf("%d%d%d", &today.year, &today.month, &today.day);  /*输入日期*/
    term.month = 12;               /*设置变量的初始值：月*/
    term.day = 31;                 /*设置变量的初始值：日*/
    for (yearday = 0, year = 1990; year < today.year; year++)
    {
        term.year = year;
        yearday += days(term);     /*计算从1990年至指定年的前一年共有多少天*/
    }
    yearday += days(today);       /*加上指定年中到指定日期的天数*/
    day = yearday % 5;               /*求余数*/
    if (day > 0 && day < 4) printf("he was fishing at that day.\n");   /*打印结果*/
    else printf("He was sleeping at that day.\n");
}

int days(struct date day)
{
    static int day_tab[2][13] =
    { {0,31,28,31,30,31,30,31,31,30,31,30,31,},      /*平均每月的天数
*/
             {0,31,29,31,30,31,30,31,31,30,31,30,31,},
    };
    int i, lp;
    lp = day.year % 4 == 0 && day.year % 100 != 0 || day.year % 400 == 0;
    /*判定year为闰年还是平年，lp=0为平年，非0为闰年*/
    for (i = 1; i < day.month; i++)            /*计算本年中自1月1日起的天数*/
        day.day += day_tab[lp][i];
    return day.day;
}