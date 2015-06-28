#ifndef __SINGLE_LIST_H__
#define __SINGLE_LIST_H__


/* ��ʼ������ͷ�����ӵ�����ͷ����Ӧ�õ��ô˺������г�ʼ�� */
#define SINGLE_LIST_INIT_HEAD(head, next) ((head)->next = NULL)

/* �ж�һ�������Ƿ�Ϊ�գ�ע��������Ǹ�����ͷ�ڵ�� */
#define single_list_is_empty(head, next) ((head)->netx == NULL)

/* --------------------------------------------------------------- */

/* �˺��������������ÿ���ڵ㣬ע��������Ǹ�����ͷ�ڵ��
 * ����posָ�����ʱ��ǰ�ڵ㣬ע��ʹ�ô˺�ʱ���ܶԽڵ����ɾ���Ͳ������
 */
#define single_list_for_each(prev, pos, head, next)		\
	for (prev = (head), pos = prev->next;			\
	pos != NULL;						\
	prev = pos, pos = pos->next)

/* ��������ڵ�ļ򻯰� */
#define single_list_for_each_lite(pos, head, next)	\
	for (pos = (head)->next;			\
	pos != NULL;					\
	pos = pos->next)

/* --------------------------------------------------------------- */

/* prev, pos ���ڼ�¼�ҵ��Ľڵ� */
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

/* pos���ڼ�¼��ɾ���Ľڵ� */
#define single_list_del_init(prev, pos, next)	\
	do {					\
		if (prev->next != pos) {	\
			printf("[single_list_del_init][error]prev->member != pos\n");	\
		}				\
		prev->next = pos->next;		\
		pos->next = NULL;		\
	} while(0)

/* pos���ڼ�¼��ɾ���Ľڵ�
 * condition�����ҵ�Ҫɾ���Ľڵ� */
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
