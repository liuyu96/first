#ifndef _BINARY_SEARCH_H_
#define _BINARY_SEARCH_H_
#include <stdio.h>

#define __binary_search(start, end, array, key, key_index) do {						\
		int __i, __j, __mid;									\
		__i = (start);										\
		__j = (end);										\
		while (__i <= __j) {									\
			__mid = (__i + __j) / 2;							\
			if (key == array[__mid]) {									\
				(key_index) = __mid;									\
				printf("found: array[%d], %d\n", __mid, array[__mid]);					\
				break;											\
			} else if (key < array[__mid]) {								\
				__j = __mid - 1;									\
			} else {											\
				__i = __mid + 1;									\
			}												\
		}													\
	} while (0)

int binary_search_recursive(int *a, int key, int low, int high);
int binary_search(int *a, int key, int n);
#endif /* _BINARY_SEARCH_H_ */
