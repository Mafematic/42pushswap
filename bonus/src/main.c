#include "../checker.h"

int     main(void)
{
        char    *line;

        while ((line = get_next_line(0)) != NULL)
        {
                printf("Checker: %s", line);
                free(line);
        }
        return (0);
}
