/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <fszendzi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:05:18 by fszendzi          #+#    #+#             */
/*   Updated: 2023/10/12 17:05:21 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	size;

	if (!check_if_sorted(*a))
	{
		size = count_size(*a);
		if (size == 2)
		{
			sa(a);
			write(1, "sa\n", 3);
		}
		else if (size == 3)
			sort_size_three(a);
		else if (size == 4)
			sort_size_four(a, b);
		else if (size == 5)
			sort_size_five(a, b);
		else
			push_swap(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = create_stack();
	b = create_stack();
	if (a == NULL || b == NULL)
		exit_error(&a, &b, NULL);
	if (argc == 2)
		process_single_arg(argv[1], &a, &b);
	else
		process_multiple_args(argc, argv, &a, &b);
	sort_stacks(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

/*
Next Steps:
Checker finalization
*/

/*Display function 

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