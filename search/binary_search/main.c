#include <stdio.h>
#include "binary_search.h"

#define ARRAY_SIZE 20

int array[ARRAY_SIZE];


int main(int argc, char **argv)
{
	int i, j, mid = -1;
	int search_val = 6;

	for (i = 0; i < ARRAY_SIZE; i++) {
		array[i] = i * 2 + 4;
		printf("array[%d]: %d\n", i, array[i]);
	}

	for (j = -4; j < 22; j++) {
		printf("search for %d\n", j);
		mid = -1;
		
		//
		__binary_search(0, (11), array, j, mid);
		if (mid >= 0)
			printf("found:array[%d]: %d\n", mid, array[mid]);
		else
			printf("not found\n");
		
		//
		mid = binary_search_recursive(array, j, 0, ARRAY_SIZE - 1);
		if (mid >= 0)
			printf("found:array[%d]: %d\n", mid, array[mid]);
		else
			printf("not found\n");
		
		//
		mid = binary_search(array, j, 0, ARRAY_SIZE - 1);
		if (mid >= 0)
			printf("found:array[%d]: %d\n", mid, array[mid]);
		else
			printf("not found\n");
	}

	return 0;
}