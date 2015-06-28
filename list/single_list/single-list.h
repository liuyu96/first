#ifndef __SINGLE_LIST_H__
#define __SINGLE_LIST_H__


/* 初始化链表头，附加的链表头，都应该调用此宏对其进行初始化 */
#define SINGLE_LIST_INIT_HEAD(head, next) ((head)->next = NULL)

/* 判断一个链表是否为空，注意此链表是附加了头节点的 */
#define single_list_is_empty(head, next) ((head)->netx == NULL)

/* --------------------------------------------------------------- */

/* 此宏用来遍历链表的每个节点，注意此链表是附加了头节点的
 * 其中pos指向遍历时当前节点，注意使用此宏时不能对节点进行删除和插入操作
 */
#define single_list_for_each(prev, pos, head, next)		\
	for (prev = (head), pos = prev->next;			\
	pos != NULL;						\
	prev = pos, pos = pos->next)

/* 遍历链表节点的简化版 */
#define single_list_for_each_lite(pos, head, next)	\
	for (pos = (head)->next;			\
	pos != NULL;					\
	pos = pos->next)

/* --------------------------------------------------------------- */

/* prev, pos 用于记录找到的节点 */
#define single_list_search_node(prev, pos, head, next, condition, __ret)	\
	do {									\
		__ret = -1;							\
		single_list_for_each(prev, pos, (head), next) {			\
			if ((condition)) {					\
				__ret = 0;					\
				break;						\
			}							\
		}								\
	} while (0)

/* --------------------------------------------------------------- */
#define single_list_add(new_node, head, next)			\
	do {							\
		(new_node)->next = (head)->next;		\
		(head)->next = (new_node);			\
	} while(0)

#define single_list_add_tail(new_node, prev, pos, head, next)	\
	do {							\
		single_list_for_each(prev, pos, (head), next) {	\
			;					\
		}						\
		single_list_add(new_node, prev, next);		\
	} while(0)

#define single_list_add_before(new_node, prev, pos, head, next, condition, __ret)	\
	do {										\
		__ret = -1;								\
		single_list_search_node(prev, pos, (head), next, (condition), (__ret));	\
		if (__ret == 0) {							\
			single_list_add(new_node, prev, next);				\
		}									\
	} while(0)

#define single_list_add_after(new_node, prev, pos, head, next, condition, __ret)	\
	do {										\
		__ret = -1;								\
		single_list_search_node(prev, pos, (head), next, (condition), (__ret));	\
		if (__ret == 0) {							\
			single_list_add(new_node, pos, next);				\
		}									\
	} while(0)

/* --------------------------------------------------------------- */

/* pos用于记录被删除的节点 */
#define single_list_del_init(prev, pos, next)	\
	do {					\
		if (prev->next != pos) {	\
			printf("[single_list_del_init][error]prev->member != pos\n");	\
		}				\
		prev->next = pos->next;		\
		pos->next = NULL;		\
	} while(0)

/* pos用于记录被删除的节点
 * condition用于找到要删除的节点 */
#define single_list_del_node(prev, pos, head, next, condition, __ret)			\
	do {										\
		__ret = -1;								\
		single_list_search_node(prev, pos, (head), next, (condition), (__ret));	\
		if (__ret == 0) {							\
			single_list_del_init(prev, pos, next);				\
		}									\
	} while(0)

/* */
#define single_list_del_first_node(first, head, next)		\
	do {								\
		first = (head)->next;					\
		if (first) {						\
			(head)->next = first->next;			\
			first->next = NULL;				\
		}							\
	} while(0)

/* --------------------------------------------------------------- */
#endif /* __SINGLE_LIST_H__ */
