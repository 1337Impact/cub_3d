NAME = cub3d

HEADER = cub3D.h ./parsing/parsing.h

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT = ./libft/libft.a

CFLAGS = -Wall -Wextra -Werror -Imlx

SRC = cub3D.c ./keys_cordinations/cordinations.c ./keys_cordinations/key_press_release.c ./keys_cordinations/player_first_cordinations.c \
		./texturse_reader/get_texturse_buff.c ./texturse_reader/get_texturse_buff_utils.c \
		./draw/draw.c ./minimap/minimap.c ./imgs/creat_imgs.c ./draw/cast_rays.c ./draw/rander_wall.c ./draw/cast_rays_utils1.c ./draw/cast_rays_utils2.c \
		./keys_cordinations/cordinations_utils.c ./parsing/parsing.c ./parsing/read_map.c ./parsing/parsing_utils.c ./parsing/parse_line.c ./parsing/parse_color.c \
		./parsing/map_checker.c ./parsing/map_checker_utils.c ./texturse_reader/get_texturse_door.c \

OBJ = $(SRC:.c=.o)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(LIBFT) $(NAME) $(HEADER)

$(NAME) : $(OBJ)
	@$(CC) $(OBJ) $(CFLAGS) $(MLXFLAGS)  -o $(NAME) -lft -L./parsing/libft
	@echo "\033[0;31m" "  ***********************************"
	@echo "\033[0;31m" " /     Cub3d has been created       /"
	@echo "\033[0;31m" "************************************"

$(LIBFT) :
	@$(MAKE) -C ./parsing/libft

bonus : all

clean :
	@$(MAKE) clean -C ./parsing/libft
	@rm -rf $(OBJ)

fclean : clean
	@$(MAKE) fclean -C ./parsing/libft
	@rm -rf $(NAME)

re : fclean all