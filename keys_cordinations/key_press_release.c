/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_release.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 08:13:35 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/03 15:57:53 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	free_2(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free (map[i]);
	free (map);
}

void	ft_exit(t_info *info, int i)
{
	if (i == 1)
	{
		free_2(info->k.map);
		free (info->k.e_path);
		free (info->k.w_path);
		free (info->k.s_path);
		free (info->k.n_path);
		free (info->rays);
		free (info->buff_ea);
		free (info->buff_so);
		free (info->buff_we);
		free (info->buff_no);
		exit (1);
	}
}

void	check_key(t_info *info, int key)
{
	if (key == KEY_W)
		info->up.k_w = 1;
	if (key == KEY_S)
		info->up.k_s = 1;
	if (key == KEY_A)
		info->up.k_a = 1;
	if (key == KEY_D)
		info->up.k_d = 1;
	if (key == KEY_RIGHT)
		info->up.k_right = 1;
	if (key == KEY_LEFT)
		info->up.k_left = 1;
	if (key == EXIT)
		ft_exit(info, 1);
}

int	key_press(int key, t_info *info)
{
	int	x;
	int	y;

	x = floor(info->px / 64);
	y = floor(info->py / 64);
	if (key == KEY_ENT)
	{
		if ((info->k.map[y][x + 1] == 'D'
			|| info->k.map[y][x - 1] == 'D') && !info->animation)
		{
			info->door_statue *= -1;
			info->animation = 4;
		}
	}
	check_key(info, key);
	return (0);
}

int	key_release(int key, t_info *info)
{
	if (key == KEY_W)
		info->up.k_w = 0;
	if (key == KEY_S)
		info->up.k_s = 0;
	if (key == KEY_A)
		info->up.k_a = 0;
	if (key == KEY_D)
		info->up.k_d = 0;
	if (key == KEY_RIGHT)
		info->up.k_right = 0;
	if (key == KEY_LEFT)
		info->up.k_left = 0;
	return (0);
}
