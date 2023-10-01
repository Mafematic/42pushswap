#include "../inc/push_swap.h"


static int find_min(t_stack *stack)
{
	int min = INT32_MAX;
	if (!stack || !stack->head)
		return min; // Return INT32_MAX if list is empty

	t_node *p = stack->head;
	int firstRun = 1;

	while (firstRun || p != stack->head)
	{
		if (p->data < min)
		{
			min = p->data;
		}
		p = p->next;
		firstRun = 0;
	}
	return min;
}

static int position_minimum(t_stack *stack, int min)
{
	int index = 0;
	t_node *p = stack->head;
	while (p != NULL)
	{
		if (min == p->data)
		{
			return index;
		}
		index++;
		p = p->next;
	}
	return -1;
}

void sort_size_four(t_stack **a, t_stack **b)
{
	int min = find_min(*a);
	int pos = position_minimum(*a, min);

	// Move the minimum value to the top of the stack
	if (pos == 2) // if position_minimum is 0-based
	{
		while ((*a)->head->data != min)
		{
			rra(a);
			printf("rra\n");
		}
	}
	else
	{
		while ((*a)->head->data != min)
		{
			ra(a);
			printf("ra\n");
		}
	}

	// Push the minimum value to stack_b
	pb(a, b);
	printf("pb\n");

	// Sort the remaining 3 elements
	sort_size_three(a);

	// Pop the element back from stack_b to stack_a
	pa(a, b);
	printf("pa\n");
}

void sort_size_five(t_stack **a, t_stack **b, int size)
{
	int min = find_min(*a);
	int pos = position_minimum(*a, min);

	if (pos == 3 || pos == 4)
	{
		while ((*a)->head->data != min)
		{
			rra(a);
			printf("rra\n");
		}
	}
	else
	{
		while ((*a)->head->data != min)
		{
			ra(a);
			printf("ra\n");
		}
	}

	pb(a, b);
	printf("pb\n");

	size--;

	sort_size_four(a, b);

	pa(a, b);
	printf("pa\n");
}