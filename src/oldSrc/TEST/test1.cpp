#include<stdio.h>
int main()
{
    printf("-----------------------------------------\n");
    printf("            主 菜 单\n\n");
    printf("   1. 添加记录   2. 显示记录 \n");
    printf("   3. 读取记录   4. 保存记录\n");
    printf("-----------------------------------------\n");
    printf("  请选择 1-4 ， 0 退出：\n");

    int x;
    //x=getchar();
    scanf("%d", &x);
    switch (x)
    {
    case 0:printf("你选择了0\n"); break;
    case 1:printf("你选择了1\n"); break;
    case 2:printf("你选择了2\n"); break;
    case 3:printf("你选择了3\n"); break;
    case 4:printf("你选择了4\n"); break;
    default:printf("选择错误！");
    }
    return 0;
}