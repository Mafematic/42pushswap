/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <fszendzi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:00:12 by fszendzi          #+#    #+#             */
/*   Updated: 2023/10/05 19:00:14 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	position_minimum(t_stack *stack, int min)
{
	int		index;
	t_node	*p;

	index = 0;
	p = stack->head;
	while (p != NULL)
	{
		if (min == p->data)
		{
			return (index);
		}
		index++;
		p = p->next;
	}
	return (-1);
}

static void	rotate_to_position(t_stack **a, int pos, int min)
{
	if (pos == 2)
	{
		while ((*a)->head->data != min)
		{
			rra(a);
			write(1, "rra\n", 4);
		}
	}
	else
	{
		while ((*a)->head->data != min)
		{
			ra(a);
			write(1, "ra\n", 3);
		}
	}
}

void	sort_size_four(t_stack **a, t_stack **b)
{
	int	min;
	int	pos;

	min = find_min(*a);
	pos = position_minimum(*a, min);
	rotate_to_position(a, pos, min);
	safe_push(a, b, "pb\n");
	sort_size_three(a);
	safe_push(b, a, "pa\n");
}

void	sort_size_five(t_stack **a, t_stack **b)
{
	int	min;
	int	pos;

	min = find_min(*a);
	pos = position_minimum(*a, min);
	rotate_to_position(a, pos, min);
	safe_push(a, b, "pb\n");
	sort_size_four(a, b);
	safe_push(b, a, "pa\n");
}
