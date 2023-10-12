/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <fszendzi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:59:48 by fszendzi          #+#    #+#             */
/*   Updated: 2023/10/12 16:59:50 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	append(t_stack **stack, long data)
{
	t_node	*new_node;

	new_node = create_node(data);
	if (!new_node)
		return (1);
	if ((*stack)->head == NULL && (*stack)->tail == NULL)
	{
		(*stack)->head = new_node;
		(*stack)->tail = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		new_node->prev = (*stack)->tail;
		new_node->next = (*stack)->head;
		(*stack)->tail->next = new_node;
		(*stack)->head->prev = new_node;
		(*stack)->tail = new_node;
	}
	return (0);
}

