#include "../inc/push_swap.h"

int	count_size(t_stack *stack)
{
	t_node	*current;
	int		count;

	current = stack->head;
	count = 0;
	if (!stack || !stack->head)
		return (0);
	while (current)
	{
		count++;
		current = current->next;
		if (current == stack->head)
			break ;
	}
	return (count);
}
