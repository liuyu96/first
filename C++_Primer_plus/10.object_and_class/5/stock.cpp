#include <iostream>
#include <cstring>
#include "stock.h"

Stock::Stock(void)
{
	std::strcpy(m_name, "no name");
	std::cout << m_name << std::endl;
}

Stock::Stock(const char *co)
{
	std::strcpy(m_name, co);
	std::cout << m_name << std::endl;
}

Stock::~Stock()
{
}

void Stock::show()
{
	std::cout << m_name << std::endl;
}
