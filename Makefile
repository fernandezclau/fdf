# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: claferna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 18:36:22 by claferna          #+#    #+#              #
#    Updated: 2024/04/16 19:26:12 by claferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --------------------------------
# -------- MAIN VARIABLE  --------
# --------------------------------

NAME	=	fdf.a

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address

RM		=	rm -f

AR		=	ar -rc

# ---------------------------------
# ---------- LIBRARIES ------------
# ---------------------------------
#
# ............ LIBFT ..............

LIBFT		=	./lib/libft
LIBFT_A		=	$(LIBFT)/libft.a

# ......... GET_NEXT_LINE .........

GNL			=	./lib/getnextline
GNL_A		=	$(GNL)/getnextline.a

# ........... PRINTF .............
PRT			= 	./lib/printf
PRT_A		=	$(PRT)/libftprintf.a
# ........... MINILIBX ............

LBX			=	./lib/minilibx
LBX_A		=	$(LBX) libmlx.a
LBX_FLAGS	=	-framework OpenGL -framework AppKit

# ---------------------------------
# --------- DIRECTORIES -----------

SRCDIR		=	src

OBJDIR		=	obj

# ---------------------------------
# ---------- SRC & OBJS -----------
# ---------------------------------

SRC		=	src/main.c src/matrix.c src/render.c src/t_coords.c\
			src/utils.c src/window_utils.c

OBJS		=	$(SRC:.c=.o)

# ---------------------------------
# ------------ RULES --------------
# ---------------------------------

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				make -C $(GNL) -f Makefile
				make -C $(LIBFT) -f Makefile
				make -C $(PRT) -f Makefile
				make -C $(LBX) -f Makefile
			#	$(CC) $(CFLAGS) src/main.c -o fdf -L$(LBX) -lmlx $(LBX_FLAGS) $(GNL_A) $(LIBT_A) $(PRT_A)
				$(AR) $(NAME) $(OBJS)

clean		:	
				$(RM) $(OBJS) 
				$(RM) mi_programa
				make -C $(GNL) clean
				make -C $(LIBFT) clean
				make -C $(PRT) clean
				make -C $(LBX) clean

fclean		:	clean
				$(RM) $(NAME)
				make -C $(GNL) fclean
				make -C $(LIBFT) fclean
				make -C $(PRT) fclean

re			:	fclean all

.PHONY		:	all fclean re clean
