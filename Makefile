NAME = lem_in

LEM_IN_NAME = anthill.c \
				error_gestion.c \
				find_line_type.c \
				lem_in.c \
				tools.c


INC_PATH = ./includes/
LEM_IN_PATH = ./srcs/
OBJ_LEM_IN_PATH = ./obj_lem_in/
LIB_PATH = ./libft/
LIB_NAME = libft.a
CC = gcc
CFLAGS = -Werror -Wall -Wextra
OBJ_NAME_LEM_IN = $(LEM_IN_NAME:.c=.o)

OBJ_LEM_IN = $(addprefix $(OBJ_LEM_IN_PATH),$(OBJ_NAME_LEM_IN))
LIB = $(addprefix $(LIB_PATH),$(LIB_NAME))
INC = $(addprefix -I,$(INC_PATH))

all:$(NAME)

$(NAME): $(OBJ_LEM_IN) libf
		$(CC) $(CFLAGS) $(OBJ_LEM_IN) $(LIB) $(INC) -o $@

$(OBJ_LEM_IN_PATH)%.o:$(LEM_IN_PATH)%.c
	@mkdir -p $(OBJ_LEM_IN_PATH)
	$(CC) -c $< -o $@

libf:
	make -C $(LIB_PATH)

clean:
	make -C $(LIB_PATH) fclean
	rm -rf $(OBJ_LEM_IN_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all
