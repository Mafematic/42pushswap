/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <fszendzi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:59:14 by fszendzi          #+#    #+#             */
/*   Updated: 2023/10/05 18:59:16 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	count_size(t_stack *stack)
{
	t_node	*current;
	int		count;

	current = stack->head;
	count = 0;
	if (!stack || !stack->head)
		return (0);
	while (current)
	{
		count++;
		current = current->next;
		if (current == stack->head)
			break ;
	}
	return (count);
}
