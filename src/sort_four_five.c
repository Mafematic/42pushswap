/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <fszendzi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:00:12 by fszendzi          #+#    #+#             */
/*   Updated: 2023/10/05 19:00:14 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	find_min(t_stack *stack)
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

static int	position_minimum(t_stack *stack, int min)
{
	int index = 0;
	t_node *p = stack->head;
	while (p != NULL)
	{
		if (min == p->data)
		{
			return index;
		}
		index++;
		p = p->next;
	}
	return -1;
}

void sort_size_four(t_stack **a, t_stack **b)
{
	int min = find_min(*a);
	int pos = position_minimum(*a, min);

	// Move the minimum value to the top of the stack
	if (pos == 2) // if position_minimum is 0-based
	{
		while ((*a)->head->data != min)
		{
			rra(a);
			write(1, "rra\n", 4);
		}
	}
	else
	{
		while ((*a)->head->data != min)
		{
			ra(a);
			write(1, "ra\n", 3);
		}
	}

	// Push the minimum value to stack_b
	if (pb(a, b) != 0)
	{
		free_stack(a);
		free_stack(b);
		exit(1);
	}
	write(1, "pb\n", 3);

	// Sort the remaining 3 elements
	sort_size_three(a);

	// Pop the element back from stack_b to stack_a
	if (pa(a, b) != 0)
	{
		free_stack(a);
		free_stack(b);
		exit(1);
	}
	write(1, "pa\n", 3);
}

void sort_size_five(t_stack **a, t_stack **b, int size)
{
	int min = find_min(*a);
	int pos = position_minimum(*a, min);

	if (pos == 3 || pos == 4)
	{
		while ((*a)->head->data != min)
		{
			rra(a);
			write(1, "rra\n", 4);
		}
	}
	else
	{
		while ((*a)->head->data != min)
		{
			ra(a);
			write(1, "ra\n", 3);
		}
	}

	if (pb(a, b) != 0)
	{
		free_stack(a);
		free_stack(b);
		exit(1);
	}
	write(1, "pb\n", 3);

	size--;

	sort_size_four(a, b);

	if (pa(a, b) != 0)
	{
		free_stack(a);
		free_stack(b);
		exit(1);
	}
	write(1, "pa\n", 3);
}
