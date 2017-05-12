// namesp.h
// create the pers and debts namespaces

namespace pers
{

const int LEN = 40;
struct Person
{
	char fname[LEN];
	char lname[LEN];
};

void getPerson(Person &);

void showPerson(Person &);

}

namespace debts
{

using namespace pers;

struct Debt
{
	Person name;
	double amount;
};

void getDebt(Debt &);

void showDebt(Debt &);

double sumDebt(const Debt ar[], int n);

}

