/*
1．建立一个文件，将学生记录（由学号 、姓名、成绩组成）按下列格式写到文件 stu.txt 中。
1 Li 90
2 Wang 45
3 Zhao 58
4 Liu 93
5 Gao 100
*/
#include<stdio.h>
#include<stdlib.h>
struct student {
    int num;
    char name[20];
    int score;
};
typedef struct student STU;
void in(STU* s, int n)
{
    STU* p;
    printf("输入学生学号、姓名、成绩\n");
    for (p = s; p < s + n; p++)
        scanf("%d%s%d", &p->num, &p->name, &p->score);
}
void out(STU* s, int n, FILE* fp)
{
    STU* p;
    printf("输出学生学号、姓名、成绩\n");
    for (p = s; p < s + n; p++)
        fprintf(fp, "%d %s %d\n", p->num, p->name, p->score);
}

int main()
{
    struct student s[5];
    FILE* fp;
    if ((fp = fopen("stu.txt", "w")) == NULL)
    {
        printf("cannot open flie");
        exit(0);
    }
    in(s, 5);
    out(s, 5, fp);
    fclose(fp);
    return 0;
}