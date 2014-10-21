/**
* ��ʬˡ���Ѥ���sqrt(2) ���ͤ�׻�����
*/
#include <stdio.h>
#include <math.h>
#include <float.h> /* DBL_EPSILON���������� */

#define TARGET 2.0

int main(void)
{
	int i = 0;
	double lower = 0.0, upper = TARGET, sqrt2;

	while (lower < upper * (1 - DBL_EPSILON)) {
		sqrt2 = (lower + upper) / 2.0;
		printf("%3d %.40f\n", i + 1, sqrt2);

		if (sqrt2*sqrt2 > TARGET) upper = sqrt2;
		else lower = sqrt2;

		i += 1;
	}

	return 0;
}