/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_imgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:33:48 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/03 15:52:00 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	my_mlx_pixel_put_utils(t_img *data, int i, int color)
{
	char	*dst;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (i == 2)
	{
		while (y != 4)
		{
			x = 0;
			while (x != 4)
			{
				dst = data->addr
					+ (y * data->line_length + x * (data->bits_per_pixel / 8));
				x++;
				*(unsigned int *) dst = color;
			}
			y++;
		}
	}
}

void	my_mlx_pixel_put(t_img *data, int i, int color)
{
	char	*dst;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (i == 1)
	{
		while (y != 240)
		{
			x = 0;
			while (x != 852)
			{
				dst = data->addr
					+ (y * data->line_length + x * (data->bits_per_pixel / 8));
				*(unsigned int *) dst = color;
				x++;
			}
			y++;
		}
	}
	my_mlx_pixel_put_utils(data, i, color);
}

void	creat_imgs(t_info *info)
{
	int	i;
	int	j;

	creat_mini_map(info);
	info->hand.img = mlx_xpm_file_to_image(info->ml,
			"./texturse/hand.xpm", &i, &j);
	info->img_u.img = mlx_new_image(info->ml, WINDOW_W, WINDOW_H / 2);
	info->img_d.img = mlx_new_image(info->ml, WINDOW_W, WINDOW_H / 2);
	info->img1.img = mlx_new_image(info->ml, 4, 4);
	info->img_d.addr = mlx_get_data_addr(
			info->img_d.img, &info->img_d.bits_per_pixel,
			&info->img_d.line_length, &info->img_d.endian);
	info->img_u.addr = mlx_get_data_addr(
			info->img_u.img, &info->img_u.bits_per_pixel,
			&info->img_u.line_length, &info->img_u.endian);
	info->img1.addr = mlx_get_data_addr(
			info->img1.img, &info->img1.bits_per_pixel,
			&info->img1.line_length, &info->img1.endian);
	my_mlx_pixel_put(&info->img_d, 1, info->k.f_hexa);
	my_mlx_pixel_put(&info->img_u, 1, info->k.c_hexa);
	my_mlx_pixel_put(&info->img1, 2, 0x000FF00);
}
