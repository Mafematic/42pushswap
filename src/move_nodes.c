#include "../inc/push_swap.h"

static void	reverse_rotate_both(t_stack **a, t_stack **b, t_node *best_node)
{
	while ((*a)->head != best_node->target_node && (*b)->head != best_node)
	{
		rrr(a, b);
		printf("rrr\n");
	}
	set_position(*a);
	set_position(*b);
}

static void	rotate_both(t_stack **a, t_stack **b, t_node *best_node)
{
	while ((*a)->head != best_node->target_node && (*b)->head != best_node)
	{
		rr(a, b);
		printf("rr\n");
	}
	set_position(*a);
	set_position(*b);
}

static t_node	*return_best_node(t_stack *stack)
{
	t_node	*current_node;
	t_node	*start_node;

	if (stack == NULL || stack->head == NULL)
		return (NULL);
	current_node = stack->head;
	start_node = stack->head;
	while (current_node)
	{
		if (current_node->best_match)
			return (current_node);
		current_node = current_node->next;
		if (current_node == start_node)
			break ;
	}
	return (NULL);
}

void	move_nodes(t_stack **a, t_stack **b)
{
	t_node	*best_node;

	best_node = return_best_node(*b);
	if (best_node->above_mid && best_node->target_node->above_mid)
		rotate_both(a, b, best_node);
	else if (!(best_node->above_mid) && !(best_node->target_node->above_mid))
		reverse_rotate_both(a, b, best_node);
	finish_rotation(b, best_node, 'b');
	finish_rotation(a, best_node->target_node, 'a');
	if (pa(a, b) != 0)
	{
		free_stack(a);
		free_stack(b);
		exit(1);
	}
	//write(1, "pa\n", 3);
	printf("pa\n");
}
