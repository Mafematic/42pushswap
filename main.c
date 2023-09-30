#include "push_swap.h"
#include <stdio.h>




int count_size(t_stack *stack)
{
	int count = 0;
	if (!stack || !stack->head)
		return 0;

	t_node *current = stack->head;
	t_node *start = stack->head;

	do
	{
		count++;
		current = current->next;
	} while (current && current != start);

	return count;
}

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

int check_if_sorted(t_stack *stack)
{
	if (!stack || !stack->head)
		return 1; // considering an empty list as sorted

	t_node *current = stack->head;
	t_node *next_node = current->next;

	do
	{
		if (current->data > next_node->data && next_node != stack->head)
			return 0; // List is not sorted
		current = next_node;
		next_node = next_node->next;
	} while (current != stack->head);

	return 1; // List is sorted in ascending order
}

void display(t_stack *stack)
{
	if (!stack || !stack->head)
	{
		printf("Empty Stack\n");
		return;
	}

	t_node *p = stack->head;
	while (1)
	{
		printf("%d ", p->data);
		p = p->next;
		if (p == stack->head)
			break;
	}
	printf("\n");
}

// Initialize a new node
t_node *create_node(long data)
{
	t_node *new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
	{
		perror("Failed to create node");
		exit(1);
	}
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}

t_stack *create_stack()
{
	t_stack *new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
	{
		perror("Failed to allocate memory for stack");
		exit(1);
	}
	new_stack->head = NULL;
	new_stack->tail = NULL;
	return new_stack;
}

void append(t_stack **stack, long data)
{
	t_node *new_node = create_node(data);
	if (!new_node)
	{
		perror("Failed to allocate memory for new node");
		exit(1);
	}

	if ((*stack)->head == NULL && (*stack)->tail == NULL)
	{
		// The stack is empty, so make new_node both the head and the tail
		(*stack)->head = new_node;
		(*stack)->tail = new_node;
		new_node->next = new_node; // For circularity
		new_node->prev = new_node; // For circularity
	}
	else
	{
		// Insert new_node at the end
		new_node->prev = (*stack)->tail;
		new_node->next = (*stack)->head; // The next of new_node points back to the head
		(*stack)->tail->next = new_node; // The current tail's next points to new_node
		(*stack)->head->prev = new_node; // The head's previous points to new_node
		(*stack)->tail = new_node;		 // Update the tail of the list
	}
}

int find_min(t_stack *stack)
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

int position_minimum(t_stack *stack, int min)
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

void push(t_stack **stack, int x)
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

t_node *pop(t_stack **stack)
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
	ra(b); // Use the same logic for rb as ra
}

void rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

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

