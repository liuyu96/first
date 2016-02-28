#include <stdio.h>

int binary_search_recursive(int *a,int key,int low,int high)
{
	int mid;

	if(low > high)
		return -1;

	mid = (low + high)/2;
	if(a[mid] == key)
		return mid;
	else if(a[mid] > key)
		return binary_search_recursive(a,key,low,mid -1);
	else
		return binary_search_recursive(a,key,mid + 1,high);
}

int binary_search(int *a, int key, int n )
{
#if 0
	int left = 0, right = n - 1, mid = 0;

	mid = (left + right) / 2;
	while( left < right && a[mid] != key ) {
		if( a[mid] < key )
			left = mid + 1;
		else if( a[mid] > key )
			right = mid - 1;
		mid = ( left + right ) / 2;
	}
	if( a[mid] == key )
		return mid;
	return -1;
#else	
	binary_search_recursive(a, key, 0, n - 1);
#endif
}


//int a[] = {2, 4, 5, 7, 9, 11};
int a[] = {1, 1, 2, 3, 4, 5, 5, 7, 9, 11};
#define ARRAY_SIZE(_x) (sizeof(_x)/sizeof(_x[0]))

int main(int argc, char**argv)
{
	int key = 1;
	int ret;
	int i;

	for (i = 0; i < ARRAY_SIZE(a); i++)
		printf("%d ", a[i]);
	printf("\n");

	if (argc > 1)
		key = atoi(argv[1]);

	ret = binary_search(a, key, ARRAY_SIZE(a));
	if (ret < 0)
		printf("find %d failed!\n", key);
	else
		printf("find %d index %d\n", key, ret);

	return 0;
}
