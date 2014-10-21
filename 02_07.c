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
	while ((n *= POW_BASE) <= MAX_N / 2) /* �����С��ե����� */
		printf("%20llu\t%.16f\t%.16E\n", n * i, abs(pow(1.0 + 1.0 / (double(n * i)), (double)(n * i)) - M_E), 1.0 / (double(n * i)));

	/* pow�ؿ�����2������int or double�ʤΤϤ���äȥ��� */

	return 0;
}
