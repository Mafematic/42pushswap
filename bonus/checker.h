#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target_node;
	bool			above_mid;
	bool			best_match;
	int				current_position;
	int				push_sum;
}	t_node;

typedef struct s_stack
{
	t_node *head;
	t_node *tail;
} t_stack;

int	append(t_stack **stack, long data);
t_node	*create_node(long data);
t_stack	*create_stack(void);
void	exit_error(t_stack **a, t_stack **b, char **numbers);
void	free_stack(t_stack **stack);
long	ft_atol(const char *nptr);
char	**ft_split(char *s, char c);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
int		pa(t_stack **a, t_stack **b);
int		pb(t_stack **a, t_stack **b);
int	process_and_append_number(char *number_str, t_stack **a); 
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

#endif