#include <iostream>
#include <cstring>

class Stock
{
private:
	char m_name[30];
public:
	Stock(void);
	Stock(const char *name);
	~Stock(void);
	void show();
};
