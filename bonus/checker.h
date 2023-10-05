#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif