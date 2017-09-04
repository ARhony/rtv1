# Makefile by Anthony

NAME 	= rtv1

SRC 	= main.c \
		  init.c \
		  list.c \
		  colors.c \
		  calcul.c \
		  draw.c \
		  inter_obj.c \
		  light.c \
		  rotate.c \
		  shadow.c \
		  key.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -O3

LIBFT 	= ./libft/libft.a
LIBINC 	= -I./libft
LIBLINK = -L./libft -lft

MLX		= ./minilibx/libmlx.a
MLXINC	= -I./minilibx
MLXLINK = -L./minilibx -lmlx -framework OpenGL -framework AppKit

INCDIR	= ./include/
SRCDIR	= ./src/
OBJDIR	= ./obj/

all: obj $(LIBFT) $(MLX) $(NAME)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(LIBINC) $(MLXINC) -I $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(MLXLINK) $(LIBLINK)

$(LIBFT):
	make -C ./libft

$(MLX):
	make -C ./minilibx

obj:
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)
	make -C ./libft clean
	make -C ./minilibx clean

fclean: clean
	rm -rf $(NAME)

re: fclean all
