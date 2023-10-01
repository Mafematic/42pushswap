#include "../inc/push_swap.h"

static void push(t_stack **stack, int x)
{
	t_node *t = create_node(x);

	if (!*stack || !(*stack)->head)
	{
		if (!*stack)
		{
			*stack = (t_stack *)malloc(sizeof(t_stack));
			if (!*stack)
			{
				perror("Failed to initialize stack");
				exit(1);
			}
		}
		(*stack)->head = t;
		(*stack)->tail = t;
		t->next = t; // Points to itself, as it's the only element
		t->prev = t; // Points to itself
	}
	else
	{
		t->next = (*stack)->head;
		t->prev = (*stack)->tail;
		(*stack)->head->prev = t;
		(*stack)->tail->next = t;
		(*stack)->head = t;
	}
}

static t_node *pop(t_stack **stack)
{
	if (!*stack || !(*stack)->head)
	{
		return NULL;
	}

	t_node *temp = (*stack)->head;
	if ((*stack)->head == (*stack)->tail)
	{
		// Only one node left in the list
		(*stack)->head->next = NULL;
		(*stack)->head->prev = NULL;
		(*stack)->head = NULL;
		(*stack)->tail = NULL;
	}
	else
	{
		(*stack)->head = (*stack)->head->next;
		(*stack)->tail->next = (*stack)->head;
		(*stack)->head->prev = (*stack)->tail;
	}
	temp->next = NULL; // break the circular link for the node being popped
	temp->prev = NULL;

	return temp;
}

void pa(t_stack **a, t_stack **b)
{
	t_node *node = pop(b);
	if (node)
	{
		push(a, node->data);

		if (!(*a)->head->next)
		{
			(*a)->tail = (*a)->head;
		}
		free(node);
	}
}

void pb(t_stack **a, t_stack **b)
{
	t_node *node = pop(a);
	if (node)
	{
		push(b, node->data);

		if (!(*b)->head->next)
		{
			(*b)->tail = (*b)->head;
		}
		free(node);
	}
}