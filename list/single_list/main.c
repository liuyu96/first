
/*
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "single-list.h"

extern int create_destroy_list(int length);
extern int search_node(int list_len, int search_val);
extern int insert_node(int list_len, int insert_val, int position_val);
extern int del_node(int list_len, int del_val);
extern int insert_sort(int list_len);

int main(int argc, char **argv)
{

#if 0
	create_destroy_list(10);
#endif

#if 0
	printf(">>>> search_node(10, 9);\n");
	search_node(10, 9);
	printf(">>>> search_node(0, 9);\n");
	search_node(1, 9);
	printf(">>>> search_node(1, 9);\n");
	search_node(1, 9);
	printf(">>>> search_node(2, 9);\n");
	search_node(2, 9);
	printf(">>>> search_node(3, 9);\n");
	search_node(3, 9);
#endif

#if 0
	printf(">>>> search_node(1, 0);\n");
	search_node(1, 0);
	printf(">>>> search_node(2, 0);\n");
	search_node(2, 0);
	printf(">>>> search_node(2, 1);\n");
	search_node(2, 1);
	printf(">>>> search_node(3, 1);\n");
	search_node(3, 1);
	printf(">>>> search_node(3, 2);\n");
	search_node(3, 2);
	printf(">>>> search_node(3, 0);\n");
	search_node(3, 0);
#endif

#if 0
	printf(">>>>\n");
	insert_node(10, 20, 8);
	printf(">>>>\n");
	insert_node(10, 20, 18);
	printf(">>>>\n");
	insert_node(0, 20, 0);
	printf(">>>>\n");
	insert_node(1, 20, 0);
#endif
#if 0
	printf(">>>>\n");
	del_node(10, 0);
	printf(">>>>\n");
	del_node(10, 11);
	printf(">>>>\n");
	del_node(1, 0);
#endif
#if 1
	printf(">>>>\n");
	insert_sort(10);
	printf(">>>>\n");
	insert_sort(0);
	printf(">>>>\n");
	insert_sort(1);
	printf(">>>>\n");
	insert_sort(2);
	printf(">>>>\n");
	insert_sort(3);
	printf(">>>>\n");
	insert_sort(4);
#endif
	return 0;
}
