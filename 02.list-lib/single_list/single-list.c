
#include <stdlib.h>
#include <stdio.h>
#include "single-list.h"

struct nd {
	struct nd * n;
	int data;
};


struct my_node {
	struct nd * next;
	int data;
	int data2;
};


void single_list_init_head(struct nd *head)
{
	head->n = NULL;
}

int my_func(void)
{
	struct nd head;
	struct my_node head2;

	SINGLE_LIST_INIT_HEAD((&head), n);
	SINGLE_LIST_INIT_HEAD((&head2), next);


	single_list_init_head(&head);
}


/*
 * create and destroy single list
 */
int create_destroy_list(int length)
{
	struct nd head;
	struct nd *p;
	struct nd *prev, *pos;
	int i;
printf("[%s]+\n", __FUNCTION__);

	#if 0
	head.data = 0;
	head.n = NULL;
	#else
	SINGLE_LIST_INIT_HEAD((&head), n);
	#endif

	/* create list */
	for (i = 0; i < length; i++) {
		p = malloc(sizeof(struct nd));
		if (!p)
			break;
		p->data = i;
		#if 0
		single_list_add(p, (&head), n);
		#else
		single_list_add_tail(p, prev, pos, (&head), n);
		#endif
	}
printf("------------------\n");
	/* print list */
	i = 0;
	single_list_for_each(prev, pos, (&head), n) {
		printf("node %d: %d\n", i, pos->data);
		i++;
	}
printf("------------------\n");
	/* print list again */
	i = 0;
	single_list_for_each_lite(pos, (&head) ,n) {
		printf("node %d: %d\n", i, pos->data);
		i++;
	}
printf("------------------\n");
	/* destroy list */
	i = 0;
	while ((&head)->n != NULL) {
		single_list_del_first_node(pos, (&head), n);
		if (pos != NULL) {
			printf("free node %d, %d\n", i, pos->data);
			free(pos);
			i++;
		}
	}
printf("[%s]-\n", __FUNCTION__);
	return 0;
}

/*
 * search node
 */
int search_node(int list_len, int search_val)
{
	struct nd head;
	struct nd *p;
	struct nd *prev, *pos;
	int i;
	int ret;

	SINGLE_LIST_INIT_HEAD((&head), n);

	/* create list */
	for (i = 0; i < list_len; i++) {
		p = malloc(sizeof(struct nd));
		if (!p)
			break;
		p->data = i;
		single_list_add_tail(p, prev, pos, (&head), n);
	}
printf("------------------\n");
	/* print list */
	i = 0;
	single_list_for_each(prev, pos, (&head), n) {
		printf("node %d: %d\n", i, pos->data);
		i++;
	}
printf("------------------\n");
	single_list_search_node(prev, pos, (&head), n, (pos->data == search_val), ret);
	if (ret == 0 && pos != NULL) {
		printf("found node: %d\n", pos->data);
	} else {
		printf("not found\n");
	}
	
printf("------------------\n");
	/* destroy list */
	i = 0;
	while ((&head)->n != NULL) {
		single_list_del_first_node(pos, (&head), n);
		if (pos != NULL) {
			printf("free node %d, %d\n", i, pos->data);
			free(pos);
			i++;
		}
	}
	return 0;
}



/*
 * insert
 */
int insert_node(int list_len, int insert_val, int position_val)
{
	struct nd head;
	struct nd *p;
	struct nd *prev, *pos;
	int i;
	int ret;

	SINGLE_LIST_INIT_HEAD((&head), n);

	/* create list */
	for (i = 0; i < list_len; i++) {
		p = malloc(sizeof(struct nd));
		if (!p)
			break;
		p->data = i;
		single_list_add_tail(p, prev, pos, (&head), n);
	}
printf("------------------\n");
	/* print list */
	i = 0;
	single_list_for_each(prev, pos, (&head), n) {
		printf("node %d: %d\n", i, pos->data);
		i++;
	}
printf("------------------\n");

	p = malloc(sizeof(struct nd));
	if (p) {
		p->data = insert_val;
		p->n = NULL;

		single_list_add_before(p, prev, pos, (&head), n, (pos->data == position_val), ret);
		if (ret == 0) {
			printf("insert success\n");
		} else {
			printf("insert fail\n");
		}
	}
	p = malloc(sizeof(struct nd));
	if (p) {
		p->data = insert_val + 1;
		p->n = NULL;

		single_list_add_after(p, prev, pos, (&head), n, (pos->data == position_val), ret);
		if (ret == 0) {
			printf("insert success\n");
		} else {
			printf("insert fail\n");
		}
	}

printf("------------------\n");
	/* destroy list */
	i = 0;
	while ((&head)->n != NULL) {
		single_list_del_first_node(pos, (&head), n);
		if (pos != NULL) {
			printf("free node %d, %d\n", i, pos->data);
			free(pos);
			i++;
		}
	}
	return 0;
}


