/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:02:41 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/03 16:11:01 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include "./libft/libft.h"

typedef struct s_data
{
	char			*n_path;
	char			*s_path;
	char			*w_path;
	char			*e_path;
	unsigned long	f_hexa;
	unsigned long	c_hexa;
	char			**map;
}	t_data;

char			**read_map(int fd);
t_data			parsing(char *file_name);
void			print_error(int error);
int				is_map(char *str);
void			parse_line(char *line, t_data *d, char **map);
int				arrlen(char **arr);
unsigned long	color_parse(char *str, t_data *d, char **map);
unsigned long	rgb_to_hexa(int r, int g, int b);
char			**map_checker(char **map, t_data *d, char **file);
int				is_meta(char c);
int				check_map_characters(char **map);
void			free_arr(char **arr);
void			free_data(t_data *d);
int				all_set(t_data *d);

#endif
