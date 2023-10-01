#include "../inc/push_swap.h"

void sa(t_stack **a)
{
	if (!*a || !(*a)->head || !(*a)->head->next)
	{
		return; // Nothing to swap
	}

	t_node *first = (*a)->head;
	t_node *second = first->next;

	// If there's a third node, connect it to the first
	if (second->next != first)
	{
		first->next = second->next;
		second->next->prev = first;
	}
	else
	{
		// If there's no third node (i.e., only two nodes in the list),
		// they will point to each other after the swap.
		first->next = second;
		second->next = first;
	}

	// Connect first's prev (which is the last node) to the second
	first->prev->next = second;
	second->prev = first->prev;

	// Connect first to second and second to first
	second->next = first;
	first->prev = second;

	// Update the head
	(*a)->head = second;

	// If there were only two nodes, update the tail
	if ((*a)->tail == second)
	{
		(*a)->tail = first;
	}
}

void sb(t_stack **b)
{
	sa(b);
}

void ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}