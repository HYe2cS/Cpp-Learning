#include<stdio.h>

#include<math.h>

main()

{
	int weight1, weight2, weight3, weight4, d1, d2, d3, d4, x, flag;     /*flag:满
 足题意的标记*/

	printf("The weight is broke up as following 4 pieces:");

	for (weight1 = 1; weight1 <= 40; weight1++)         /*将40分解成4份*/

		for (weight2 = weight1 + 1; weight2 <= 40 - weight1; weight2++)

			for (weight3 = weight2 + 1; weight3 <= 40 - weight1 - weight2; weight3++)

				if ((weight4 = 40 - weight1 - weight2 - weight3) >= weight3)

				{
					for (flag = 1, x = 1; x < 41 && flag; x++)     /*判断可否称出1~40之
   间的全部重量*/

						for (flag = 0, d1 = 1; d1 > -2; d1--)     /*将重物放在天平的左
   边*/

							for (d2 = 1; d2 > -2 && !flag; d2--)   /*1:砝码在天平右边
	*/

								for (d3 = 1; d3 > -2 && !flag; d3--)    /*0：不用该砝码
	 */

									for (d4 = 1; d4 > -2 && !flag; d4--)    /*-1:砝码在天平
		 的左边*/

										if (x == weight1 * d1 + weight2 * d2 + weight3 * d3 + weight4 * d4)

											flag = 1;

					if (flag) printf("%d %d %d %d\n", weight1, weight2, weight3, weight4);

					flag = 0;
				}
}