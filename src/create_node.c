#include "../inc/push_swap.h"

t_node *create_node(long data)
{
	t_node *new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
	{
		perror("Failed to create node");
		exit(1);
	}
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}