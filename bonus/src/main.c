#include "../checker.h"

int     main(void)
{
        char    *line;
		t_stack *a;
		t_stack *b;

		a = create_stack();
		b = create_stack();

        while ((line = get_next_line(0)) != NULL)
        {
                printf("Checker: %s", line);
                free(line);
        }
        return (0);
}

/*
function main(arguments):
    stack_a = initialize_empty_stack()
    stack_b = initialize_empty_stack()

    for number in arguments:
        push(stack_a, number)

    while operation = read_from_stdin():
        if operation == "ra":
            rotate(stack_a)
        elif operation == "pb":
            push_b(stack_a, stack_b)
        ...
        # Add conditions for other operations

    if is_sorted(stack_a) and is_empty(stack_b):
        print("OK")
    else:
        print("KO")
*/