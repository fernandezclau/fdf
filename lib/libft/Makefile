# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: claferna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 18:31:20 by claferna          #+#    #+#              #
#    Updated: 2024/04/23 18:49:53 by claferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CFLAGS		=	-Wall -Wextra -Werror

LIB			=	ar -rcs

RM			=	rm -f

SRCS 		= ft_atoi.c ft_isdigit.c ft_memset.c ft_strlcpy.c ft_tolower.c\
	   		ft_bzero.c ft_isprint.c ft_strchr.c ft_strlen.c ft_toupper.c\
	   		ft_calloc.c ft_memchr.c ft_strncmp.c ft_isalnum.c\
	   		ft_memcmp.c ft_strnstr.c ft_isalpha.c ft_memcpy.c\
	   		ft_strrchr.c ft_isascii.c ft_memmove.c ft_strlcat.c\
	   		ft_substr.c ft_strdup.c ft_strjoin.c	ft_strtrim.c\
	   		ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
	   		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS		=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(LIB) $(NAME) $(OBJS)

.c.o	:
			cc $(CFLAGS) -c $< -o $(<:.c=.o)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
				$(RM) $(NAME)

.PHONY	: 	all clean fclean re

re		:	fclean all

