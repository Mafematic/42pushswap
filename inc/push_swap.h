#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

typedef struct s_node
{
	int data;
	struct s_node *next;
	struct s_node *prev;
	struct s_node *target_node;
	bool above_median;
	bool cheapest;
	int current_position;
	int push_price;
} t_node;

typedef struct s_stack
{
	t_node *head;
	t_node *tail;
} t_stack;

int count_size(t_stack *stack);
t_node *create_node(long data);
t_stack *create_stack(void);
t_node *find_smallest(t_stack *stack);
void init_nodes(t_stack *a, t_stack *b);
void move_nodes(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);
void push_swap(t_stack **a, t_stack **b);
void ra(t_stack **a);
void rb(t_stack **b);
void rr(t_stack **a, t_stack **b);
void rra(t_stack **a);
void rrb(t_stack **b);
void rrr(t_stack **a, t_stack **b);
void sa(t_stack **a);
void sb(t_stack **b);
void ss(t_stack **a, t_stack **b);
void set_cheapest(t_stack *b);
void set_current_position(t_stack *stack);
void set_price(t_stack *a, t_stack *b);
void set_target_node(t_stack *a, t_stack *b);
void sort_size_three(t_stack **a);
void sort_size_four(t_stack **a, t_stack **b);
void sort_size_five(t_stack **a, t_stack **b, int size);

#endif