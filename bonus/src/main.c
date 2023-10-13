#include "../checker.h"
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

	a = create_stack();
	b = create_stack();
	if (a == NULL || b == NULL)
		exit_error(&a, &b, NULL);
    if (argc == 2)
		process_single_arg(argv[1], &a, &b);
	else
		process_multiple_args(argc, argv, &a, &b);

    display(a);
    while ((line = get_next_line(0)) != NULL)
    {
        if (ft_strcmp(line, "ra\n") == 0)
            ra(&a);
        else if (ft_strcmp(line, "rb\n") == 0)
            rb(&b);
        else if (ft_strcmp(line, "rr\n") == 0)
            rr(&a, &b);
        else if (ft_strcmp(line, "rra\n") == 0)
            rra(&a);
        else if (ft_strcmp(line, "rrb\n") == 0)
            rrb(&b);
        else if (ft_strcmp(line, "rrr\n") == 0)
            rrr(&a, &b);
        else if (ft_strcmp(line, "sa\n") == 0)
            sa(&a);
        else if (ft_strcmp(line, "sb\n") == 0)
            sb(&b);
        else if (ft_strcmp(line, "pa\n") == 0)
            pa(&a, &b);
        else if (ft_strcmp(line, "pb\n") == 0)
            pb(&a, &b);

        free(line);
    }
    display(a);
    return (0);
}

/*
function main(arguments):
    stack_a = initialize_empty_stack()
    stack_b = initialize_empty_stack()

    for number in arguments:
        push(stack_a, number)

    while operation = read_from_stdin():
        if operation == "ra":
            rotate(stack_a)
        elif operation == "pb":
            push_b(stack_a, stack_b)
        ...
        # Add conditions for other operations

    if is_sorted(stack_a) and is_empty(stack_b):
        print("OK")
    else:
        print("KO")
*/