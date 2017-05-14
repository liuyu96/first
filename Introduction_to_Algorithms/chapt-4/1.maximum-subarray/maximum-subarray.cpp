// maximum-subarray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct maximum_crossing_subarray {
	//int left_sum;
	int max_left;
	//int right_sum;
	int max_right;
	int sum;
};

struct maximum_subarray {
	int start;
	int end;
	int max;
};


static void find_max_crossing_subarray(int *arr, int low, int mid, int high,
			struct maximum_crossing_subarray *max)
{
	int i;
	int sum;
	int left_sum;
	int max_left;

	sum = 0;
	left_sum = arr[mid];
	max_left = mid;
	for (i = mid; i >= low; i--) {
		sum += arr[i];
		if (sum > left_sum) {
			left_sum = sum;
			max_left = i;
		}
	}

	int right_sum;
	int max_right;

	sum = 0;
	right_sum = arr[mid + 1];
	max_right = mid + 1;
	for (i = mid + 1; i <= high; i++) {
		sum += arr[i];
		if (sum > right_sum) {
			right_sum = sum;
			max_right = i;
		}
	}

	max->max_left = max_left;
	max->max_right = max_right;
	max->sum = left_sum + right_sum;
}


static void find_max_subarray(int *arr, int low, int high, struct maximum_subarray *max)
{
	if (low == high) {
		max->start = low;
		max->end = high;
		max->max = arr[low];
		return;
	}

	struct maximum_subarray left_max, right_max;
	struct maximum_crossing_subarray max_cross;

	int mid = (low + high) / 2;

	find_max_subarray(arr, low, mid, &left_max);
	find_max_subarray(arr, mid + 1, high, &right_max);
	find_max_crossing_subarray(arr, low, mid, high, &max_cross);

	if ((left_max.max > right_max.max) && (left_max.max > max_cross.sum)) {
		max->start = left_max.start;
		max->end = left_max.end;
		max->max = left_max.max;
	} else if ((right_max.max > left_max.max) && (right_max.max > max_cross.sum)) {
		max->start = right_max.start;
		max->end = right_max.end;
		max->max = right_max.max;
	} else {
		max->start = max_cross.max_left;
		max->end = max_cross.max_right;
		max->max = max_cross.sum;
	}
}

/* ********************************************************************************** */

/*
 * Divide and Conquer solution
 */

static int get_max_subarray(int *a, int len, struct maximum_subarray *max_sub_array)
{
	/* TODO: ...... */
	return 0;
}


/*
 * force search solution
 */
static int find_maximum_subarray(int *a, int len, struct maximum_subarray *max_subarray)
{
	int max, tmp;
	int i, j;

	if (!a || len <= 1 || !max_subarray) {
		printf("invalid args\n");
		return -1;
	}

	max = a[0] + a[1];
	max_subarray->start = 0;
	max_subarray->end = 1;

	for (i = 0; i < len; i++) {
		tmp = a[i];
		for (j = i + 1; j < len; j++) {
			tmp += a[j];
			if (tmp > max) {
				max = tmp;
				max_subarray->start = i;
				max_subarray->end = j;
			}
		}
	}

	max_subarray->max = max;

	return 0;
}

/* ********************************************************************************** */

static int a[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

int _tmain(int argc, _TCHAR* argv[])
{
	int len = sizeof(a)/sizeof(a[0]);
	int ret;
	struct maximum_subarray max_subarray;

	ret = find_maximum_subarray(a, len, &max_subarray);

	printf("start %d, end %d, max %d\n", max_subarray.start,
		max_subarray.end, max_subarray.max);

	find_max_subarray(a, 0, len - 1, &max_subarray);
	printf("start %d, end %d, max %d\n", max_subarray.start,
		max_subarray.end, max_subarray.max);

	return 0;
}

