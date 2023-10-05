/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_target_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <fszendzi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:59:39 by fszendzi          #+#    #+#             */
/*   Updated: 2023/10/05 18:59:41 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	find_target_for_node(t_node *current_b, t_stack *a)
{
	t_node	*current_a;
	t_node	*target_node;
	long	best_match_index;

	best_match_index = LONG_MAX;
	current_a = a->head;
	while (current_a)
	{
		if (current_a->data > current_b->data
			&& current_a->data < best_match_index)
		{
			best_match_index = current_a->data;
			target_node = current_a;
		}
		current_a = current_a->next;
		if (current_a == a->head)
			break ;
	}
	if (LONG_MAX == best_match_index)
		current_b->target_node = find_smallest(a);
	else
		current_b->target_node = target_node;
}

void	set_target_nodes(t_stack *a, t_stack *b)
{
	t_node	*current_b;
	t_node	*start_b;

	current_b = b->head;
	start_b = b->head;
	if (!a->head || !b->head)
		return ;
	while (current_b)
	{
		find_target_for_node(current_b, a);
		current_b = current_b->next;
		if (current_b == start_b)
			break ;
	}
}
