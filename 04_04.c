#include <stdio.h>
#include <float.h>
#include <math.h>

#define TARGET 2.0

double my_log(double x);

int main(void)
{
	printf("Calc. Val.: %.16f\n", my_log(TARGET));
	printf("Exct. Val.: %.16f\n", log(TARGET));
	printf("Abs. Err. : %.16E\n", abs(my_log(TARGET) - log(TARGET)));
	printf("Rel. Err. : %.16E\n", abs((my_log(TARGET) - log(TARGET)) / log(TARGET)));
	/* Exact: 0.693147180559945309417232121458176568075500134360255254120680... */

	return 0;
}

/* Calc log(x) by Newton Method */
/* xが大きい領域で極端に収束性が悪化 */
/* xが小さい領域でNewton法, 大きい場合に2分法で計算すべきか */

double my_log(double x)
{
	double val = x, temp, temp2;
	unsigned long count = 0;


	/* x <= 0.0の場合の例外処理 */
	if (x == 0.0)
		return -INFINITY;
	if (x < 0.0)
		return NAN;

	do
	{
		temp = val;
		temp2 = exp(val);
		val -= (temp2 - x) / temp2;
		count++;
	} while (abs(temp - val) > DBL_EPSILON * abs(val));

	//	printf("Repitation: %d\n", count);

	return val;
}
