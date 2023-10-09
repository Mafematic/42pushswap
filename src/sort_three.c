/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <fszendzi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:00:47 by fszendzi          #+#    #+#             */
/*   Updated: 2023/10/05 19:00:49 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_node	*find_max(t_stack *stack)
{
	long	max;
	t_node	*current_node;
	t_node	*start_node;
	t_node	*max_node;

	if (stack == NULL || stack->head == NULL)
		return (NULL);
	max = LONG_MIN;
	current_node = stack->head;
	start_node = stack->head;
	while (1)
	{
		if (current_node->data > max)
		{
			max = current_node->data;
			max_node = current_node;
		}
		current_node = current_node->next;
		if (current_node == start_node)
			break ;
	}
	return (max_node);
}

void	sort_size_three(t_stack **a)
{
	t_node	*max_node;

	max_node = find_max(*a);
	if ((*a)->head == max_node)
	{
		ra(a);
		write(1, "ra\n", 3);
	}
	else if ((*a)->head->next == max_node)
	{
		rra(a);
		write(1, "rra\n", 4);
	}
	if ((*a)->head->data > (*a)->head->next->data)
	{
		sa(a);
		write(1, "sa\n", 3);
	}
}
