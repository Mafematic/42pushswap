#include "../inc/push_swap.h"

static void reverse_rotate_both(t_stack **a, t_stack **b, t_node *cheapest_node)
{
	while ((*a)->head != cheapest_node->target_node && (*b)->head != cheapest_node)
	{
		rrr(a, b);
		printf("rrr\n");
	}
	set_current_position(*a);
	set_current_position(*b);
}

static void rotate_both(t_stack **a, t_stack **b, t_node *cheapest_node)
{
	while ((*a)->head != cheapest_node->target_node && (*b)->head != cheapest_node)
	{
		rr(a, b);
		printf("rr\n");
	}
	set_current_position(*a);
	set_current_position(*b);
}

static void finish_rotation(t_stack **stack, t_node *top_node, char stack_name)
{
	while ((*stack)->head != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
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
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
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
	}
}

static t_node *return_cheapest(t_stack *stack)
{
	t_node *current_node;

	if (stack == NULL || stack->head == NULL)
		return NULL;

	current_node = stack->head;
	while (current_node)
	{
		if (current_node->cheapest)
			return current_node;
		current_node = current_node->next;
	}
	return NULL;
}

void move_nodes(t_stack **a, t_stack **b)
{
	t_node *cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b);
	printf("pa\n");
	//display(*a);
	//display(*b);
}