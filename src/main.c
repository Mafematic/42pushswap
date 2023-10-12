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
#include <stdio.h>

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

int is_duplicate(t_stack *a, int nbr)
{
	t_node *current;

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

int process_and_append_number(char *number_str, t_stack **a)
{
    long nbr = ft_atol(number_str);

    if (nbr == 0 && number_str[0] != '0')
    {
        fprintf(stderr, "Invalid number: %s\n", number_str);
        return(1);
    }

    if (nbr > INT_MAX || nbr < INT_MIN)
    {
        fprintf(stderr, "Number out of range: %ld\n", nbr);
        return(1);
    }
	if (is_duplicate(*a, (int)nbr))
    {
        fprintf(stderr, "Duplicate number: %ld\n", nbr);
        return(1);
    }
    if (append(a, nbr) != 0)
		return 1;
	return 0;
}

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = create_stack();
	b = create_stack();
	if (a == NULL || b == NULL)
	{
		free_stack(&a);
		free_stack(&b);
		write(1, "Error\n", 6);
		exit(1);
	}

	if (argc == 2) 
    {
        char **numbers = ft_split(argv[1], ' ');
	
        int i = 0;
        while (numbers[i])
        {
            if (process_and_append_number(numbers[i], &a) != 0) 
			{
				// Handle the error (print a message, for instance)
				printf("Error: Invalid input detected.\n");
				
				// Free the allocated memory
				for (int j = 0; numbers[j]; j++)
				{
					free(numbers[j]);
				}
				free(numbers);
				free_stack(&a);
				free_stack(&b);

				// Exit the program or continue to other tasks
				exit(1);
			}
			i++;
        }

        // Free memory
        for (int j = 0; numbers[j]; j++)
        {
            free(numbers[j]);
        }
        free(numbers);
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            if (process_and_append_number(argv[i], &a) != 0)
			{
				printf("Error: Invalid input detected for argument %d.\n", i);
				free_stack(&a);
				free_stack(&b);
				exit(1);
			}
        }
    }
	display(a);

	//printf("%d\n", count_size(a));
	if (!check_if_sorted(a))
	{
		if (count_size(a) == 2)
		{
			sa(&a);
			write(1, "sa\n", 3);
		}
		else if (count_size(a) == 3)
			sort_size_three(&a);
		else if (count_size(a) == 4)
			sort_size_four(&a, &b);
		else if (count_size(a) == 5)
			sort_size_five(&a, &b);
		else
			push_swap(&a, &b);
	}

	display(a);
	free_stack(&a);
	free_stack(&b);
	return 0;
}

/*
Next Steps:
Norminette
Give prompt back if empty. 
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