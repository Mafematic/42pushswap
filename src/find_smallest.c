#include "../inc/push_swap.h"

t_node *find_smallest(t_stack *stack)
{
	long smallest;
	t_node *smallest_node = NULL; // Initialize to NULL
	t_node *current;
	t_node *start; // For tracking the starting node in a circular list

	if (NULL == stack || NULL == stack->head)
		return (NULL);

	current = start = stack->head;
	smallest = LONG_MAX;

	do
	{
		if (current->data < smallest)
		{
			smallest = current->data;
			smallest_node = current;
		}
		current = current->next;
	} while (current && current != start); // Ensure not to process the head node twice

	return (smallest_node);
}