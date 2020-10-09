#include<stdio.h>
main()

{
	int p, e, a, r;

	for (p = 1; p <= 9; p++)          /*从1到9穷举字母p的全部可能取值*/

		for (e = 0; e <= 9; e++)      /*从0到穷举字母e的全部可能取值*/

			if (p != e)            /*p不等于e*/

				for (a = 1; a <= 9; a++)    /*从0到9穷举字母a的全部可能取值*/

					if (a != p && a != e)

						for (r = 0; r <= 9; r++)    /*从0到9穷举字母r的全部可能取值*/

							if (r != p && r != e && r != a && p * 1000 + e * 100 + a * 10 + r - (a * 100 + r * 10 + a)

								== p * 100 + e * 10 + a)

							{
								printf("   PEAR   %d%d%d%d\n", p, e, a, r);

								printf("  -ARA -   %d%d%d\n", a, r, a);

								printf(".........................\n");

								printf("   PEA   %d%d%d\n", p, e, a);
							}
}