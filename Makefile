# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/20 19:51:59 by mhaddadi          #+#    #+#              #
#    Updated: 2025/08/06 19:33:45 by mhaddadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Push Swap Makefile


# Configuration
NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -rf
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a
BUILD_DIR   = build
BONUS_NAME  = checker

# Source code
SRCS_DIR = src

SRCS = \
	$(SRCS_DIR)/push_swap/push_swap.c \ 
	$(SRCS_DIR)/push_swap/stack.c \
	$(SRCS_DIR)/push_swap/stack_utils.c \
	$(SRCS_DIR)/push_swap/operations_s_p.c \
	$(SRCS_DIR)/push_swap/operations_rr.c \
	$(SRCS_DIR)/push_swap/operations_rrr.c \
	$(SRCS_DIR)/push_swap/small_sort.c \
	$(SRCS_DIR)/push_swap/chunksort.c


SRCS_BONUS = \
	$(SRCS_DIR)/checker/checker_bonus.c \
	$(SRCS_DIR)/checker/stack_bonus.c

# Object files
OBJS       = $(SRCS:$(SRCS_DIR)/push_swap/%.c=$(BUILD_DIR)/push_swap/%.o)
OBJS_BONUS = $(SRCS_BONUS:$(SRCS_DIR)/checker/%.c=$(BUILD_DIR)/checker/%.o)

create_dirs:
	@mkdir -p build/checker
	@mkdir -p build/pushswap


# Targets
all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): create_dirs $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

# Compile .c to .o in build/
$(BUILD_DIR)/push_swap/%.o: $(SRCS_DIR)/push_swap/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

$(BUILD_DIR)/checker/%.o: $(SRCS_DIR)/checker/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

$(BONUS_NAME): create_dirs $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -L$(LIBFT_DIR) -lft -o $(BONUS_NAME)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(BUILD_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all


.PHONY: all clean fclean re bonus
