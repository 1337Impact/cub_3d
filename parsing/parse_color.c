/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:02:54 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/03 16:17:33 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_atoi2(char *str)
{
	int	i;
	int	out;

	i = 0;
	out = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		out = out * 10 + (str[i] - 48);
		i++;
	}
	if (!str[i] && i >= 1 && i <= 3)
		return (out);
	return (-1);
}

int	count_separator(char *str)
{
	int	i;
	int	sep;

	i = 0;
	sep = 0;
	while (str[i])
	{
		if (str[i] == ',')
			sep++;
		i++;
	}
	return (sep);
}

int	*parse_str_color(char *str)
{
	int		i;
	char	**arr;
	int		*out;

	if (count_separator(str) != 2)
		return (0);
	arr = ft_split(str, ',');
	if (arrlen(arr) != 3)
		return (0);
	i = 0;
	out = malloc(3 * sizeof(int));
	while (arr[i])
	{
		out[i] = ft_atoi2(arr[i]);
		if (out[i] == -1)
			return (0);
		i++;
	}
	free_arr(arr);
	return (out);
}

unsigned long	color_parse(char *str, t_data *d, char **map)
{
	int				*rgb;
	int				i;
	unsigned long	hexa;

	rgb = parse_str_color(str);
	if (!rgb || rgb[0] < 0 || rgb[0] > 255
		|| rgb[1] < 0 || rgb[1] > 255
		|| rgb[2] < 0 || rgb[2] > 255)
	{
		free_arr(map);
		free_data(d);
		print_error(12);
	}
	i = 0;
	hexa = rgb_to_hexa(rgb[0], rgb[1], rgb[2]);
	free(rgb);
	return (hexa);
}
