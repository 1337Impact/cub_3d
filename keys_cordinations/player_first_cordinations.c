/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_first_cordinations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 08:13:38 by aaitoual          #+#    #+#             */
/*   Updated: 2022/08/20 21:57:53 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	get_player_position(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (info->k.map[++i])
	{
		j = -1;
		while (info->k.map[i][++j])
		{
			if (info->k.map[i][j] == 'N' || info->k.map[i][j] == 'S'
				|| info->k.map[i][j] == 'W' || info->k.map[i][j] == 'E')
			{
				info->px = j * WALL_SIZE + 32;
				info->py = i * WALL_SIZE + 32;
				return ;
			}
		}
	}
}
