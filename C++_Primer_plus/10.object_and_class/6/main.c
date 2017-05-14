#include <iostream>
#include <string>
#include "stock.h"

int main()
{
	Stock stock1;
	Stock stock2 = Stock("nano smart");

	stock1.show();
	stock2.show();

	return 0;
}
