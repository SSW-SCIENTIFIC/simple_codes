#include <stdio.h>
#include <limits.h>
#include <math.h>

#define MAX_N ULLONG_MAX
#define POW_BASE 10

double pow_ll(double base, unsigned long long pow);

int main(void)
{
	unsigned long long n = 1;
	int i = 1;

	/* Calculate (1 + 1/n)^n */
	while ((n *= POW_BASE) <= MAX_N / 2) /* オーバーフロー回避 */
		printf("%20llu\t%.16f\t%.16E\n", n * i, abs(pow_ll(1.0 + 1.0 / (double(n * i)), n * i) - M_E), 1.0 / (double(n * i)));

	return 0;
}

double pow_ll(double base, unsigned long long pow)
{
	double value = 1.0;

	/* O(log(n))の整数指数計算 */
	do {
		if (pow & 1) value *= base;
		pow >>= 1;
		base *= base;
	} while (pow);

	return value;
}
