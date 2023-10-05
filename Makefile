# Compiler and flags
CC = cc
CFLAGS = -g -Wall -Werror -Wextra

# Source dir and files
SRC_DIR = src
SRCS = src/count_size.c src/create_node.c src/create_stack.c src/find_smallest.c src/free_stack.c src/ft_split.c src/ft_strdup.c src/ft_substr.c src/ft_strlen.c src/init_nodes.c src/main.c src/move_nodes.c \
	src/pa_pb.c src/perform_rotation.c src/pushswap.c src/ra_rb_rr.c src/rra_rrb_rrr.c src/sa_sb_ss.c src/set_target_nodes.c src/sort_four_five.c src/sort_three.c 

BONUS_SRC_DIR = bonus/src
BONUS_SRCS = bonus/src/get_next_line.c bonus/src/get_next_line_utils.c bonus/src/main.c \
			bonus/src/create_stack.c

# Object files
OBJ_DIR = obj
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

BONUS_OBJ_DIR = obj_bonus
BONUS_OBJS = $(BONUS_SRCS:$(BONUS_SRC_DIR)/%.c=$(BONUS_OBJ_DIR)/%.o)

# Output binary
TARGET = push_swap
BONUS_TARGET = checker

# Phony targets
.PHONY: all clean fclean re bonus

# Default target (all)
all: $(TARGET)

bonus: $(TARGET) $(BONUS_TARGET)

# Linking the program
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(BONUS_TARGET): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Compilation rule for object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c | $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BONUS_OBJ_DIR):
	mkdir -p $(BONUS_OBJ_DIR)

# Clean object files
clean:
	rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)

# Remove all generated files
fclean: clean
	rm -f $(TARGET) $(BONUS_TARGET)

# Rebuild everything
re: fclean all