#include <stdio.h>

#define MAX_N 67

int main(void)
{
	unsigned long results[MAX_N + 1];
	int i, j, n;

	/* Initialization */
	for (i = 0; i <= MAX_N; i++)
		results[i] = 0;

	printf("Input n for combination nCr: ");
	scanf("%d", &n);

	/* Input Range Check */
	if (n > MAX_N)
	{
		printf("Overflow. ");
		return 0;
	}
	else if (n < 0)
	{
		printf("Underflow. ");
		return 0;
	}

	/* Iterative Calculation */
	for (i = 0; i <= n; i++)
		for (j = i; j >= 0; j--)
			results[j] = (j == 0 || j == i) ? 1 : results[j - 1] + results[j];

	/* Output Results */
	for (i = 0; i <= n; i++)
		printf("%lu\n", results[i]);

	return 0;
}

