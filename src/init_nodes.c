#include "../inc/push_swap.h"

void set_cheapest(t_stack *b)
{
	long best_match_value;
	t_node *best_match_node = NULL; // Initialize to NULL
	t_node *current_node;
	t_node *start_node; // For tracking the starting node

	if (b == NULL || b->head == NULL)
		return;

	best_match_value = LONG_MAX;
	current_node = start_node = b->head;

	do
	{
		current_node->cheapest = false;
		if (current_node->push_price < best_match_value)
		{
			best_match_value = current_node->push_price;
			best_match_node = current_node;
		}
		current_node = current_node->next;
	} while (current_node && current_node != start_node);

	if (best_match_node)
		best_match_node->cheapest = true;
}

void set_price(t_stack *a, t_stack *b)
{
	int len_a;
	int len_b;
	t_node *start_node; // For tracking the starting node
	t_node *current_b;

	len_a = count_size(a);
	len_b = count_size(b);

	current_b = start_node = b->head; // Use the head of stack b for iteration

	do
	{
		current_b->push_price = current_b->current_position;
		if (!(current_b->above_median))
			current_b->push_price = len_b - (current_b->current_position);
		if (current_b->target_node->above_median)
			current_b->push_price += current_b->target_node->current_position;
		else
			current_b->push_price += len_a - (current_b->target_node->current_position);
		current_b = current_b->next;
	} while (current_b && current_b != start_node);
}


void set_target_node(t_stack *a, t_stack *b)
{
	t_node *current_a;
	t_node *current_b = b->head;
	t_node *start_b = b->head;
	t_node *target_node;
	long best_match_index;

	if (!a->head || !b->head)
		return;

	do
	{
		current_a = a->head;
		best_match_index = LONG_MAX;

		do
		{
			if (current_a->data > current_b->data && current_a->data < best_match_index)
			{
				best_match_index = current_a->data;
				target_node = current_a;
			}
			current_a = current_a->next;
		} while (current_a && current_a != a->head); // Ensure not to process the a's head twice

		if (LONG_MAX == best_match_index)
			current_b->target_node = find_smallest(a);
		else
			current_b->target_node = target_node;

		current_b = current_b->next;
	} while (current_b && current_b != start_b); // Ensure not to process the b's head twice
}



void set_current_position(t_stack *stack)
{
	int i;
	int centerline;
	t_node *current = stack->head;
	t_node *start = stack->head;

	i = 0;
	if (stack == NULL || stack->head == NULL)
		return;
	centerline = count_size(stack) / 2;

	// Initial setting for the head node
	current->current_position = i;
	if (i <= centerline)
		current->above_median = true;
	else
		current->above_median = false;
	current = current->next;
	++i;

	// For remaining nodes
	while (current && current != start) // Ensure we don't process the head node twice
	{
		current->current_position = i;
		if (i <= centerline)
			current->above_median = true;
		else
			current->above_median = false;
		current = current->next;
		++i;
	}
}


void init_nodes(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}