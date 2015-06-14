#include <stdio.h>
//µİ¹éËã·¨
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

//·Çµİ¹éËã·¨
int binary_search( int *a, int key, int n )
{
	int left = 0, right = n - 1, mid = 0;

	mid = ( left + right ) / 2;
	while( left < right && a[mid] != key )
	{
		if( a[mid] < key )
			left = mid + 1;
		else if( a[mid] > key )
			right = mid - 1;
		mid = ( left + right ) / 2;
	}
	if( a[mid] == key )
		return mid;
	return -1;
}