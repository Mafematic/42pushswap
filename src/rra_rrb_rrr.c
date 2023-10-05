/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <fszendzi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:32:26 by fszendzi          #+#    #+#             */
/*   Updated: 2023/10/05 19:32:28 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rra(t_stack **a)
{
	t_node	*last;

	if (!*a || !(*a)->head || !(*a)->head->next)
	{
		return ;
	}
	last = (*a)->tail;
	last->next = (*a)->head;
	(*a)->head->prev = last;
	last->prev->next = last;
	(*a)->tail = last->prev;
	(*a)->head = last;
}

void	rrb(t_stack **b)
{
	rra(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
