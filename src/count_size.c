#include "../inc/push_swap.h"

int count_size(t_stack *stack)
{
	int count = 0;
	if (!stack || !stack->head)
		return 0;

	t_node *current = stack->head;
	t_node *start = stack->head;

	do
	{
		count++;
		current = current->next;
	} while (current && current != start);

	return count;
}