#ifndef _LINUX_LIST_H
#define _LINUX_LIST_H

/*
 * Simple doubly linked list implementation.
 *
 * Some of the internal functions ("__xxx") are useful when
 * manipulating whole lists rather than single entries, as
 * sometimes we already know the next/prev entries and we can
 * generate better code by using them directly rather than
 * using the generic single-entry routines.
 */

struct list_head {
	struct list_head *next, *prev;
	void *data;
};


#define INIT_LIST_HEAD(list, p, n)		\
	do {					\
		(list)->n = (list);		\
		(list)->p = (list);		\
	} while(0)


#define __LIST_ADD(new_node, prev, next, p, n)	\
	do {					\
		(next)->p = (new_node);		\
		(new_node)->n = (next);		\
		(new_node)->p = (prev);		\
		(prev)->n = (new_node);		\
	} while(0)


#define LIST_ADD(new_node, head, p, n)					\
	do {								\
		__LIST_ADD((new_node), (head), (head)->n, p, n);		\
	} while(0)


#define LIST_ADD_TAIL(new_node, head, p, n)				\
	do {								\
		__LIST_ADD((new_node), (head)->p, (head), p, n);		\
	} while(0)


#define __LIST_DEL(prev, next, p, n)					\
	do {								\
		(next)->p = (prev);					\
		(prev)->n = (next);					\
	} while(0)

#define __LIST_DEL_ENTRY(entry, p, n)				\
	do {							\
		__LIST_DEL((entry)->p, (entry)->n, p, n);	\
	} while(0)


#define LIST_DEL(entry, p, n)					\
	do {							\
		__LIST_DEL((entry)->p, (entry)->n, p, n);	\
		(entry)->n = NULL;				\
		(entry)->p = NULL;				\
	} while(0)

#define LIST_REPLACE(old_node, new_node, p, n)		\
	do {						\
		new_node->n = old_node->n;		\
		new_node->n->p = new_node;		\
		new_node->p = old_node->p;		\
		new_node->p->n = new_node;		\
	} while(0)


#define LIST_REPLACE_INIT(old_node, new_node, p, n)		\
	do {							\
		LIST_REPLACE((old_node), (new_node), p, n);	\
		INIT_LIST_HEAD((old_node), p, n);		\
	} while(0)

#define LIST_DEL_INIT(entry, p, n)		\
	do {					\
		__LIST_DEL_ENTRY(entry, p, n);	\
		INIT_LIST_HEAD(entry, p, n);		\
	} while(0)

#define LIST_MOVE(list, head, p, n)			\
	do {						\
		__LIST_DEL_ENTRY((list), p, n);		\
		LIST_ADD((list), (head), p, n);		\
	} while(0)


#define LIST_MOVE_TAIL(list, head, p, n)			\
	do {						\
		__LIST_DEL_ENTRY((list), p, n);		\
		LIST_ADD_TAIL((list), (head), p, n);	\
	} while(0)

#define LIST_IS_LAST(list, head, p, n)	((list)->n == (head))

#define LIST_EMPTY(head, p, n)	((head)->n == (head))

#define LIST_IS_SINGULAR(head, p, n) ((!LIST_EMPTY((head), p, n)) && ((head)->n == (head)->p))


#define LIST_FOR_EACH(pos, head, p, n)	\
	for (pos = (head)->n; pos != (head); pos = pos->n)


#define LIST_FOR_EACH_PREV(pos, head, p, n)	\
	for (pos = (head)->p; pos != (head); pos = pos->p)

#define LIST_FOR_EACH_SAFE(pos, next, head, p, n)		\
	for (pos = (head)->n, next = pos->n; pos != (head);	\
		pos = next, next = pos->n)

#define LIST_FOR_EACH_PREV_SAFE(pos, next, head, p, n)		\
	for (pos = (head)->p, next = pos->p;			\
	     pos != (head);					\
	     pos = next, next = pos->p)

#endif
