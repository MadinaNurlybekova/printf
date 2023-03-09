# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnurlybe <mnurlybe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 20:05:01 by mnurlybe          #+#    #+#              #
#    Updated: 2023/03/09 20:07:49 by mnurlybe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

MY_SOURCES = libft/ft_isdigit.c \
	libft/ft_strlen.c \
	libft/ft_strlcpy.c \
	libft/ft_strchr.c \
	libft/ft_strncmp.c \
	bonuses/ft_c_s_p.c \
	bonuses/ft_d_i_u.c \
	bonuses/ft_hex.c \
	bonuses/utils_bonus.c \
	utilits/ft_decimal_to_str.c \
	utilits/ft_init.c \
	utilits/ft_putstr.c \
	utilits/ft_adds.c \
	utilits/ft_flags.c \
	utilits/ft_format.c \
	ft_printf.c
	
MY_HEADER = ft_printf.h
			
MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS = -Wall -Werror -Wextra

.c.o:
	cc $(CFLAGS) -c -I $(MY_HEADER) $< -o ${<:.c=.o}

$(NAME): $(MY_OBJECTS)
	ar rcs $(NAME) $(MY_SOURCES) $(MY_OBJECTS)
# gcc $(CFLAGS) $(MY_SOURCES) $(MY_OBJECTS)

bonus: 
	ar rcs $(NAME) $(MY_SOURCES) $(MY_OBJECTS)
# gcc $(CFLAGS) $(MY_HEADER) $(MY_SOURCES) $(MY_OBJECTS)

all: $(NAME)

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
