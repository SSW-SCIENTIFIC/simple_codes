/* 二分法を用いてSqrt(2) の値を計算する*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calc_sqrt_int_part(double x);

int main(int argc, char **argv)
{
	if (argc > 1) calc_sqrt_int_part(atof(argv[1]));
	return 0;
}

void calc_sqrt_int_part(double x)
{
	double lower = 0.0, upper = x, square_root = x;
	double x0 = x;
	size_t count = 0;

	while (int(upper) != int(lower))
	{
		square_root = (lower + upper) / 2.0;

		if (square_root*square_root > x) upper = square_root;
		else lower = square_root;

		printf("%e %e\n", fabs(lower - upper), fabs((lower - upper) / square_root));
		count++;
	};

	square_root = (lower + upper) / 2.0;
	printf("%d: %d %.16E\n", count, int(lower), sqrt(x) - int(lower));

	/* 平方根が整数近傍の場合に著しく収束性が悪い */

	return;
}