/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:20:53 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/02 20:42:06 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	get_x(t_info *info)
{
	int	x;

	x = (120) - (int)floor((info->px / 64) * 17);
	return (x);
}

int	get_y(t_info *info)
{
	int	y;

	y = 120 - (int)floor((info->py / 64) * 17);
	return (y);
}

int	get_color_map(t_info *info, int i, int j)
{
	if (info->k.map[(int)floor(i / 17)][(int)floor(j / 17)] == '0'
		|| info->k.map[(int)floor(i / 17)][(int)floor(j / 17)] == 'N'
		|| info->k.map[(int)floor(i / 17)][(int)floor(j / 17)] == 'S'
		|| info->k.map[(int)floor(i / 17)][(int)floor(j / 17)] == 'E'
		|| info->k.map[(int)floor(i / 17)][(int)floor(j / 17)] == 'W')
		return (0x0FFFFFF);
	if (info->k.map[(int)floor(i / 17)][(int)floor(j / 17)] == '1')
		return (0x0FF00FF);
	if (info->k.map[(int)floor(i / 17)][(int)floor(j / 17)] == 'D')
		return (0x0008080);
	return (0x0FF00FF);
}

void	draw_mini(t_info *info)
{
	int			i;
	int			j;
	char		*dst;
	int			color;

	i = 119;
	while (++i - 120 < info->map_h * 17)
	{
		j = 119;
		while (j++ - 120 < info->map_w * 17)
		{
			dst = info->mini_map.addr + (i * info->mini_map.line_length
					+ j * (info->mini_map.bits_per_pixel / 8));
			color = get_color_map(info, i - 120, j - 120);
					*(unsigned int *) dst = color;
		}
	}	
}

void	creat_mini_map(t_info *info)
{
	int			i;
	int			j;
	char		*dst;

	i = -1;
	info->mini_map.img = mlx_new_image(
			info->ml, (info->map_w * 17) + 240, (info->map_w * 17) + 240);
	info->mini_map.addr = mlx_get_data_addr(
			info->mini_map.img, &info->mini_map.bits_per_pixel,
			&info->mini_map.line_length, &info->mini_map.endian);
	while (++i < (info->map_h * 17) + 240)
	{
		j = -1;
		while (j++ < (info->map_w * 17) + 240)
		{
			if (i > 120 && i < (info->map_h * 17) + 120 && j == 120)
				j = (info->map_w * 17) + 119;
			dst = info->mini_map.addr + (i * info->mini_map.line_length
					+ j * (info->mini_map.bits_per_pixel / 8));
			*(unsigned int *) dst = 0x0FF00FF;
		}
	}
	draw_mini(info);
}
