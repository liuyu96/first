//
#include <iostream>

inline double square(double x)
{
	return x * x;
}

int main(int argc, char **argv)
{
	using namespace std;
	double a = 5.0;
	double b;

	b = square(a);

	cout << "a = " << a << endl << "a * a = " << b << endl;

	return 0;
}
