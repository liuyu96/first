#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int *p;
	int (*q)[3];
	int i,j;

	p=(int *)malloc(sizeof(int)*6);
	
	for(i=0;i<=6;i++)
		p[i]=i+1;

	q=(int (*)[3])p;

	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
			printf("%d\n",q[i][j]);
		printf("\n");
	}

	return 0;
}