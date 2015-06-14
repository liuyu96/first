#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW_SIZE 3
#define COL_SIZE 2

int data[ROW_SIZE * COL_SIZE] = {0};

int main(int argc, char **argv)
{
	int *p = data;
	int (*q)[ROW_SIZE]; /* q is a pointer to single dimension array which has 3 elements */
	int i, j;

	/* initialize data */
	for(i = 0; i <= ROW_SIZE * COL_SIZE; i++)
		p[i] = i + 1;

	q = (int (*)[ROW_SIZE])p; /* translate p to a pointer to single dimension array */

	/* print the two dimension array */
	printf("the two dimension array:\n");
	for(i = 0; i < COL_SIZE; i++)
	{
		for(j = 0; j < ROW_SIZE; j++)
			printf("%d ",q[i][j]);
		printf("\n");
	}

	return 0;
}
