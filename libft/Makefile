# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaddadi <mhaddadi@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/27 09:11:07 by mhaddadi          #+#    #+#              #
#    Updated: 2025/04/27 09:11:16 by mhaddadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                              LIBFT MAKEFILE                                  #
# **************************************************************************** #

# Variables
NAME				= libft.a

CC					= cc
CFLAGS			=	-Wall -Wextra -Werror
ARFLAGS			= rcs
RM					= rm -f
# Sources

SRCS_DIR		= src
BUILD_DIR		= build


SRCS				= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
							ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
							ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
							ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
							ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
							ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
							ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

# Bonus part sources

SRCS_BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
							ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
							ft_lstmap.c


OBJS        = $(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS_BONUS  = $(SRCS_BONUS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)


# Targets

all: $(NAME)

$(NAME): $(OBJS)
	ar $(ARFLAGS) $@ $^

$(BUILD_DIR)/%.o:$(SRCS_DIR)/%.c
	$(CC) -c $(CFLAGS) $^ -o $@ 

bonus: $(NAME) $(OBJS_BONUS)
	ar $(ARFLAGS) $(NAME) $(OBJS_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
