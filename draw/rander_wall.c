/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rander_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:22:19 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/03 15:50:52 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_door(t_info *m, int i, int *ix, int x)
{
	int			y;
	static int	k;
	static int	r = 1;
	static int	time;

	x = m->rays[i / 3].w_x / 64;
	y = m->rays[i / 3].w_y / 64;
	if (++time >= 100000)
		time = 1;
	if (k == 3 && m->animation && r == 1 && !(time % 1000))
		r *= -1;
	else if (k == 0 && m->animation && r == -1 && !(time % 1000))
		r *= -1;
	if (m->k.map[y][x] == 'D' && m->rays[i / 3].washitvertical)
	{
		*ix = (int)((m->rays[i / 3].w_y) % WALL_SIZE);
		if (m->animation && !(time % 1000))
			k += r;
		if (((k == 3 && r == 1) || (k == 0 && r == -1)) && !(time % 1000))
			m->animation = 0;
		if (k > 3 || k < 0)
			k += 3 * r;
		return (k);
	}
	return (-1);
}

int	*get_texturse_info(t_info *m, int i, int *ix)
{
	int	tmp;

	tmp = check_door(m, i, ix, 0);
	if (tmp != -1)
	{
		return (m->buff_door[tmp]);
	}
	if (!m->rays[i / 3].washitvertical)
	{
		*ix = (int)((m->rays[i / 3].w_x) % WALL_SIZE);
		if (m->rays[i / 3].rayisdown)
			return (m->buff_so);
		else
			return (m->buff_no);
	}
	else
	{
		*ix = (int)((m->rays[i / 3].w_y) % WALL_SIZE);
		if (m->rays[i / 3].rayisright)
			return (m->buff_ea);
		else
			return (m->buff_we);
	}
}

void	rander_img(t_info *m, int wall_h, int i)
{
	static int	walk;
	int			y;
	static int	k = -2;

	if (walk >= 20 || walk <= -20)
	{
		k *= -1;
		if (walk >= 20)
			walk = 20;
		else
			walk = -20;
		walk += k;
	}
	if (!i)
	{
		if (m->up.k_a || m->up.k_d || m->up.k_s || m->up.k_w)
			walk += k * 3;
		else
			walk += k;
	}
	y = (480 / 2) - (wall_h / 2);
	mlx_put_image_to_window(m->ml, m->window, m->img_tmp.img,
		i, y - (walk / 2));
}

void	put_wall(t_info *m, int wall_h, int i, int y)
{
	char	*dst;
	int		x;
	int		ix;
	int		iy;
	int		*buffer;

	m->img_tmp.img = mlx_new_image(m->ml, 3, wall_h);
	m->img_tmp.addr = mlx_get_data_addr(m->img_tmp.img, &m->img_tmp
			.bits_per_pixel, &m->img_tmp.line_length, &m->img_tmp.endian);
	buffer = get_texturse_info(m, i, &ix);
	while (++y != wall_h)
	{
		iy = y * ((WALL_SIZE / (float)wall_h));
		x = 0;
		while (x != 3)
		{
			dst = m->img_tmp.addr + (y * m->img_tmp.line_length
					+ x * (m->img_tmp.bits_per_pixel / 8));
			*(unsigned int *)dst = buffer[(WALL_SIZE * iy) + ix];
			x++;
		}
	}
	rander_img(m, wall_h, i);
	mlx_destroy_image(m->ml, m->img_tmp.img);
}

void	rander_walls(t_info *info)
{
	int			i;
	float		projection_distance;
	float		wall_height;
	float		dis;

	projection_distance = (WINDOW_W / 2) / tan(60 / 2);
	i = 0;
	while (i < 320)
	{
		if ((int)info->rays[i].distance)
		{
			dis = info->rays[i].distance
				* cos(info->rays[i].rayangle - info->pa);
			wall_height = (WALL_SIZE / dis) * projection_distance;
			put_wall(info, (int)fabs((wall_height * 10)), i * 3, -1);
		}
		i++;
	}
}
