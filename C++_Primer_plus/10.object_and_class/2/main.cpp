#include <iostream>
#include "stock.h"

int main(int argc, char **argv)
{
	Stock stock1;
	stock1.acquire("NanaSmart");
	stock1.set_tot();
	stock1._set_tot();
	return 0;
}
