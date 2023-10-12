/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <fszendzi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:00:54 by fszendzi          #+#    #+#             */
/*   Updated: 2023/10/05 19:00:56 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*find_smallest(t_stack *stack)
{
	long	smallest;
	t_node	*smallest_node;
	t_node	*current;
	t_node	*start;

	if (NULL == stack || NULL == stack->head)
		return (NULL);
	current = stack->head;
	start = stack->head;
	smallest = LONG_MAX;
	while (current)
	{
		if (current->data < smallest)
		{
			smallest = current->data;
			smallest_node = current;
		}
		current = current->next;
		if (current == start)
			break ;
	}
	return (smallest_node);
}

int	find_min(t_stack *stack)
{
	int		min;
	t_node	*p;
	int		first_run;

	min = INT32_MAX;
	if (!stack || !stack->head)
		return (min);
	p = stack->head;
	first_run = 1;
	while (first_run || p != stack->head)
	{
		if (p->data < min)
			min = p->data;
		p = p->next;
		first_run = 0;
	}
	return (min);
}
