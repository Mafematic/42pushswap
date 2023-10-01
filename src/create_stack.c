#include "../inc/push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
	{
		write(1, "Failed to allocate memory for stack\n", 36);
		exit(1);
	}
	new_stack->head = NULL;
	new_stack->tail = NULL;
	return (new_stack);
}
