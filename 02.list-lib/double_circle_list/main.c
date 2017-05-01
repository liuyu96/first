
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node {
	int data;
	struct node *next;
	struct node *prev;
};

struct node head;

int create_list(struct node *head, int node_num)
{
	int i;
	struct node *new_node;

	if (!head)
		return -1;

	INIT_LIST_HEAD((head), prev, next);

	for (i = 0; i < node_num; i++) {
		new_node = (struct node *)malloc(sizeof(*new_node));
		new_node->data = i;
		LIST_ADD_TAIL(new_node, head, prev, next);
	}

	return 0;
}

int main(int argc, char **argv)
{
	printf("Hello world!\n");
	return 0;
}
