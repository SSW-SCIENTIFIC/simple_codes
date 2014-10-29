#include <cstdio>
#include <cmath>
using namespace std;

#define MAX_N 50

inline int sign(size_t x) { return (x & 1) ? -1 : 1; }

class Leibniz
{
private:
	size_t _n;
	double _value;
public:
	Leibniz(size_t n) : _n(0), _value(1.0)
	{
		for (size_t i = 0; i < n; i++)
			next();
	}

	double next()
	{
		double tmp = _value;

		_n++;
		_value += sign(_n) / (2.0 * _n + 1.0);

		return tmp;
	}

	double value() const { return _value; }
	size_t n() const { return _n; }
};

int main()
{
	Leibniz leibniz(0);

	for (size_t i = 0; i < MAX_N; i++)
		printf("%20llu %.16E %.16E\n", i, leibniz.next() * 4.0, (leibniz.value() * 4.0 - M_E) / M_E);

	return 0;
}
