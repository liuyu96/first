#include "insertion_sort.h"


int __insertion_sort(int *array, int len)
{
	int i;
	int key;

	if (len <= 1)
		return 0;

	__insertion_sort(array, len - 1);

	key = array[len - 1];
	for (i = len - 2; i >=0; i--) {
		if (key > array[i]) {
			array[i + 1] = key;
			break;
		}
		array[i + 1] = array[i];
	}

	return 0;
}

int insertion_sort(int *array, int len)
{
#if 0
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
#else
	return __insertion_sort(array, len);
#endif
}
