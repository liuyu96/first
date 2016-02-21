#include <stdio.h>
#include <stdlib.h>

#include "insertion_sort.h"
#include "merge_sort.h"

#define ARRAY_SIZE(_a) (sizeof(_a) / sizeof(_a[0]))

int main(int argc, char **argv)
{
	int a[] = {5, 2, 4, 6, 1, 3, 8, 9, 12, 100, 67, 52, 32, 62, 70, 88, 888, 66};
	int i;
	int len = ARRAY_SIZE(a);
	int ret;

	printf("array a:\n");
	for (i = 0; i < len; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	if (argc < 2) {
		printf("must specify a method\n");
		return -1;
	}

	if (!strncmp(argv[1], "insertion", strlen("insertion"))) {
		ret = insertion_sort(a, len);
	} else if (!strncmp(argv[1], "merge", strlen("merge"))) {
		ret = merge_sort(a, 0, len - 1);
	} else {
		printf("no sort method\n");
	}
	printf("sort ret %d\n", ret);


	printf("array a after sort:\n");
	for (i = 0; i < len; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