/*
 * del node
 */
int del_node(int list_len, int del_val)
{
	struct nd head;
	struct nd *p;
	struct nd *prev, *pos;
	int i;
	int ret;

	SINGLE_LIST_INIT_HEAD((&head), n);

	/* create list */
	for (i = 0; i < list_len; i++) {
		p = malloc(sizeof(struct nd));
		if (!p)
			break;
		p->data = i;
		single_list_add_tail(p, prev, pos, (&head), n);
	}
printf("------------------\n");
	/* print list */
	i = 0;
	single_list_for_each(prev, pos, (&head), n) {
		printf("node %d: %d\n", i, pos->data);
		i++;
	}
printf("------------------\n");

	single_list_del_node(prev, pos, (&head), n, (pos->data == del_val), ret);
	if (ret == 0 && pos != NULL) {
		printf("del node %d\n", pos->data);
		free(pos);
	} else {
		printf("not found node %d\n", del_val);
	}

printf("------------------\n");
	/* destroy list */
	i = 0;
	while ((&head)->n != NULL) {
		single_list_del_first_node(pos, (&head), n);
		if (pos != NULL) {
			printf("free node %d, %d\n", i, pos->data);
			free(pos);
			i++;
		}
	}
	return 0;
}


/*
 * insert sort
 */
int sort_insert(struct nd *head, struct nd *new_node)
{
	struct nd *prev, *pos;

	if ((NULL == head) || (NULL == new_node))
		return -1;

	if (NULL == head->n) {
		new_node->n = head->n;
		head->n = new_node;
		return 0;
	}

	for (prev = head, pos = head->n; pos; prev = pos, pos = pos->n) {
		if (new_node->data < pos->data) { /* 降序排列，如果是升序则>，也可以>=或<= */
			if (NULL == pos->n) { /* pos是最后一个节点 */
				single_list_add(new_node, pos, n); /* 将新节点插入最后一个节点的后面 */
				break;
			}
		} else {
			single_list_add(new_node, prev, n); /* 将新节点插入prev后面 */
			break;
		}
	}

	return 0;
}
int insert_sort(int list_len)
{
	struct nd head;
	struct nd *p;
	struct nd *prev, *pos;
	int i;

	struct nd new_head;
	SINGLE_LIST_INIT_HEAD((&new_head), n);
	new_head.data = 0;

	SINGLE_LIST_INIT_HEAD((&head), n);

	srand(12345);

	/* create list */
	for (i = 0; i < list_len; i++) {
		p = malloc(sizeof(struct nd));
		if (!p)
			break;
		p->data = rand();
		single_list_add(p, (&head), n);
	}
printf("------------------\n");
	/* print list */
	i = 0;
	single_list_for_each(prev, pos, (&head), n) {
		printf("node %d: %d\n", i, pos->data);
		i++;
	}
printf("------------------\n");

	while (head.n != NULL) {
		single_list_del_first_node(pos, (&head), n);
		if (pos)
			sort_insert(&new_head, pos);
	}
printf("------------------\n");
	/* print list */
	i = 0;
	single_list_for_each(prev, pos, (&new_head), n) {
		printf("node %d: %d\n", i, pos->data);
		i++;
	}
printf("------------------\n");
	/* destroy list */
	i = 0;
	while ((&new_head)->n != NULL) {
		single_list_del_first_node(pos, (&new_head), n);
		if (pos != NULL) {
			printf("free node %d, %d\n", i, pos->data);
			free(pos);
			i++;
		}
	}
	return 0;
}
