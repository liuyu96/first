#include <iostream>
#include <cstring>
#include "stock.h"

Stock::Stock(void)
{
	std::strncpy(m_company, "NoName", 29);
	std::cout << m_company << " constructor" << std::endl;
}

Stock::Stock(const char *co)
{
	std::strncpy(m_company, co, 29);
	std::cout << m_company << " constructor with parameter" << std::endl;
}

Stock::~Stock()
{
	std::cout << m_company << " destructor" << std::endl;
}

void Stock::acquire(const char *co)
{
	std::strncpy(m_company, co, 29);
	std::cout << m_company << " acquire" << std::endl;
}

void Stock::show() const
{
	std::cout << m_company << " show" << std::endl;
}
