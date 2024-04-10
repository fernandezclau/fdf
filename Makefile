# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: claferna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 18:36:22 by claferna          #+#    #+#              #
#    Updated: 2024/04/10 19:09:32 by claferna         ###   ########.fr        #
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
LBX_FLAGS	=	-framework OpenGL -framework AppKit

# ---------------------------------
# --------- DIRECTORIES -----------

SRCDIR		=	src

OBJDIR		=	obj

# ---------------------------------
# ---------- SRC & OBJS -----------
# ---------------------------------

SRC			=	src/main.c src/paint.c src/process_map.c src/window_utils.c

OBJS		=	$(SRC:.c=.o)

# ---------------------------------
# ------------ RULES --------------
# ---------------------------------
all			:	$(NAME)

$(NAME)		:	$(OBJS)
				make -C $(GNL) -f Makefile
				make -C $(LIBFT) -f Makefile
				make -C $(LBX) -f Makefile
				$(CC) $(CFLAGS) src/main.c -o mi_programa -L$(LBX) -lmlx $(LBX_FLAGS)
				$(AR) $(NAME) $(OBJS)

clean		:	
				$(RM) $(OBJS) 
				$(RM) mi_programa
				make -C $(GNL) clean
				make -C $(LIBFT) clean
				make -C $(LBX) clean

fclean		:	clean
				$(RM) $(NAME)
				make -C $(GNL) fclean
				make -C $(LIBFT) fclean

re			:	fclean all

.PHONY		:	all fclean re clean
