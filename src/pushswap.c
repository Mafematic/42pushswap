#include "../inc/push_swap.h"

void push_swap(t_stack **a, t_stack **b)
{
	t_node *smallest;
	int len_a;

	len_a = count_size(*a);
	if (len_a == 5)
		sort_size_five(a, b, 5);
	else
	{
		while (len_a-- > 3)
		{
			pb(a, b);
			printf("pb\n");
		}
			
	}
	sort_size_three(a);
	while ((*b)->head)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while ((*a)->head != smallest)
		{
			ra(a);
			printf("ra\n");
		}
	else
		while ((*a)->head != smallest)
		{
			rra(a);
			printf("rra\n");
		}
}