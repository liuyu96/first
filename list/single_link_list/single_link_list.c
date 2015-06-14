#include <stdio.h>
#include <stdlib.h>
struct node
{
	struct node *next;
	int a;
};

struct node *head, *tmp_node;

void insert_node(struct node **head, struct node *insert_node)
{
	insert_node->next = *head;
	*head = insert_node;
}

struct node * delete_node(struct node **head)
{
	struct node *tmp_node;
	tmp_node = *head;
	*head = tmp_node->next;
	return tmp_node;
}

int main(int argc, char *argv[])
{
	int i=0;
	struct node node1, *cyy_node;
	struct node *head2 = NULL;
	node1.next = NULL;
	node1.a = 1;
	
	for (i=100; i>0; i--)
	{
		cyy_node = (struct node*)malloc(sizeof(struct node));
		cyy_node->a = i;
		insert_node(&head, cyy_node);
		printf("%p volue is %d\n", cyy_node,cyy_node->a);
	}

	printf("----------------------------\n");
	for (cyy_node = head; cyy_node != NULL; cyy_node = cyy_node->next)
	{
		printf("%p value is %d\n",cyy_node, cyy_node->a);
	}

	printf("----------------------------\n");

	for (; head != NULL; )
	{
		cyy_node = delete_node(&head);
		insert_node(&head2, cyy_node);
	}
		printf("----------------------------\n");
	for (cyy_node = head2; cyy_node != NULL; cyy_node = cyy_node->next)
	{
		printf("%p value is %d\n",cyy_node, cyy_node->a);
	}
	return 0;
}

