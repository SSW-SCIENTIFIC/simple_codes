#include <stdio.h>

unsigned long long binomial(unsigned int n, unsigned int m);

int main(void)
{
	printf("%lld\n", binomial(5, 3));

	return 0;
}

unsigned long long binomial(unsigned int n, unsigned int m)
{
	if (!(0 < m && m < n)) return 1;
	return (binomial(n - 1, m - 1) / m) * n;
}
