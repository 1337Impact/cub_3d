/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:02:44 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/03 16:10:12 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_texturse(t_data d)
{
	int	e;
	int	s;
	int	n;
	int	w;

	e = open(d.e_path, F_OK | R_OK);
	s = open(d.s_path, F_OK | R_OK);
	n = open(d.n_path, F_OK | R_OK);
	w = open(d.w_path, F_OK | R_OK);
	close(e);
	close(s);
	close(n);
	close(w);
	if (e == -1 || s == -1
		|| n == -1 || w == -1)
		return (0);
	return (1);
}

void	map_name(char *file)
{
	int	i;

	i = ft_strlen(file) - 4;
	if (ft_strncmp(file + i, ".cub", 4))
		print_error(10);
}

t_data	parsing(char *file_name)
{
	int		fd;
	t_data	d;
	char	**map;
	int		i;

	map_name(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		print_error(errno);
	}
	map = read_map(fd);
	i = 0;
	while (map[i][0] != ' ' && map[i][0] != '1')
		parse_line(map[i++], &d, map);
	d.map = map_checker(map + i, &d, map);
	free_arr(map);
	all_set(&d);
	close(fd);
	if (!check_texturse(d))
	{
		free_data(&d);
		print_error(15);
	}
	return (d);
}
