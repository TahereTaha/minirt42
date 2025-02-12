# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 09:52:48 by tatahere          #+#    #+#              #
#    Updated: 2025/02/12 15:53:46 by tatahere         ###   ########.fr        #
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

NAME	=	miniRT

#	program core.

OBJ		:=	main.o			\

#	here gose all the files

#	gnl
OBJ_GNL	:=	gnl.o			\
			gnl_utils.o		\

OBJ		+=	$(OBJ_GNL)

#	error managment

OBJ_ERROR_MANAGMENT	:=	error_clear.o				\
						error_change_msg.o			\
						error_get_sys_error.o		\
						error_is_sys_error.o		\
						error_append_to_error_msg.o	\
						error_manage_error.o		\

OBJ		+=	$(OBJ_ERROR_MANAGMENT)

#	vector math
OBJ_VECTOR_MATH	:=	vec_debug_print.o			\
					vec_is_null.o				\
					vec_get_magnitude.o			\
					vec_addition.o				\
					vec_substraction.o			\
					vec_scaling.o				\
					vec_normalization.o			\
					vec_linear_combination.o	\

#					vec2_get_angle.o		\
					vec3_get_angle.o		\
					vec2_create.o			\

OBJ		+=	$(OBJ_VECTOR_MATH)

OBJ		:=	$(addprefix $(BIN_DIR), $(OBJ))

DEP		:=	$(OBJ:.o=.d)

#	path to all places where there is 

VPATH	=	$(ROOT_DIR):
VPATH	+=	$(SRC_DIR):
VPATH	+=	$(SRC_DIR)/error_managment:
VPATH	+=	$(SRC_DIR)utils/gnl:
VPATH	+=	$(SRC_DIR)utils/vector_math:

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
