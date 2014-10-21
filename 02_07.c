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
		printf("%20llu\t%.16f\t%.16E\n", n * i, abs(pow(1.0 + 1.0 / (double(n * i)), (double)(n * i)) - M_E), 1.0 / (double(n * i)));

	/* pow関数の第2引数がint or doubleなのはちょっとアレ */

	return 0;
}
