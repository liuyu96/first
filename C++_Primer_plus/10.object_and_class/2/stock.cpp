#include <iostream>
#include <cstring>
#include "stock.h"

/*inline*/ void Stock::set_tot() // WTF! g++ don't support inline ?!
{
	std::cout << "set_tot" << std::endl;
}

void Stock::acquire(const char *co)
{
	std::strncpy(company, co, 29); // std::strncpy declared in cstring
	company[29] = '\0';
	std::cout << company << std::endl;
}
