SRCS	=	app/cub3d.c							\
			game_funcs/file_name_control.c		\
			game_funcs/free_game.c				\
			game_funcs/ft_get_read.c			\
			game_funcs/ft_split.c				\
			game_funcs/game_data_creats.c		\
			game_funcs/map_check.c				\
			game_funcs/map_find_and_clone.c		\
			game_funcs/textures_and_colors.c	\
			game_funcs/map_check_continue.c		\
			game_funcs/player.c					\
			game_funcs/get_images.c				\
			game_funcs/start.c					\
			game_funcs/ft_atoi.c				\
			game_funcs/create_map.c				\
			game_funcs/raycasting.c				\
			game_funcs/ray_utils.c				\

OBJS	=	$(SRCS:.c=.o)
CFLAGS	=	-Wall -Wextra -Werror #-g -fsanitize=address
NAME	=	cub3d
MINI	=	mlx/libmlx.a
MLXFLAG =  -L./mlx -lmlx -lX11 -lXext -lXrandr -lXi -lm -lGL

all: $(NAME)

$(MINI):
	make -C mlx/

$(NAME): $(OBJS) $(MINI)
	gcc $(CFLAGS) $(OBJS) -o $(NAME) $(MLXFLAG)

clean:
	rm -rf $(OBJS)
#	make clean -C mlx/

fclean: clean
	rm -rf $(NAME)
#	make clean -C mlx/

re: fclean $(NAME)

.PHONY: all clean fclean re