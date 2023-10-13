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

#include "../checker.h"

static int	is_duplicate(t_stack *a, int nbr)
{
	t_node	*current;

	if (!a->head)
		return (0);
	current = a->head;
	while (1)
	{
		if (current->data == nbr)
			return (1);
		current = current->next;
		if (current == a->head)
			break ;
	}
	return (0);
}

int	process_and_append_number(char *number_str, t_stack **a)
{
	long	nbr;

	nbr = ft_atol(number_str);
	if (nbr == 0 && number_str[0] != '0')
		return (1);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (1);
	if (is_duplicate(*a, (int)nbr))
		return (1);
	if (append(a, nbr) != 0)
		return (1);
	return (0);
}

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
