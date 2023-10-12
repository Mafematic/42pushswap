/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <fszendzi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:42:55 by fszendzi          #+#    #+#             */
/*   Updated: 2023/10/12 16:42:58 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

int	check_if_sorted(t_stack *stack)
{
	t_node	*current;
	t_node	*next_node;

	if (!stack || !stack->head)
		return (1);
	current = stack->head;
	next_node = current->next;
	while (current->next != stack->head)
	{
		if (current->data > next_node->data)
			return (0);
		current = next_node;
		next_node = next_node->next;
	}
	printf("Sorted\n");
	return (1);
}
