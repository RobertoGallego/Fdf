NAME = fdf
CC = gcc

SRC_PATH = ./src/
OBJ_PATH = ./obj/
LIB_PATH = ./lib/
INC_PATH = ./include/ $(LIB_PATH)libft/include/

GCC_FLGS = -Werror -Wextra -Wall -g
GCC_LIBS = -lmlx -framework OpenGL -framework Appkit

SRC_NAME = main.c fdf.c read.c map_draw.c key_hook.c draw_bresenham.c
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L$(LIB_PATH),$(LIB_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_PATH)libft -j
	$(CC) $(GCC_FLGS) $(LIB) -lft $(INC) $(OBJ) $(GCC_LIBS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(GCC_FLGS) $(INC) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C $(LIB_PATH)libft fclean
	rm -fv $(NAME)

re: fclean all