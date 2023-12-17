/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:46:17 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/03 16:10:38 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./parsing/parsing.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>

# define DOOR_TEXTURE1 "./texturse/door1.xpm"
# define DOOR_TEXTURE2 "./texturse/door2.xpm"
# define DOOR_TEXTURE3 "./texturse/door3.xpm"
# define DOOR_TEXTURE4 "./texturse/door4.xpm"
# define WINDOW_H 480
# define WINDOW_W 852
# define KEY_ENT 36
# define EXIT 53
# define KEY_A 0
# define KEY_M 46
# define KEY_D 2
# define KEY_W 13
# define KEY_S 1
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define PI 3.141592653589793238
# define FOV 1.04
# define TRUE 1
# define FALSE 0
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define WALL_SIZE 64

typedef struct s_calculations
{
	int		rayisup;
	int		rayisdown;
	int		rayisleft;
	int		rayisright;
	int		w_x;
	int		w_y;
	float	rayangle;
	int		washitvertical;
	float	distance;
}	t_calculations;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
	char	*add;
	int		bpp;
	int		ll;
	t_img	img;
}			t_win;

typedef struct s_update
{
	int	k_d;
	int	k_a;
	int	k_s;
	int	k_w;
	int	k_left;
	int	k_right;
}	t_update;

typedef struct s_cast
{
	int	vx;
	int	vy;
	int	hx;
	int	hy;
}	t_cast;

typedef struct s_info
{
	int				door_statue;
	int				animation;
	t_data			k;
	int				window_h;
	int				window_w;
	int				map_h;
	int				map_w;
	t_calculations	*rays;
	t_cast			cast;
	t_update		up;
	float			pa;
	float			px;
	float			py;
	t_img			hand;
	t_img			mini_map;
	t_img			img_u;
	t_img			img_tmp;
	t_img			img_d;
	t_img			img1;
	void			*ml;
	void			*window;
	void			*window2;
	int				**buff_door;
	int				*buff_no;
	int				*buff_so;
	int				*buff_we;
	int				*buff_ea;
}			t_info;

int				check_door2(t_info *info, int x, int y);
void			get_door_texture1(t_info *info);
void			get_door_texture2(t_info *info);
void			get_door_texture3(t_info *info);
void			get_door_texture4(t_info *info);
int				mouse_move(int x, int y, t_info *param);
int				check_wall(t_info *info, int x, int y);
void			rays(t_info *m);
int				is_wall(t_info *m, int x, int y, char identf);
void			get_directions(t_info *m, float rayangel, int i);
void			get_vertical_inter(t_info *m, int i, float
					*yintercept, float *xintercept);
double			check_vertical(t_info *m, int i, float rayangel, float ystep);
int				is_end_window(t_info *m, double x, double y);
float			normaliseangle(float angle);
float			distancebetwenpoint(float x1, float y1, float x2, float y2);
void			rander_walls(t_info *info);
void			creat_imgs(t_info *info);
int				get_x(t_info *info);
int				get_y(t_info *info);
void			creat_mini_map(t_info *info);
int				draw(void *stru);
void			get_texture_buff(t_info *info);
void			get_no_texture(t_info *info);
void			get_we_texture(t_info *info);
void			get_so_texture(t_info *info);
unsigned int	get_color(t_img img, int x, int y);
void			get_player_position(t_info *info);
int				key_release(int key, t_info *info);
int				key_press(int key, t_info *info);
void			update_player_cord(t_info *info);
void			update_player_cord(t_info *info);
void			ft_exit(t_info *info, int i);
int				mouse_move(int x, int y, t_info *info);

#endif