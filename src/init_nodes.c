#include "../inc/push_swap.h"

void	set_best_node(t_stack *b)
{
	long	best_match_value;
	t_node	*best_match_node;
	t_node	*current_node;

	if (b == NULL || b->head == NULL)
		return ;
	best_match_value = LONG_MAX;
	current_node = b->head;
	while (current_node)
	{
		current_node->best_match = false;
		if (current_node->push_sum < best_match_value)
		{
			best_match_value = current_node->push_sum;
			best_match_node = current_node;
		}
		if (current_node->next == b->head)
			break ;
		current_node = current_node->next;
	}
	if (best_match_node)
		best_match_node->best_match = true;
}

void	set_addition(t_stack *a, t_stack *b)
{
	int		len_a;
	int		len_b;
	t_node	*current_b;

	len_a = count_size(a);
	len_b = count_size(b);
	current_b = b->head;
	while (current_b)
	{
		current_b->push_sum = current_b->current_position;
		if (!(current_b->above_median))
			current_b->push_sum = len_b - (current_b->current_position);
		if (current_b->target_node->above_median)
			current_b->push_sum += current_b->target_node->current_position;
		else
			current_b->push_sum += len_a
				- (current_b->target_node->current_position);
		if (current_b->next == b->head)
			break ;
		current_b = current_b->next;
	}
}

void	set_position(t_stack *stack)
{
	int		i;
	int		mid;
	t_node	*current;
	t_node	*start;

	current = stack->head;
	start = stack->head;
	i = 0;
	if (stack == NULL || stack->head == NULL)
		return ;
	mid = count_size(stack) / 2;
	while (current)
	{
		current->current_position = i;
		if (i <= mid)
			current->above_median = true;
		else
			current->above_median = false;
		current = current->next;
		i++;
		if (current == start)
			break ;
	}
}

void	init_nodes(t_stack *a, t_stack *b)
{
	set_position(a);
	set_position(b);
	set_target_nodes(a, b);
	set_addition(a, b);
	set_best_node(b);
}
