#include <stdio.h>
#include <stdlib.h>

#include "insertion_sort.h"

#define ARRAY_SIZE(_a) (sizeof(_a) / sizeof(_a[0]))

int main(int argc, char **argv)
{
	int a[] = {5, 2, 4, 6, 1, 3};
	int i;
	int len = ARRAY_SIZE(a);
	int ret;

	printf("---> main\n");
	printf("array a:\n");
	for (i = 0; i < len; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");


	ret = insertion_sort(a, len);
	printf("insertion sort ret %d\n", ret);


	printf("array a after sort:\n");
	for (i = 0; i < len; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
