/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:02:51 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/03 16:14:53 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_map(char *str)
{
	int	len;

	if (!str)
		return (1);
	len = ft_strlen(str);
	while (*str == '1' || *str == ' ')
		str++;
	if (!(*str) && len)
		return (1);
	return (0);
}

char	*rm_spaces(char *str, int n)
{
	char	*out;

	out = ft_strdup(str + n);
	return (out);
}

void	parse_line(char *line, t_data *d, char **map)
{
	if (!strncmp(line, "NO ", 3) && !d->n_path)
		d->n_path = rm_spaces(line, 3);
	else if (!strncmp(line, "SO ", 3) && !d->s_path)
		d->s_path = rm_spaces(line, 3);
	else if (!strncmp(line, "WE ", 3) && !d->w_path)
		d->w_path = rm_spaces(line, 3);
	else if (!strncmp(line, "EA ", 3) && !d->e_path)
		d->e_path = rm_spaces(line, 3);
	else if (!strncmp(line, "F ", 2) && !d->f_hexa)
		d->f_hexa = color_parse(line + 2, d, map);
	else if (!strncmp(line, "C ", 2) && !d->c_hexa)
		d->c_hexa = color_parse(line + 2, d, map);
	else if (line[0] != 0)
	{
		free_arr(map);
		free_data(d);
		print_error(11);
	}
}
