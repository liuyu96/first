
#include <iostream>

template <typename Any>
void Swap(Any &a, Any &b);

template <class Any>
void Swap(Any *a, Any *b, int n);

int main(int argc, char **argv)
{
	using namespace std;
	int a = 10;
	int b = 20;

	cout << "using templete:" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "swap \"a\" and \"b\" using template function \"Swap\"" << endl;
	Swap(a, b); // the parameter is reference, but the argument can be a original type value.
	cout << "a = " << a << " and b = " << b << " after swap" << endl;

	cout << endl << "using overload template:" << endl;

	int m[3] = {1, 2, 3};
	int n[3] = {4, 5, 6};
	cout << "m[]:" << m[0] << " " << m[1] << " " << m[2] << endl;
	cout << "n[]:" << n[0] << " " << n[1] << " " << n[2] << endl;
	Swap(m, n, 3);
	cout << "after swap:" << endl;
	cout << "m[]:" << m[0] << " " << m[1] << " " << m[2] << endl;
	cout << "n[]:" << n[0] << " " << n[1] << " " << n[2] << endl;

	return 0;
}


#if 0
// using "class" is old manner
template <class Any>
#else
// the fashion manner is using "typename"
template <typename Any> // caution: don't end with ";" !
#endif
void Swap(Any &a, Any &b)
{
	Any temp;
	
	temp = a;
	a = b;
	b = temp;
}

template <class Any> // "class" equal to "typename", using "typename" is new manner
void Swap(Any *a, Any *b, int n)
{
	Any temp;

	for (int i = 0; i < n; i++) {
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}
