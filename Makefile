# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 09:52:48 by tatahere          #+#    #+#              #
#    Updated: 2025/02/10 16:39:47 by tatahere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	some directories

ROOT_DIR		=	./

BIN_DIR			=	$(ROOT_DIR)bin/
SRC_DIR			=	$(ROOT_DIR)src/
INC_DIR			=	$(ROOT_DIR)inc/
LIB_DIR			=	$(ROOT_DIR)libs/

#	libraries directories

LIBFT_DIR		=	$(LIB_DIR)libft/
LIBFT_HDR_DIR	=	$(LIBFT_DIR)inc/
LIBFT_NAME		=	libft.a
LIBFT			=	$(LIBFT_DIR)$(LIBFT_NAME)

LIBMLX_DIR		=	$(LIB_DIR)MLX42/
LIBMLX_HDR_DIR	=	$(LIBMLX_DIR)include/
LIBMLX_NAME		=	libmlx42.a
LIBMLX			=	$(LIBMLX_DIR)build/$(LIBMLX_NAME)

LIBS		=	$(LIBFT) $(LIBMLX)

#	some flags

CFLAGS			:=	-Wall -Wextra -Werror -MMD

CINC		:=	-I$(ROOT_DIR)
CINC		+=	-I$(INC_DIR)
CINC		+=	-I$(LIBMLX_HDR_DIR)
CINC		+=	-I$(LIBFT_HDR_DIR)
CFLAGS		+=	$(CINC)

CDEBUG		:=	-g -fsanitize=address
CFLAGS		+=	$(CDEBUG)

CFLAGSMLX	=	-ldl -lglfw -pthread -lm

#	some usfull variables

RM		=	rm -rf
CC		=	cc

NAME	=	test

#	program core.

OBJ		:=	main.o			\

OBJ		:=	$(addprefix $(BIN_DIR), $(OBJ))

DEP		:=	$(OBJ:.o=.d)

VPATH	=	$(ROOT_DIR):
VPATH	+=	$(SRC_DIR)

all	:	libs $(BIN_DIR) $(NAME)

libs:
	git submodule init
	git submodule update
	cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build && make -C $(LIBMLX_DIR)/build -j4
	make -C $(LIBFT_DIR) all

$(BIN_DIR)		:
	mkdir $(BIN_DIR)

$(NAME) : $(OBJ) Makefile
	$(CC) $(CFLAGS) $(CFLAGSMLX) $(OBJ) $(LIBS) -o $(NAME)

$(BIN_DIR)%.o : %.c	Makefile 
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(BIN_DIR)
	make -C $(LIBFT_DIR) clean
	rm -rf $(LIBMLX_DIR)/build

fclean : clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all

-include $(DEP)

.PHONY:	all clean fclean re libs
