#include <stdio.h>

#define MAX_LEN 512
int left[MAX_LEN], right[MAX_LEN];

int merge(int *array, int start, int mid, int end)
{
	int left_len, right_len;
	int i, j, k;
	int n;


	if (start < 0 || mid < 0 || end < 0 || !array) {
		printf("%s: invalid arguments\n", __func__);
		return -1;
	}
	
	if ((end - start + 1) > MAX_LEN) {
		printf("%s: too long\n", __func__);
		return -1;
	}

	left_len = mid - start + 1;
	right_len = end - mid;
	
	for (i = 0; i < left_len; i++) {
		left[i] = array[start + i];
	}
	
	for (i = 0; i < right_len; i++) {
		right[i] = array[mid + i + 1];
	}

	i = 0;
	j = 0;
#if 1
	for (k = start; k <= end; k++) {
		if (left[i] < right[j]) {
			array[k] = left[i];
			i++;
		} else {
			array[k] = right[j];
			j++;
		}

		if ((i >= left_len) || (j >= right_len))
			break;
	}
	
	if (i >= left_len)
		for (; j < right_len; j++)
			array[++k] = right[j];
	else if (j >= right_len)
		for (; i < left_len; i++)
			array[++k] = left[i];
#else
	for (k = start; k <= end; k++) {
		if ((i < left_len) && (j < right_len))
			if (left[i] < right[j]) {
				array[k] = left[i];
				i++;
			} else {
				array[k] = right[j];
				j++;
			}
		else if (i < left_len)
			array[k] = left[i++];
		else
			array[k] = right[j++];
	}
#endif
	return 0;
}


int __merge_sort(int *array, int start, int end)
{
	int mid;
	if (start < end) {
		mid = (start + end) / 2;
		__merge_sort(array, start, mid);
		__merge_sort(array, mid + 1, end);
		merge(array, start, mid, end);
	}
	return 0;
}


int merge_sort(int *array, int len)
{
	return __merge_sort(array, 0, len - 1);
}
