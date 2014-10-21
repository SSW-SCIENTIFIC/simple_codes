#include <stdio.h>
#include <limits.h>
#include <math.h>

#define MAX_N LLONG_MAX
#define MAX_FACT 170 /* これを超えるとdoubleでもオーバーフロー */

double pow_ll(double base, long long pow);
double my_fact(unsigned int n);

int main(void)
{
	double n = 1;
	int i = 1;

	/* Calculate Sum[k = 1, n] 1/k! */
	double result = 0;
	unsigned int j = 0;
	do
	{
		result += 1.0 / my_fact(j);
		printf("%2d\t%.16f\t%.16E\n", j, abs(result - M_E), my_fact(j));
		j++;
	} while (j < MAX_N && j <= MAX_FACT);
	//	*/

	return 0;
}

double my_fact(unsigned int n)
{
	/* 再帰で実装してみる                                             */
	/* アセンブラ読んでみるとcallされてたので末尾最適化されないっぽい */
	if (n == 0) return 1.0;
	else return double(n) * my_fact(n - 1);
}
