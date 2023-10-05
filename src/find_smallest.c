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
