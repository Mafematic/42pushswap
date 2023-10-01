#include "../inc/push_swap.h"

void rra(t_stack **a)
{
	if (!*a || !(*a)->head || !(*a)->head->next)
	{
		return;
	}

	t_node *last = (*a)->tail;

	// Link the old tail (i.e., new head) to the list
	last->next = (*a)->head;
	(*a)->head->prev = last;

	// Move the new tail's next to point to new head
	last->prev->next = last;

	// Update the tail and head pointers of the list
	(*a)->tail = last->prev;
	(*a)->head = last;
}

void rrb(t_stack **b)
{
	rra(b); // Use the same logic for rrb as rra
}

void rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}