/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <fszendzi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:01:42 by fszendzi          #+#    #+#             */
/*   Updated: 2023/10/05 19:01:44 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	sa(t_stack **a)
{
	t_node	*first;
	t_node	*second;

	if (!*a || !(*a)->head || !(*a)->head->next)
		return ;
	first = (*a)->head;
	second = first->next;
	if (second->next != first)
	{
		first->next = second->next;
		second->next->prev = first;
	}
	else
	{
		first->next = second;
		second->next = first;
	}
	first->prev->next = second;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	(*a)->head = second;
	if ((*a)->tail == second)
		(*a)->tail = first;
}

void	sb(t_stack **b)
{
	sa(b);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
