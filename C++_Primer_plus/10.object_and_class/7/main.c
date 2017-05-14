#include <iostream>
#include "stock.h"

int main(void)
{
	std::cout << "-------- object array\n";

	Stock stocks[5];
	stocks[0].show();
	
	std::cout << "-------- object array with initialize\n";
	Stock other_stocks[5] = {
		Stock("nano smart"),
		Stock("micro smart"),
	};

	return 0;
}
