/* 二分法を用いてSqrt(2) の値を計算する*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int my_mult(unsigned int x, unsigned int y);
unsigned int my_div(unsigned int x, unsigned int y);

int main(int argc, char **argv)
{
	if (argc > 2) printf("%d\n", my_mult((unsigned int)atol(argv[1]), (unsigned int)atol(argv[2])));
	printf("%d\t%d\n", my_mult(5, 255), my_div(255 * 5, 0));
	return 0;
}

unsigned int my_mult(unsigned int x, unsigned int y)
{
	unsigned int base = (x < y) ? y : x, fact = (x < y) ? x : y;
	unsigned int result = 0;

	/* 普通に書くとO(n)なのでO(log(n))程度に計算量を下げる */
	while (fact)
	{
		if (fact & 1) result += base;
		base += base;
		fact >>= 1; /* ビットシフトは違法？ */
	}

	return result;
}

unsigned int my_div(unsigned int x, unsigned int y)
{
	unsigned int result = 0;
	unsigned int div = 0, n = 0;

	if (y == 0)
	{
		printf("ゼロ除算\n");  /* ゼロ除算 */
		exit(0);
	}

	/* 計算量は残念 */
	while (true)
	{
		div += y;
		n++;
		if (x - div == 0)
			return n;
		if (x - div < 0)
		{
			printf("整数上で除算不能\n");  /* 非整数値 */
			exit(0);
		}
	}

	return result;
}