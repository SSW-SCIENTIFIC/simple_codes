/**
* 二分法を用いてsqrt(2) の値を計算する
*/
#include <stdio.h>
#include <math.h>
#include <float.h> /* DBL_EPSILONの定義をロード */

#define TARGET 2.0

int main(void)
{
	int i = 0;
	double lower = 0.0, upper = TARGET, sqrt2;

	while (lower < upper * (1 - DBL_EPSILON)) {
		sqrt2 = (lower + upper) / 2.0;
		printf("%3d %.40f\n", i + 1, sqrt2);

		if (sqrt2*sqrt2 > TARGET) upper = sqrt2;
		else lower = sqrt2;

		i += 1;
	}

	printf("Abs. Err.: %.40f\nRel. Err.: %.40f\n", abs(sqrt2 - M_SQRT2), abs(sqrt2 - M_SQRT2) / M_SQRT2);

	/*
		Abs. Err.: 0.0000000000000000000000000000000000000000
		Rel. Err.: 0.0000000000000000000000000000000000000000
		on Windows
	*/

	return 0;
}