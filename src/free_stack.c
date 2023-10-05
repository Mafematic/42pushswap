/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <fszendzi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:21:04 by fszendzi          #+#    #+#             */
/*   Updated: 2023/10/05 19:21:06 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_node	*current;
	t_node	*start;
	t_node	*next_node;

	if (!*stack)
		return ;
	current = (*stack)->head;
	start = (*stack)->head;
	if (current)
	{
		next_node = NULL;
		while (1)
		{
			next_node = current->next;
			free(current);
			if (next_node == start)
				break ;
			current = next_node;
		}
	}
	free(*stack);
	*stack = NULL;
}
