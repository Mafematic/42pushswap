#include "../checker.h"
#include <stdio.h>

//# define RED   "\x1B[31m"
# define RED "\033[31m"
# define GRN "\033[32m"
//# define GRN   "\x1B[32m"
//# define RESET "\x1B[0m"
#define RESET "\033[0m"

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

int     main(int argc, char **argv)
{
    char    *line;
    t_stack	*a;
    t_stack	*b;
    int valid;

	a = create_stack();
	b = create_stack();
	if (a == NULL || b == NULL)
    {
        free_stack(&a);
        free_stack(&b);
        return 1;
    }

    if (argc == 1)
    {
        free_stack(&a);
        free_stack(&b);
        return 0;
    }
    else if (argc == 2)
		process_single_arg(argv[1], &a, &b);
	else
		process_multiple_args(argc, argv, &a, &b);
    while ((line = get_next_line(0)) != NULL)
    {
        valid = 0;
        if (ft_strcmp(line, "ra\n") == 0)
        {
            ra(&a);
            valid = 1;
        }
        if (ft_strcmp(line, "rb\n") == 0)
        {
            rb(&b);
            valid = 1;
        }
        if (ft_strcmp(line, "rr\n") == 0)
        {
            rr(&a, &b);
            valid = 1;
        }
        if (ft_strcmp(line, "rra\n") == 0)
        {
            rra(&a);
            valid = 1;
        }
        if (ft_strcmp(line, "rrb\n") == 0)
        {
            rrb(&b);
            valid = 1;
        }
        if (ft_strcmp(line, "rrr\n") == 0)
        {
            rrr(&a, &b);
            valid = 1;
        }
        if (ft_strcmp(line, "sa\n") == 0)
        {
            sa(&a);
            valid = 1;
        }
        if (ft_strcmp(line, "sb\n") == 0)
        {
            sb(&b);
            valid = 1;
        }
        if (ft_strcmp(line, "pa\n") == 0)
        {
            pa(&a, &b);
            valid = 1;
        }
        if (ft_strcmp(line, "pb\n") == 0)
        {
            pb(&a, &b);
            valid = 1;
        }
        free(line);
        if (!valid)
        {
            write(2, "Error\n", 6);
            get_next_line(-1);
            free_stack(&a);
	        free_stack(&b);
            return 1;
        }
    }
    if (line == NULL && (!check_if_sorted(a) || !is_empty(b)))
    {
        write(1, RED"KO\n"RESET, 8);
        free_stack(&a);
	    free_stack(&b);
        get_next_line(-1);
        return 0;
    }
    else 
    {
        write(1, GRN "OK\n" RESET, 8);
        free_stack(&a);
	    free_stack(&b);
        get_next_line(-1);
        return 0;
    }
}
