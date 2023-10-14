/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <fszendzi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:00:39 by fszendzi          #+#    #+#             */
/*   Updated: 2023/10/05 19:00:41 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push_elements_to_b(t_stack **a, t_stack **b, int len)
{
	while (len-- > 3)
	{
		if (pb(a, b) != 0)
		{
			free_stack(a);
			free_stack(b);
			write(2, "Error\n", 6);
			exit(1);
		}
		write(1, "pb\n", 3);
	}
}

static void	position_smallest_at_head(t_stack **a)
{
	t_node	*smallest;

	smallest = find_smallest(*a);
	if (smallest->above_mid)
	{
		while ((*a)->head != smallest)
		{
			ra(a);
			write(1, "ra\n", 3);
		}
	}
	else
	{
		while ((*a)->head != smallest)
		{
			rra(a);
			write(1, "rra\n", 4);
		}
	}
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = count_size(*a);
	push_elements_to_b(a, b, len_a);
	sort_size_three(a);
	while ((*b)->head)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_position(*a);
	position_smallest_at_head(a);
}
