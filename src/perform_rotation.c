#include "../inc/push_swap.h"

static void	perform_rotation_a(t_stack **stack, bool above_mid)
{
	if (above_mid)
	{
		ra(stack);
		printf("ra\n");
	}
	else
	{
		rra(stack);
		printf("rra\n");
	}
}

static void	perform_rotation_b(t_stack **stack, bool above_mid)
{
	if (above_mid)
	{
		rb(stack);
		printf("rb\n");
	}
	else
	{
		rrb(stack);
		printf("rrb\n");
	}
}

void	finish_rotation(t_stack **stack, t_node *top_node, char stack_name)
{
	while ((*stack)->head != top_node)
	{
		if (stack_name == 'a')
		{
			perform_rotation_a(stack, top_node->above_mid);
		}
		else if (stack_name == 'b')
		{
			perform_rotation_b(stack, top_node->above_mid);
		}
	}
}
