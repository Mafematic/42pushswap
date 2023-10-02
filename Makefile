# Compiler and flags
CC = cc
CFLAGS = -g -Wall -Werror -Wextra

# Source dir and files
SRC_DIR = src
SRCS = src/count_size.c src/create_node.c src/create_stack.c src/find_smallest.c src/ft_split.c src/ft_strdup.c src/ft_substr.c src/ft_strlen.c src/init_nodes.c src/main.c src/move_nodes.c \
	src/pa_pb.c src/pushswap.c src/ra_rb_rr.c src/rra_rrb_rrr.c src/sa_sb_ss.c src/sort_four_five.c src/sort_three.c 

# Object files
OBJ_DIR = obj
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Output binary
TARGET = push_swap

# Phony targets
.PHONY: all clean fclean re

# Default target (all)
all: $(TARGET)

# Linking the program
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Compilation rule for object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean object files
clean:
	rm -rf $(OBJ_DIR)

# Remove all generated files
fclean: clean
	rm -f $(TARGET)

# Rebuild everything
re: fclean all