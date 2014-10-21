/* 二分法を用いてSqrt(2) の値を計算する*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 4.0E-16

void calc_sqrt(double x);

int main(int argc, char **argv)
{
	if (argc > 1) calc_sqrt(atof(argv[1]));
	return 0;
}

void calc_sqrt(double x)
{
	double lower = 0.0, upper = x, square_root = x;
	double x0 = x;

	/* fabs(square_root - exact) / exact < EPSILON / 2.0 */
	while (fabs(lower - upper) > EPSILON / 2.0 * fabs(square_root))
	{
		square_root = (lower + upper) / 2.0;

		if (square_root*square_root > x) upper = square_root;
		else lower = square_root;

		printf("%e %e\n", fabs(lower - upper), fabs((lower - upper) / square_root));
	}
	printf("%.16e %.16e\n", square_root,
		fabs(square_root*square_root - x0) / square_root);
	return;
}