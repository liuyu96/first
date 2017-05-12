
class Stock
{
private:
	char m_company[30];
public:
	Stock(void);
	Stock(const char *co);
	~Stock();
	void acquire(const char *co);
	void show() const; // this const member function, this function never modify member
};
