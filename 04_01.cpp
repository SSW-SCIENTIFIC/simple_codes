#include <cstdio>
#include <cmath>
using namespace std;

#define MAX_N 50

class HalfAngle
{
private:
	double _l;
	double _L;
	size_t _n;

public:
	HalfAngle() : _l(4.0 * sin(M_PI / 4.0)), _L(4.0 * tan(M_PI / 4.0)), _n(4) {  }
	void next()
	{
		_l = sqrt(2.0) * _l / sqrt(1.0 + sqrt(1.0 - (_l / _n) * (_l / _n)));
		_L = 2 * _L / (sqrt(1.0 + (_L / _n) * (_L / _n)) + 1);
		_n <<= 1;
	}

	double l() const { return _l; }
	double L() const { return _L; }
	size_t n() const { return _n; }
};

int main()
{
	HalfAngle ha;

	for (size_t i = 0; i <= MAX_N; i++)
	{
		printf("%20lld %.16E %.16E\n", ha.n(), ha.l(), ha.L());
		ha.next();
	}

	return 0;
}
