/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:03:02 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/03 16:17:57 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_map_characters(char **map)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				p++;
			else if (!is_meta(map[i][j])
				&& map[i][j] != '1' && map[i][j] != ' ')
				return (1);
			j++;
		}
		i++;
	}
	if (p != 1)
		return (1);
	return (0);
}

int	check_empty_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		if (!map[i++][0])
			return (1);
	return (0);
}

int	all_set(t_data *d)
{
	if (!d->n_path || !d->s_path || !d->w_path
		|| !d->e_path || !d->c_hexa || !d->f_hexa
		|| !d->map)
	{
		free_data(d);
		print_error(14);
	}
	if (check_map_characters(d->map) || check_empty_lines(d->map))
	{
		free_data(d);
		print_error(14);
	}
	return (0);
}