void sort_size_three(t_stack **a)
{
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


int main(void)
{
	t_stack *a = create_stack();
	t_stack *b = create_stack();

	// Define your array of numbers
	long numbers[] = {27, 17, 37, 11, 21};

	//long numbers[] = {7, 17, 19, 1, 4, 18, 20, 12, 14, 5, 9, 3, 6, 16, 10, 13, 2, 8, 11, 15};
	//long numbers[] = {149, 254, 141, 266, 294, 45, 5, 298, 347, 197, 307, 456, 280, 186, 499, 444, 405, 397, 14, 449, 301, 467, 356, 2, 271, 129, 353, 400, 91, 162, 326, 340, 21, 447, 258, 156, 98, 24, 368, 234, 55, 160, 34, 377, 190, 311, 121, 176, 41, 407, 72, 16, 290, 202, 132, 445, 1, 212, 15, 116, 399, 492, 36, 193, 328, 83, 273, 109, 22, 300, 99, 316, 288, 471, 312, 484, 20, 317, 490, 372, 435, 211, 82, 330, 173, 376, 208, 6, 495, 100, 111, 215, 293, 155, 123, 422, 120, 365, 19, 401, 329, 59, 304, 67, 18, 418, 411, 126, 319, 396, 308, 103, 221, 105, 360, 500, 276, 394, 324, 115, 306, 88, 213, 144, 101, 268, 48, 210, 106, 437, 124, 200, 393, 30, 146, 384, 327, 252, 166, 262, 387, 232, 140, 332, 255, 404, 337, 96, 309, 336, 143, 464, 299, 89, 343, 229, 188, 65, 159, 172, 235, 4, 40, 277, 114, 458, 63, 263, 305, 94, 478, 180, 370, 246, 187, 433, 477, 320, 236, 251, 198, 8, 369, 310, 469, 367, 61, 195, 357, 391, 486, 242, 62, 66, 133, 217, 189, 424, 29, 214, 58, 479, 256, 73, 257, 292, 49, 318, 474, 31, 150, 191, 53, 35, 92, 175, 223, 468, 491, 354, 302, 50, 249, 64, 28, 425, 171, 373, 272, 352, 362, 148, 475, 331, 38, 480, 432, 466, 259, 112, 374, 93, 386, 434, 233, 289, 145, 128, 349, 11, 26, 230, 37, 178, 158, 226, 465, 167, 442, 117, 12, 454, 296, 441, 243, 283, 85, 207, 108, 342, 323, 261, 264, 42, 54, 130, 448, 87, 409, 382, 346, 414, 174, 205, 250, 127, 339, 69, 32, 487, 17, 241, 75, 451, 47, 81, 406, 253, 378, 181, 281, 430, 278, 240, 25, 335, 237, 218, 113, 79, 179, 462, 192, 201, 443, 151, 358, 470, 165, 488, 428, 139, 222, 102, 338, 359, 135, 275, 203, 238, 489, 80, 417, 43, 452, 389, 284, 245, 182, 23, 170, 423, 450, 224, 341, 269, 260, 131, 297, 51, 313, 457, 239, 314, 199, 453, 157, 381, 419, 76, 119, 90, 415, 350, 153, 282, 206, 325, 375, 168, 497, 455, 476, 482, 410, 426, 228, 420, 333, 39, 439, 364, 315, 366, 194, 322, 74, 118, 27, 265, 427, 184, 483, 459, 164, 134, 295, 225, 461, 408, 71, 472, 429, 104, 496, 52, 177, 204, 183, 244, 152, 485, 57, 344, 481, 286, 7, 440, 392, 390, 403, 345, 3, 125, 110, 460, 379, 247, 438, 185, 363, 231, 279, 86, 10, 473, 361, 463, 13, 44, 248, 388, 413, 77, 303, 334, 136, 421, 385, 137, 220, 97, 147, 196, 416, 169, 291, 9, 209, 46, 216, 56, 33, 395, 348, 154, 267, 227, 285, 142, 351, 412, 95, 493, 122, 494, 321, 68, 446, 436, 355, 274, 138, 78, 398, 270, 498, 107, 84, 163, 402, 431, 219, 60, 383, 287, 380, 70, 371, 161};

	int num_elements = sizeof(numbers) / sizeof(numbers[0]);

	for (int i = 0; i < num_elements; i++)
	{
		long nbr = numbers[i];

		// Check for syntax errors or other conditions
		// if (error_syntax(numbers[i]))
		//{
		// Handle the error if needed
		// }

		// Check if nbr is within INT_MIN and INT_MAX range
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			// Handle the error if needed
		}

		// Check for repetition errors
		//if (error_repetition(a, (int)nbr))
		//{
			// Handle the error if needed
		//}

		// Append the number to stack 'a'
		append(&a, nbr);
	}

	display(a);

	printf("%d\n", count_size(a));
	if (!check_if_sorted(a))
	{
		if (count_size(a) == 2)
		{
			sa(&a);
			printf("sa\n");
		}
		else if (count_size(a) == 3)
			sort_size_three(&a);
		else if (count_size(a) == 4)
			sort_size_four(&a, &b);
		else if (count_size(a) == 5)
			sort_size_five(&a, &b, 5);
		//else
		//	push_swap(&a, &b);
	}

	display(a);
	// Remember to free your stack at the end
	//free_stack(&a);


	return 0;
}
