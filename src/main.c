#include "../inc/push_swap.h"
#include <stdio.h>


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

int append(t_stack **stack, long data)
{
	t_node *new_node = create_node(data);
	if (!new_node)
		return (1);

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
	return 0;
}

int	ft_iswhitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
	{
		return (1);
	}
	return (0);
}

long	ft_atoi(const char *nptr)
{
	int		i;
	int		is_negative;
	long	num;

	i = 0;
	is_negative = 1;
	num = 0;
	while (ft_iswhitespace(nptr[i]))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		is_negative *= -1;
		i++;
	}
	if (!(nptr[i] >= '0' && nptr[i] <= '9'))
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num *= 10;
		num += nptr[i] - '0';
		i++;
	}
	return (num * is_negative);
}

int process_and_append_number(char *number_str, t_stack **a)
{
    long nbr = ft_atoi(number_str);  // Convert string argument to long

    // Check for invalid conversion (e.g., non-numeric inputs).
    if (nbr == 0 && number_str[0] != '0')
    {
        fprintf(stderr, "Invalid number: %s\n", number_str);
        return(1);
    }

    // Check if nbr is within INT_MIN and INT_MAX range
    if (nbr > INT_MAX || nbr < INT_MIN)
    {
        fprintf(stderr, "Number out of range: %ld\n", nbr);
        return(1);
    }
    // Append the number to stack 'a'
    if (append(a, nbr) != 0)
		return 1;
	return 0;
}

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = create_stack();
	b = create_stack();
	if (a == NULL || b == NULL)
	{
		free_stack(&a);
		free_stack(&b);
		write(1, "Error\n", 6);
		exit(1);
	}

	// Define your array of numbers
	//long numbers[] = {27, 17, 37, 21, 11, 35};

	//long numbers[] = {7, 17, 19, 1, 4, 18, 20, 12, 14, 5, 9, 3, 6, 16, 10, 13, 2, 8, 11, 15};
	//long numbers[] = {149, 254, 141, 266, 294, 45, 5, 298, 347, 197, 307, 456, 280, 186, 499, 444, 405, 397, 14, 449, 301, 467, 356, 2, 271, 129, 353, 400, 91, 162, 326, 340, 21, 447, 258, 156, 98, 24, 368, 234, 55, 160, 34, 377, 190, 311, 121, 176, 41, 407, 72, 16, 290, 202, 132, 445, 1, 212, 15, 116, 399, 492, 36, 193, 328, 83, 273, 109, 22, 300, 99, 316, 288, 471, 312, 484, 20, 317, 490, 372, 435, 211, 82, 330, 173, 376, 208, 6, 495, 100, 111, 215, 293, 155, 123, 422, 120, 365, 19, 401, 329, 59, 304, 67, 18, 418, 411, 126, 319, 396, 308, 103, 221, 105, 360, 500, 276, 394, 324, 115, 306, 88, 213, 144, 101, 268, 48, 210, 106, 437, 124, 200, 393, 30, 146, 384, 327, 252, 166, 262, 387, 232, 140, 332, 255, 404, 337, 96, 309, 336, 143, 464, 299, 89, 343, 229, 188, 65, 159, 172, 235, 4, 40, 277, 114, 458, 63, 263, 305, 94, 478, 180, 370, 246, 187, 433, 477, 320, 236, 251, 198, 8, 369, 310, 469, 367, 61, 195, 357, 391, 486, 242, 62, 66, 133, 217, 189, 424, 29, 214, 58, 479, 256, 73, 257, 292, 49, 318, 474, 31, 150, 191, 53, 35, 92, 175, 223, 468, 491, 354, 302, 50, 249, 64, 28, 425, 171, 373, 272, 352, 362, 148, 475, 331, 38, 480, 432, 466, 259, 112, 374, 93, 386, 434, 233, 289, 145, 128, 349, 11, 26, 230, 37, 178, 158, 226, 465, 167, 442, 117, 12, 454, 296, 441, 243, 283, 85, 207, 108, 342, 323, 261, 264, 42, 54, 130, 448, 87, 409, 382, 346, 414, 174, 205, 250, 127, 339, 69, 32, 487, 17, 241, 75, 451, 47, 81, 406, 253, 378, 181, 281, 430, 278, 240, 25, 335, 237, 218, 113, 79, 179, 462, 192, 201, 443, 151, 358, 470, 165, 488, 428, 139, 222, 102, 338, 359, 135, 275, 203, 238, 489, 80, 417, 43, 452, 389, 284, 245, 182, 23, 170, 423, 450, 224, 341, 269, 260, 131, 297, 51, 313, 457, 239, 314, 199, 453, 157, 381, 419, 76, 119, 90, 415, 350, 153, 282, 206, 325, 375, 168, 497, 455, 476, 482, 410, 426, 228, 420, 333, 39, 439, 364, 315, 366, 194, 322, 74, 118, 27, 265, 427, 184, 483, 459, 164, 134, 295, 225, 461, 408, 71, 472, 429, 104, 496, 52, 177, 204, 183, 244, 152, 485, 57, 344, 481, 286, 7, 440, 392, 390, 403, 345, 3, 125, 110, 460, 379, 247, 438, 185, 363, 231, 279, 86, 10, 473, 361, 463, 13, 44, 248, 388, 413, 77, 303, 334, 136, 421, 385, 137, 220, 97, 147, 196, 416, 169, 291, 9, 209, 46, 216, 56, 33, 395, 348, 154, 267, 227, 285, 142, 351, 412, 95, 493, 122, 494, 321, 68, 446, 436, 355, 274, 138, 78, 398, 270, 498, 107, 84, 163, 402, 431, 219, 60, 383, 287, 380, 70, 371, 161};

	//int num_elements = sizeof(numbers) / sizeof(numbers[0]);


	if (argc == 2) 
    {
        char **numbers = ft_split(argv[1], ' ');
	
        int i = 0;
        while (numbers[i])
        {
            if (process_and_append_number(numbers[i], &a) != 0) 
			{
				// Handle the error (print a message, for instance)
				printf("Error: Invalid input detected.\n");
				
				// Free the allocated memory
				for (int j = 0; numbers[j]; j++)
				{
					free(numbers[j]);
				}
				free(numbers);
				free_stack(&a);
				free_stack(&b);

				// Exit the program or continue to other tasks
				exit(1);
			}
			i++;
        }

        // Free memory
        for (int j = 0; numbers[j]; j++)
        {
            free(numbers[j]);
        }
        free(numbers);
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            if (process_and_append_number(argv[i], &a) != 0)
			{
				printf("Error: Invalid input detected for argument %d.\n", i);
				free_stack(&a);
				free_stack(&b);
				exit(1);
			}
        }
    }
	display(a);

	//printf("%d\n", count_size(a));
	if (!check_if_sorted(a))
	{
		if (count_size(a) == 2)
		{
			sa(&a);
			write(1, "sa\n", 3);
		}
		else if (count_size(a) == 3)
			sort_size_three(&a);
		else if (count_size(a) == 4)
			sort_size_four(&a, &b);
		else if (count_size(a) == 5)
			sort_size_five(&a, &b);
		else
			push_swap(&a, &b);
	}

	display(a);
	free_stack(&a);
	free_stack(&b);
	return 0;
}

/*
Next Steps:
Norminette
Last Error check
Checker finalization
*/
