# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: claferna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 17:56:39 by claferna          #+#    #+#              #
#    Updated: 2024/04/10 18:11:23 by claferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --------------------------------
# -------- MAIN VARIABLE  --------
# --------------------------------

NAME	=	getnextline.a

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

AR		=	ar -rcs

# ---------------------------------
# ---------- SRC & OBJS -----------
# ---------------------------------

SRC			=	get_next_line.c	get_next_line_utils.c\

OBJS		=	$(SRC:.c=.o)

# ---------------------------------
# ------------ RULES --------------
# ---------------------------------
all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(AR) $(NAME) $(OBJS)

.c.o		:
				cc $(CFLAGS) -c $< -o $(<:.c=.o)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all fclean re clean
