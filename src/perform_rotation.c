/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <fszendzi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:00:05 by fszendzi          #+#    #+#             */
/*   Updated: 2023/10/05 19:00:06 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	perform_rotation_a(t_stack **stack, bool above_mid)
{
	if (above_mid)
	{
		ra(stack);
		write(1, "ra\n", 3);
	}
	else
	{
		rra(stack);
		write(1, "rra\n", 4);
	}
}

static void	perform_rotation_b(t_stack **stack, bool above_mid)
{
	if (above_mid)
	{
		rb(stack);
		write(1, "rb\n", 3);
	}
	else
	{
		rrb(stack);
		write(1, "rrb\n", 4);
	}
}

void	finish_rotation(t_stack **stack, t_node *top_node, char stack_name)
{
	while ((*stack)->head != top_node)
	{
		if (stack_name == 'a')
		{
			perform_rotation_a(stack, top_node->above_mid);
		}
		else if (stack_name == 'b')
		{
			perform_rotation_b(stack, top_node->above_mid);
		}
	}
}
