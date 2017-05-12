#include <iostream>
//#include <cstring>

class Stock
{
private:
	char company[30];
public:
	void acquire(const char *co);

	void set_tot();

	void _set_tot() // defined in class, auto become inline function
	{
		std::cout << "_set_tot\n";
	}
};
