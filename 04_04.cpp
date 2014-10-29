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
class Machin
{
private:
	size_t _n;
	double _value;
public:
	Machin(size_t n) : _n(0), _value(4.0 * (1.0 / 5.0 - 1.0 / (3.0 * 5.0 * 5.0 * 5.0) + 1.0 / (5.0 * 5.0 * 5.0 *5.0 * 5.0 * 5.0)) - 1.0/239.0)
	{
		for (size_t i = 0; i < n; i++)
			next();
	}

	double next()
	{
		double tmp = _value;

		_n++;
		_value += 4.0 * (sign(3 * _n) * (6.0 * _n + 3.0) * (6.0 * _n + 5.0) * 625.0 + sign(3 * _n + 1) * (6.0 * _n + 1.0) * (6.0 * _n + 5.0) * 25.0 + sign(3 * _n + 2) * (6.0 * _n + 1.0) * (6.0 * _n + 3.0)) / ((6.0 * _n + 1.0) * (6.0 * _n + 3.0) * (6.0 * _n + 5.0) * pow(5.0, 6 * _n + 5.0)) - sign(_n) / ((2.0 * _n + 1.0) * pow(239.0, 2.0 * _n + 1.0));

		return tmp;
	}

	double value() const { return _value; }
	size_t n() const { return _n; }
};

int main()
{
	Leibniz leibniz(0);
	Machin machin(0);

	for (size_t i = 0; i < MAX_N; i++)
		printf("%20llu %.16E %.16E\n", i, abs((leibniz.next() * 4.0 - M_PI) / M_PI), abs((machin.next() * 4.0 - M_PI) / M_PI));

	return 0;
}
