// quick-sort.cpp
//

#include "stdafx.h"

static void print_array(int *a, int start, int end)
{
	for (int i = start; i <= end; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

#define exchange_int_val(_a, _b) do {	\
	int tmp = _a;						\
	_a = _b;							\
	_b = tmp;							\
} while(0)


static int partition(int *a, int start, int end)
{
	int x = a[end];
	int i = start;

	printf("\n");
	for (int j = start; j <= end - 1; j++) {
		if (a[j] <= x) {
			exchange_int_val(a[i], a[j]);
			i++;
		}
		print_array(a, start, end);
	}
	exchange_int_val(a[i], a[end]);
	print_array(a, start, end);

	return i;
}

static int quick_sort(int *a, int start, int end)
{
	if (start < end) {
		int mid = partition(a, start, end);
		quick_sort(a, start, mid - 1);
		quick_sort(a, mid + 1, end);
	}
	return 0;
}

int data[] = {2,8,7,1,3,5,6,4};

int _tmain(int argc, _TCHAR* argv[])
{
	quick_sort(data, 0, 7);

	print_array(data, 0, 7);
	return 0;
}

