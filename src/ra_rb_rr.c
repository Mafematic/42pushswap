#include "../inc/push_swap.h"

void ra(t_stack **a)
{
	if (!*a || !(*a)->head || !(*a)->head->next)
	{
		return; // Nothing to rotate
	}

	(*a)->tail = (*a)->head;	   // Move the head node to the tail
	(*a)->head = (*a)->head->next; // Set the new head
}

void rb(t_stack **b)
{
	ra(b);
}

void rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}