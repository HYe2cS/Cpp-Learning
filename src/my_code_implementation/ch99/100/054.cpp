#include<stdio.h>

main()

{
    int a, b, c, aa, bb, cc;

    for (a = 0; a <= 1; a++)            /*穷举全部情况*/

        for (b = 0; b <= 1; b++)

            for (c = 0; c <= 1; c++)

                for (aa = 0; aa <= 1; aa++)

                    for (bb = 0; bb <= 1; bb++)

                        for (cc = 0; cc <= 1; cc++)

                            if (a + aa != 2 && b + bb != 2 && c + cc != 2 &&       /*判断逻辑条件*/

                                a + b + c == 1 && aa + bb + cc == 1 &&

                                (a && !aa && b && !bb || !a && !b) &&

                                !b &&

                                (c && !b && !bb || (!c && !cc) && (b || bb) || !c & cc))

                            {
                                printf("The man stand on left is a %s.\n",

                                    aa ? "double--dealer" : (a ? "honest" : "lier"));

                                printf("The man stand on left is a %s.\n",

                                    bb ? "double--dealer" : (b ? "honest" : "lier"));

                                printf("The man stand on left is a %s.\n",

                                    cc ? "double--dealer" : (c ? "honest" : "lier"));

                                /*输出最终的推
理结果*/
                            }
}