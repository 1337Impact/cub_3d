/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texturse_buff.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 08:47:24 by aaitoual          #+#    #+#             */
/*   Updated: 2022/10/30 18:27:06 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

unsigned int	get_color(t_img img, int y, int x)
{
	char	*ptr;
	int		pixel;

	pixel = x * img.line_length + y * 4;
	ptr = img.addr + pixel;
	return (*(unsigned int *) ptr);
}

void	get_door(t_info *info)
{
	get_door_texture1(info);
	get_door_texture2(info);
	get_door_texture3(info);
	get_door_texture4(info);
}

void	get_texture_buff(t_info *info)
{
	int		i;
	int		j;
	int		k;
	t_img	img1;

	img1.img = mlx_xpm_file_to_image(info->ml, info->k.e_path, &j, &i);
	img1.addr = mlx_get_data_addr(img1.img, &img1.bits_per_pixel,
			&img1.line_length, &img1.endian);
	info->buff_ea = malloc(4 * i * j);
	k = 0;
	i = -1;
	while (++i < 64)
	{
		j = -1;
		while (++j < 64)
		{
			info->buff_ea[k] = get_color(img1, j, i);
			k++;
		}
	}
	mlx_destroy_image(info->ml, img1.img);
	get_no_texture(info);
	get_we_texture(info);
	get_so_texture(info);
	get_door(info);
}
