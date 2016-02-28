#include <stdio.h>

int choose_sort(int *array, int len)
{
	int i, j, min_idx;
	int tmp;

	if (!array || len <= 0) {
		printf("ilegal array!\n");
		return -1;
	}

	for (i = 0; i < len - 1; i++) {
		for (min_idx = j = i; j < len; j++) {
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		//printf("min_idx %d, min %d\n", min_idx, array[min_idx]);

		if (i == min_idx)
			continue;

		tmp = array[i];
		array[i] = array[min_idx];
		array[min_idx] = tmp;
	}	
	return 0;
}
