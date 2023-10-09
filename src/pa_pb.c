/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <fszendzi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:59:32 by fszendzi          #+#    #+#             */
/*   Updated: 2023/10/05 18:59:34 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	push(t_stack **stack, int num)
{
	t_node	*t;

	t = create_node(num);
	if (!t)
		return (1);
	if (!(*stack)->head)
	{
		(*stack)->head = t;
		(*stack)->tail = t;
		t->next = t;
		t->prev = t;
	}
	else
	{
		t->next = (*stack)->head;
		t->prev = (*stack)->tail;
		(*stack)->head->prev = t;
		(*stack)->tail->next = t;
		(*stack)->head = t;
	}
	return (0);
}

static t_node	*pop(t_stack **stack)
{
	t_node	*temp;

	if (!*stack || !(*stack)->head)
		return (NULL);
	temp = (*stack)->head;
	if ((*stack)->head == (*stack)->tail)
	{
		(*stack)->head->next = NULL;
		(*stack)->head->prev = NULL;
		(*stack)->head = NULL;
		(*stack)->tail = NULL;
	}
	else
	{
		(*stack)->head = (*stack)->head->next;
		(*stack)->tail->next = (*stack)->head;
		(*stack)->head->prev = (*stack)->tail;
	}
	temp->next = NULL;
	temp->prev = NULL;
	return (temp);
}

int	pa(t_stack **a, t_stack **b)
{
	t_node	*node;

	node = pop(b);
	if (node)
	{
		if (push(a, node->data) != 0)
		{
			return (1);
		}
		if (!(*a)->head->next)
		{
			(*a)->tail = (*a)->head;
		}
		free(node);
	}
	return (0);
}

int	pb(t_stack **a, t_stack **b)
{
	t_node	*node;

	node = pop(a);
	if (node)
	{
		if (push(b, node->data) != 0)
			return (1);
		if (!(*b)->head->next)
		{
			(*b)->tail = (*b)->head;
		}
		free(node);
	}
	return (0);
}
