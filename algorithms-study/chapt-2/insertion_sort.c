#include "insertion_sort.h"

int insertion_sort(int *array, int len)
{
	int i, j;
	int key;
	
	if (!array)
		return -1;

	if (len < 0)
		return -1;

	for (j = 1; j < len; j++) {
		key = array[j];
		i = j - 1;
		while(i >= 0 && key < array[i]) {
			array[i + 1] = array[i];
			i--;
		}
		array[i+1] = key;
	}
	return 0;
}
