#include <iostream>
#include <string>

class Stock
{
private:
	std::string m_company;
public:
	Stock();
	Stock(const char *co);
	~Stock();
	void show();
};
