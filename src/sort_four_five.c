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
	int		index;
	t_node	*p;

	index = 0;
	p = stack->head;
	while (p != NULL)
	{
		if (min == p->data)
		{
			return (index);
		}
		index++;
		p = p->next;
	}
	return (-1);
}

static void	rotate_to_position(t_stack **a, int pos, int min)
{
	if (pos == 2)
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
}

static void	safe_push(t_stack **source, t_stack **dest, char *action)
{
	if (pb(source, dest) != 0)
	{
		free_stack(source);
		free_stack(dest);
		exit(1);
	}
	write(1, action, ft_strlen(action));
}

void	sort_size_four(t_stack **a, t_stack **b)
{
	int	min;
	int	pos;

	min = find_min(*a);
	pos = position_minimum(*a, min);
	rotate_to_position(a, pos, min);
	safe_push(a, b, "pb\n");
	sort_size_three(a);
	safe_push(b, a, "pa\n");
}

void	sort_size_five(t_stack **a, t_stack **b)
{
	int min;
	int pos;

	min = find_min(*a);
	pos = position_minimum(*a, min);
	rotate_to_position(a, pos, min);
	safe_push(a, b, "pb\n");
	sort_size_four(a, b);
	safe_push(b, a, "pa\n");
}
