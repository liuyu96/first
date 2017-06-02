#include <iostream>
#include "mytime.h"

int main(int argc, char **argv)
{
	Time t1(2, 40);
	Time t2(5, 55);
	Time total;

	total = t1.operator+(t2);
	total.show();

	total = t1 + t2;
	total.show();
}
