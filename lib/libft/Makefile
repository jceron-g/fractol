# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jceron-g <jceron-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 14:59:39 by jceron-g          #+#    #+#              #
#    Updated: 2024/02/06 09:42:52 by jceron-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
SOURCE = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		 ft_tolower.c ft_toupper.c ft_strchr.c ft_strlcat.c ft_strlcpy.c \
		 ft_strlen.c ft_strncmp.c ft_strrchr.c ft_atoi.c ft_memset.c ft_bzero.c \
		 ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_calloc.c \
		 ft_strdup.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		 ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_striteri.c ft_strmapi.c \
		 ft_split.c
		 
SOURCE_B = ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

SOURCE_GNL = get_next_line.c get_next_line_utils.c

SOURCE_PRINT = ft_printf.c ft_printuint.c ft_putchar.c ft_putdec.c ft_puthex.c ft_putstr.c
 
OBJECTS = $(SOURCE:.c=.o)

OBJECTS_B = $(SOURCE_B:.c=.o)

OBJECTS_GNL = $(SOURCE_GNL:.c=.o)

OBJECTS_PRINT = $(SOURCE_PRINT:.c=.o)

all: $(NAME) bonus bonus_gnl bonus_print

$(NAME): $(OBJECTS) 
	ar crs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJECTS_B)
		ar rcs $(NAME) $(OBJECTS_B)
		
bonus_gnl: $(OBJECTS_GNL)
		ar rcs $(NAME) $(OBJECTS_GNL)

bonus_print: $(OBJECTS_PRINT)
		ar rcs $(NAME) $(OBJECTS_PRINT)
clean:
		rm -f $(OBJECTS) $(OBJECTS_B) $(OBJECTS_GNL) $(OBJECTS_PRINT)

fclean: clean
		rm -f $(NAME) bonus bonus_gnl bonus_print
		
re: fclean all

.PHONY: all bonus bonus_gnl bonus_print clean fclean re