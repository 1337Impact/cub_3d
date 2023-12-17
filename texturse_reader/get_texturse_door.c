/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texturse_door.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:44:38 by aaitoual          #+#    #+#             */
/*   Updated: 2022/08/15 17:26:39 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	get_door_texture1(t_info *info)
{
	int		i;
	int		j;
	int		k;
	t_img	img1;
	int		*buff;

	img1.img = mlx_xpm_file_to_image(info->ml, DOOR_TEXTURE1, &j, &i);
	img1.addr = mlx_get_data_addr(img1.img, &img1.bits_per_pixel,
			&img1.line_length, &img1.endian);
	buff = malloc(4 * i * j);
	k = 0;
	i = -1;
	while (++i < 64)
	{
		j = -1;
		while (++j < 64)
		{
			buff[k] = get_color(img1, j, i);
			k++;
		}
	}
	info->buff_door[0] = buff;
	mlx_destroy_image(info->ml, img1.img);
}

void	get_door_texture2(t_info *info)
{
	int		i;
	int		j;
	int		k;
	t_img	img1;
	int		*buff;

	img1.img = mlx_xpm_file_to_image(info->ml, DOOR_TEXTURE2, &j, &i);
	img1.addr = mlx_get_data_addr(img1.img, &img1.bits_per_pixel,
			&img1.line_length, &img1.endian);
	buff = malloc(4 * i * j);
	k = 0;
	i = -1;
	while (++i < 64)
	{
		j = -1;
		while (++j < 64)
		{
			buff[k] = get_color(img1, j, i);
			k++;
		}
	}
	info->buff_door[1] = buff;
	mlx_destroy_image(info->ml, img1.img);
}

void	get_door_texture3(t_info *info)
{
	int		i;
	int		j;
	int		k;
	t_img	img1;
	int		*buff;

	img1.img = mlx_xpm_file_to_image(info->ml, DOOR_TEXTURE3, &j, &i);
	img1.addr = mlx_get_data_addr(img1.img, &img1.bits_per_pixel,
			&img1.line_length, &img1.endian);
	buff = malloc(4 * i * j);
	k = 0;
	i = -1;
	while (++i < 64)
	{
		j = -1;
		while (++j < 64)
		{
			buff[k] = get_color(img1, j, i);
			k++;
		}
	}
	info->buff_door[2] = buff;
	mlx_destroy_image(info->ml, img1.img);
}

void	get_door_texture4(t_info *info)
{
	int		i;
	int		j;
	int		k;
	t_img	img1;
	int		*buff;

	img1.img = mlx_xpm_file_to_image(info->ml, DOOR_TEXTURE4, &j, &i);
	img1.addr = mlx_get_data_addr(img1.img, &img1.bits_per_pixel,
			&img1.line_length, &img1.endian);
	buff = malloc(4 * i * j);
	k = 0;
	i = -1;
	while (++i < 64)
	{
		j = -1;
		while (++j < 64)
		{
			buff[k] = get_color(img1, j, i);
			k++;
		}
	}
	info->buff_door[3] = buff;
	mlx_destroy_image(info->ml, img1.img);
}
