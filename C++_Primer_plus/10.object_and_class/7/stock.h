#include <iostream>
#include <cstring>

class Stock
{
private:
	#if 0
	enum {Len = 30};
	#else
	static const int Len = 30;
	#endif
	char m_name[Len];
public:
	Stock(void);
	Stock(const char *name);
	~Stock(void);
	void show();
};
