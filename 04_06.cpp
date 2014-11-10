#include <stdio.h>
#include <math.h>
#include <float.h>

double my_exp(double x);
double my_fact(size_t n);

int main(void)
{
	double dt = 1E-3;
	double t_f = 1.0;

	for (size_t i = 0; i * dt <= t_f; i++)
	{
		double val = my_exp(dt * i);
		printf("%.3f %.16E %.16E\n", dt * i, val, (val - M_E) / M_E);
	}

	return 0;
}

double my_exp(double x)
{
	double value = 0.0;

	for (size_t n = 0; 2.8 / my_fact(n) * pow(abs(x), (double)n) >= DBL_EPSILON; n++)
		value += pow(x, double(n)) / my_fact(n);
	
	return 0;
}

double my_fact(size_t n)
{
	if (n == 0) return 1.0;
	else return my_fact(n - 1);
}
