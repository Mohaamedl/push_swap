# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/20 19:51:59 by mhaddadi          #+#    #+#              #
#    Updated: 2025/07/20 20:16:37 by mhaddadi         ###   ########.fr        #
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

# Source code
SRCS_DIR = src

SRCS = \
	$(SRCS_DIR)/push_swap.c \
	$(SRCS_DIR)/stack.c

SRCS_BONUS = \
	$(SRCS_DIR)/checker.c

# Object files
OBJS       = $(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS_BONUS = $(SRCS_BONUS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)

# Targets
all: $(NAME)

bonus: all

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

# Compile .c to .o in build/
$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

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


