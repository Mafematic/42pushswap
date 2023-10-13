#include "../checker.h"

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

void	exit_error(t_stack **a, t_stack **b, char **numbers)
{
	int	i;

	i = 0;
	if (numbers)
	{
		while (numbers[i])
		{
			free(numbers[i]);
			i++;
		}
		free(numbers);
	}
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	write(1, "Error\n", 6);
	exit(1);
}