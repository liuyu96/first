#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "insertion_sort.h"

#define ARRAY_SIZE(_a) (sizeof(_a) / sizeof(_a[0]))

int raw[] = {5, 2, 4, 6, 1, 3, 8, 9, 12, 100, 67, 52, 32, 62, 70, 88, 888, 66};

extern int merge_sort(int *, int);
extern int choose_sort(int *, int);

void print_int_array(char *name, int *array, int len)
{
	int i;
	if (!array || len <= 0) {
		printf("ilegal array!\n");
		return;
	}

	if (name)
		printf("array %s:\n", name);

	for (i = 0; i < len; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	int i;
	int len = ARRAY_SIZE(raw);
	int ret;
	int *a = malloc(sizeof(a));

	memcpy(a, raw, sizeof(raw));

	print_int_array("a", a, len);

	ret = insertion_sort(a, len);
	if (ret)
		printf("insertion sort failed!\n");
	print_int_array("after insertion sort", a, len);


	memcpy(a, raw, sizeof(raw));
	print_int_array("a", a, len);
	ret = merge_sort(a, len);
	if (!ret)
		print_int_array("after merge sort", a, len);


	memcpy(a, raw, sizeof(raw));
	ret = choose_sort(a, len);
	if (!ret)
		print_int_array("after choose sort", a, len);
	
	return 0;
}
