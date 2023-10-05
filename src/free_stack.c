#include "../inc/push_swap.h"

void free_stack(t_stack **stack)
{
    if (!*stack)
        return;

    t_node *current = (*stack)->head;

    if (current)
    {
        t_node *next_node;

        do
        {
            next_node = current->next;
            free(current);
            current = next_node;
        } while (current != (*stack)->head);  // This ensures that you only traverse the list once
    }

    free(*stack);
    *stack = NULL;  // To make sure the pointer points to nothing after being freed
}