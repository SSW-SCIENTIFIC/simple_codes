#include <stdio.h>

#define N 30

int main(void)
{
	unsigned long a = 1, b = 1, c = 0;
	int i;

	for (i = 1; i <= N; i++)
	{
		c += i * b;
		a = (i % 3 == 0) ? i : 1;
		b = 2 * b + a;
	}
	printf("%lu", c);

	return 0;
}

