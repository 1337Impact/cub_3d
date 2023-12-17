/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cordinations_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:40:58 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/03 15:58:10 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	mouse_move(int x, int y, t_info *info)
{
	if (x > 0 && x < 852)
		info->pa = info->pa + (((x - 462) / 200) * PI / 180.0);
	y = 0;
	return (0);
}

int	check_wall(t_info *info, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (info->k.map[++i])
	{
		j = -1;
		while (info->k.map[i][++j])
		{
			if (info->k.map[i][j] == '1' || info->k.map[i][j] == 'D')
			{
				if ((x >= (j * 64) - 10 && x <= ((j + 1) * 64) + 10)
					&& (y >= (i * 64) - 10 && y <= ((i + 1) * 64) + 10))
					return (0);
			}
		}
	}
	return (1);
}

int	check_door2(t_info *info, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (info->k.map[++i])
	{
		j = -1;
		while (info->k.map[i][++j])
		{
			if (info->k.map[i][j] == 'D' && info->door_statue == 1
					&& info->k.map[i][j + 1] != '1'
					&& info->k.map[i][j - 1] != '1')
			{
				if ((x >= (j * 64) - 10 && x <= ((j + 1) * 64) + 10)
					&& (y >= (i * 64) - 10 && y <= ((i + 1) * 64) + 10))
					return (1);
			}
		}
	}
	return (0);
}
