# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: claferna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 18:36:22 by claferna          #+#    #+#              #
#    Updated: 2024/04/10 17:21:09 by claferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --------------------------------
# -------- MAIN VARIABLE  --------
# --------------------------------

NAME	=	fdf.a

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

AR		=	ar -rc

# ---------------------------------
# ---------- LIBRARIES ------------
# ---------------------------------
#
# ............ LIBFT ..............

LIBFT		=	./lib/libft
LIBFT_A		=	$(LIBFT) libft.a

# ......... GET_NEXT_LINE .........

GNL			=	./lib/getnextline
GNL_A		=	$(GNL) getnextline.a

# ........... MINILIBX ............

LBX			=	./lib/minilibx
LBX_A		=	$(LBX) lmx.a

# ---------------------------------
# ---------- SRC & OBJS -----------
# ---------------------------------

SRC			=	main.c	paint.c	process_map.c window_utils.c\

OBJS		=	$(SRC:.c=.o)

# ---------------------------------
# ------------ RULES --------------
# ---------------------------------
all			:	$(NAME)

$(NAME)		:	$(OBJS)
				make - C $(LIBFT) -f Makefile
				cp $(LIBT_A) $(NAME)
				$(AR) $(NAME) $(OBJS)

clean		:	
				$(RM) $(OBJS)
				make -C $(LIBFT) clean

fclean		:	clean
				$(RM) $(NAME)
				make -C $(LIBFT) fclean

re			:	fclean all

.PHONY		:	all fclean re clean
