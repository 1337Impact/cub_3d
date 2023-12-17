/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texturse_buff_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 09:07:18 by aaitoual          #+#    #+#             */
/*   Updated: 2022/10/30 18:17:27 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	get_no_texture(t_info *info)
{
	int		i;
	int		j;
	int		k;
	t_img	img1;
	int		*buff;

	img1.img = mlx_xpm_file_to_image(info->ml, info->k.n_path, &j, &i);
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
	info->buff_no = buff;
	mlx_destroy_image(info->ml, img1.img);
}

void	get_we_texture(t_info *info)
{
	int		i;
	int		j;
	int		k;
	t_img	img1;
	int		*buff;

	img1.img = mlx_xpm_file_to_image(info->ml, info->k.w_path, &j, &i);
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
	info->buff_we = buff;
	mlx_destroy_image(info->ml, img1.img);
}

void	get_so_texture(t_info *info)
{
	int		i;
	int		j;
	int		k;
	t_img	img1;
	int		*buff;

	img1.img = mlx_xpm_file_to_image(info->ml, info->k.s_path, &j, &i);
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
	info->buff_so = buff;
	mlx_destroy_image(info->ml, img1.img);
}
