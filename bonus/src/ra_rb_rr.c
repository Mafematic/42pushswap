/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <fszendzi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:01:11 by fszendzi          #+#    #+#             */
/*   Updated: 2023/10/05 19:01:13 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ra(t_stack **a)
{
	if (!*a || !(*a)->head || !(*a)->head->next)
	{
		return ;
	}
	(*a)->tail = (*a)->head;
	(*a)->head = (*a)->head->next;
}

void	rb(t_stack **b)
{
	ra(b);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
