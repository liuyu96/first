#include <iostream>
#include <string>
#include "stock.h"

Stock::Stock()
{
	m_company = "no name";
	std::cout << m_company << std::endl;
}

Stock::Stock(const char *co)
{
	m_company = co;
	std::cout << m_company << std::endl;
}

Stock::~Stock()
{
	std::cout << m_company << " destruct\n";
}

void Stock::show()
{
	std::cout << "show " << m_company << std::endl;
}
