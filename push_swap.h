#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>

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

#endif