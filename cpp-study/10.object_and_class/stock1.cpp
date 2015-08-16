#include <iostream>
#include <cstring>
#include "stock1.h"

Stock::Stock()
{
	std::cout << "Default constructor called\n";
	std::strcpy(company, "no name");
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const char * co, int n, double pr)
{
	std::cout << "Constructor using " << co << " called\n";
	std::strcpy(company, co);
	company[29] = '\0';

	if (n < 0)
	{
		std::cerr << "Number of shares can't be negative\n";
		shares = 0;
	}
	else
	{
		shares = n;
	}

	share_val = pr;
	set_tot();
}


Stock::~Stock()
{
	std::cout << "Bye, " << company << " !\n";
}

void Stock::buy(int num, double price)
{
	if (num < 0)
	{
		std::cerr << "Number of shares purchased can't be negative\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(int num, double price)
{
	using std::cerr;

	if (num < 0)
	{
		cerr << "Number can't be negative\n";
	}
	else if (num > shares)
	{
		cerr << "You can't sell more than you have\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

void Stock::show()
{
	using std::cout;
	using std::endl;

	cout << "Company: " << company << " Shares: " << shares << endl
		<< "Share price: " << share_val << " Total Worth: $" << total_val << endl;
}

const Stock & Stock::topval(const Stock & s)
{
	if (s.total_val > total_val)
		return s;
	else
		*this; // 运用了this指针
}
