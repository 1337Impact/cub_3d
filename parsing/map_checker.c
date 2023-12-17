/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:02:57 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/03 16:17:47 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_meta(char c)
{
	if (c == '0' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W' || c == 'D')
		return (1);
	return (0);
}

int	check_sub_lines(char **s)
{
	int	last;
	int	i;

	i = 0;
	while (s[0][i])
		if (is_meta(s[0][i++]))
			return (1);
	i = 0;
	while (s[i])
	{
		last = ft_strlen(s[i]) - 1;
		if (is_meta(s[i][0]) || is_meta(s[i++][last]))
			return (1);
	}
	last = arrlen(s) - 1;
	i = 0;
	while (s[last][i])
		if (is_meta(s[last][i++]))
			return (1);
	return (0);
}

int	check_lines(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i + 1])
	{
		j = 0;
		while (s[i][j])
		{
			if (is_meta(s[i][j]))
			{
				if (s[i - 1][j] == ' ' || s[i - 1][j + 1] == ' '
					|| s[i][j + 1] == ' ' || s[i + 1][j + 1] == ' '
					|| s[i + 1][j] == ' ' || s[i + 1][j - 1] == ' '
					|| s[i][j - 1] == ' ' || s[i - 1][j - 1] == ' '
					|| !s[i - 1][j + 1] || !s[i + 1][j + 1])
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

char	**allocate_map(char **map)
{
	char	**map2;
	int		i;

	map2 = malloc((arrlen(map) + 1) * sizeof(char *));
	if (!map2)
		return (0);
	i = 0;
	while (map[i])
	{
		map2[i] = ft_strdup(map[i]);
		i++;
	}
	map2[i] = 0;
	return (map2);
}

char	**map_checker(char **map, t_data *d, char **file)
{
	if (!(*map))
		return (0);
	if (check_lines(map) || check_sub_lines(map))
	{
		free_arr(file);
		free_data(d);
		print_error(14);
	}
	return (allocate_map(map));
}
