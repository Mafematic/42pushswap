#include "../inc/push_swap.h"

static t_node *find_highest(t_stack *stack)
{
	long highest;
	t_node *highest_node = NULL;
	t_node *current_node;
	t_node *start_node; // For tracking the starting node

	if (stack == NULL || stack->head == NULL)
		return NULL;

	highest = LONG_MIN;
	current_node = start_node = stack->head;

	do
	{
		if (current_node->data > highest)
		{
			highest = current_node->data;
			highest_node = current_node;
		}
		current_node = current_node->next;
	} while (current_node && current_node != start_node);

	return highest_node;
}

void sort_size_three(t_stack **a)
{
	t_node *highest_node;

	highest_node = find_highest(*a);
	if ((*a)->head == highest_node)
	{
		ra(a);
		write(1, "ra\n", 3);
	}
		
	else if ((*a)->head->next == highest_node)
	{
		rra(a);
		write(1, "rra\n", 4);
	}
	if ((*a)->head->data > (*a)->head->next->data)
	{
		sa(a);
		write(1, "sa\n", 3);
	}
	
	/*
	if (!*a || !(*a)->head || !(*a)->head->next || !(*a)->head->next->next)
	{
		return; // Nothing to sort
	}

	int first = (*a)->head->data;
	int second = (*a)->head->next->data;
	int third = (*a)->head->next->next->data;

	// Case 3 1 2
	if (first > third && second < third)
	{
		ra(a);
		printf("ra\n");
	}
	// Case 2 1 3
	else if (first > second && first < third)
	{
		sa(a);
		printf("sa\n");
	}
	// Case 1 3 2
	else if (first < third && second > third)
	{
		sa(a);
		ra(a);
		printf("sa\n");
		printf("ra\n");
	}
	// Case 2 3 1
	else if (first > third && second > first)
	{
		rra(a);
		printf("rra\n");
	}
	// Case 3 2 1
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
		printf("sa\n");
		printf("rra\n");
	}
	*/
}
