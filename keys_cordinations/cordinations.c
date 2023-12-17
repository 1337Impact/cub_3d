/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cordinations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 07:58:54 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/03 15:54:36 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	player_next_position_1(t_info *info, int *i)
{
	int	x;
	int	y;

	x = round(info->px + (cos(info->pa)) * 5);
	y = round(info->py + (sin(info->pa)) * 5);
	if (check_wall(info, x, y))
	{
		info->px = x;
		info->py = y;
	}
	if (check_door2(info, x, y) && *i == 1)
	{
		if (info->k.map[y / 64][(int)round(info->px
				+ (cos(info->pa)) * (90)) / 64] != 'D')
		{
			info->px = round(info->px + (cos(info->pa)) * (90));
			*i -= 1;
		}
	}
}

void	player_next_position_2(t_info *info, int *i)
{
	int	x;
	int	y;

	x = round(info->px + cos(info->pa) * -5);
	y = round(info->py + sin(info->pa) * -5);
	if (check_wall(info, x, y))
	{
		info->px = x;
		info->py = y;
	}
	if (check_door2(info, x, y) && *i == 1)
	{
		if (info->k.map[y / 64][(int)round(info->px
				+ cos(info->pa) * (-90)) / 64] != 'D')
		{
			info->px = round(info->px + cos(info->pa) * (-90));
			*i -= 1;
		}
	}
}

void	player_next_position_3(t_info *info, int *i)
{
	int	x;
	int	y;

	x = round(info->px + sin(info->pa) * 5);
	y = round(info->py - cos(info->pa) * 5);
	if (check_wall(info, x, y))
	{
		info->px = x;
		info->py = y;
	}
	if (check_door2(info, x, y) && *i == 1)
	{
		if (info->k.map[y / 64][(int)round(info->px
				+ sin(info->pa) * (90)) / 64] != 'D')
		{
			info->px = round(info->px + sin(info->pa) * (90));
			*i -= 1;
		}
	}
}

void	player_next_position_4(t_info *info, int *i)
{
	int	x;
	int	y;

	x = round(info->px - sin(info->pa) * 5);
	y = round(info->py + cos(info->pa) * 5);
	if (check_wall(info, x, y))
	{
		info->px = x;
		info->py = y;
	}
	if (check_door2(info, x, y) && *i == 1)
	{
		if (info->k.map[y / 64][(int)round(info->px
				- sin(info->pa) * (90)) / 64] != 'D')
		{
			info->px = round(info->px - sin(info->pa) * (90));
			*i -= 1;
		}
	}
}

void	update_player_cord(t_info *info)
{
	int	i;

	i = 1;
	if (info->up.k_w)
		player_next_position_1(info, &i);
	if (info->up.k_s)
		player_next_position_2(info, &i);
	if (info->up.k_a)
		player_next_position_3(info, &i);
	if (info->up.k_d)
		player_next_position_4(info, &i);
	if (info->up.k_right)
		info->pa = info->pa + 0.041;
	if (info->up.k_left)
		info->pa = info->pa - 0.041;
}
