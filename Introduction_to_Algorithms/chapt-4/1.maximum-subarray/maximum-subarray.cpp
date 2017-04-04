// maximum-subarray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct maximum_subarray {
	int start;
	int end;
	int max;
};

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

	
	return 0;
}

