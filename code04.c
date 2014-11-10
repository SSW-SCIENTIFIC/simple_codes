#include <stdio.h>
#include <math.h>

#define MAX_N 100000
#define MAX_EFF_N (MAX_N / 2)

void Eratosthenes(char sieve[]);
void print_prime_triplet(char sieve[]);

int main(void)
{
	char sieve[MAX_EFF_N];
	
	Eratosthenes(sieve);
	print_prime_triplet(sieve);

	return 0;
}

void Eratosthenes(char sieve[])
{
	size_t i, j;
	const size_t sqrt_n = (size_t)sqrt(MAX_EFF_N);

	for (i = 0; i < MAX_EFF_N; i++)
		sieve[i] = 1;

	for (i = 0; i < sqrt_n; i++)
		if (sieve[i])
			for (j = i + (i + i + 3); j < MAX_EFF_N; j += i + i + 3)
				sieve[j] = 0;
}

void print_prime_triplet(char sieve[])
{
	size_t i;

	for (i = 0; i < MAX_EFF_N - 3; i++)
		if (sieve[i] & sieve[i + 1] & sieve[i + 3]) printf("%d,%d,%d\n", i + i + 3, i + i + 5, i + i + 9);
		else if (sieve[i] & sieve[i + 2] & sieve[i + 3]) printf("%d,%d,%d\n", i + i + 3, i + i + 7, i + i + 9);
}
