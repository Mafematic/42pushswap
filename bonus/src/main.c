/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <fszendzi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:50:40 by fszendzi          #+#    #+#             */
/*   Updated: 2023/10/15 17:50:42 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	process_multiple_args(int argc, char **argv, t_stack **a, t_stack **b)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (process_and_append_number(argv[i], a) != 0)
			exit_error(a, b, NULL);
		i++;
	}
}

void	process_single_arg(char *arg, t_stack **a, t_stack **b)
{
	char	**numbers;
	int		i;
	int		j;

	numbers = ft_split(arg, ' ');
	i = 0;
	while (numbers[i])
	{
		if (process_and_append_number(numbers[i], a) != 0)
			exit_error(a, b, numbers);
		i++;
	}
	j = 0;
	while (numbers[j])
	{
		free(numbers[j]);
		j++;
	}
	free(numbers);
}

void	initialize_stacks(t_stack **a, t_stack **b)
{
	*a = create_stack();
	*b = create_stack();
	if (*a == NULL || *b == NULL)
	{
		free_stack(a);
		free_stack(b);
		exit(1);
	}
}

void	process_args(int argc, char **argv, t_stack **a, t_stack **b)
{
	if (argc == 1)
		return ;
	else if (argc == 2)
		process_single_arg(argv[1], a, b);
	else
		process_multiple_args(argc, argv, a, b);
}

int	main(int argc, char **argv)
{
	char	*line;
	t_stack	*a;
	t_stack	*b;

	initialize_stacks(&a, &b);
	process_args(argc, argv, &a, &b);
	line = get_next_line(0);
	while (line != NULL)
	{
		if (is_valid_operation(line))
			execute_command(line, &a, &b);
		else
			return (terminate_with_error(line, &a, &b));
		free(line);
		line = get_next_line(0);
	}
	if (line == NULL && (!check_if_sorted(a) || !is_empty(b)))
		write(1, RED"KO\n"RESET, 8);
	else
		write(1, GRN "OK\n" RESET, 8);
	cleanup_stacks(&a, &b);
	return (0);
}

/*
#include <stdio.h>

void display(t_stack *stack)
{
	if (!stack || !stack->head)
	{
		printf("Empty Stack\n");
		return;
	}

	t_node *p = stack->head;
	while (1)
	{
		printf("%d ", p->data);
		p = p->next;
		if (p == stack->head)
			break;
	}
	printf("\n");
}
*/
