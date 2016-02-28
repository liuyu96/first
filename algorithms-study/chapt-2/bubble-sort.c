
#include <stdio.h>

int bubble_sort(int *array, int len)
{
	int i, j;
	int tmp;

	if (!array || len <=0)
		return -1;

	for (i = 0; i < len - 1; i++) {
		for (j = len - 1; j > i; j--) {
			if (array[j] < array[j - 1]) {
				tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
			}
		}
	}

	return 0;
}
