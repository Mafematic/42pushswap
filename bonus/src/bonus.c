/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <fszendzi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:50:07 by fszendzi          #+#    #+#             */
/*   Updated: 2023/10/16 14:50:09 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	cleanup_stacks(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	get_next_line(-1);
}

int	is_valid_operation(char *line)
{
	char	*valid_operations[11];
	int		i;

	valid_operations[0] = "ra\n";
	valid_operations[1] = "rb\n";
	valid_operations[2] = "rr\n";
	valid_operations[3] = "rra\n";
	valid_operations[4] = "rrb\n";
	valid_operations[5] = "rrr\n";
	valid_operations[6] = "sa\n";
	valid_operations[7] = "sb\n";
	valid_operations[8] = "pa\n";
	valid_operations[9] = "pb\n";
	valid_operations[10] = NULL;
	i = 0;
	while (valid_operations[i])
	{
		if (ft_strcmp(line, valid_operations[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	execute_command(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b);
	else if (ft_strcmp(line, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(a, b);
}

int	terminate_with_error(char *line, t_stack **a, t_stack **b)
{
	write(2, "Error\n", 6);
	get_next_line(-1);
	free_stack(a);
	free_stack(b);
	free(line);
	return (1);
}
