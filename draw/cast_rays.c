/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:23:47 by aaitoual          #+#    #+#             */
/*   Updated: 2022/11/02 22:41:28 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	get_horizontal_inter(t_info *m, int i,
	float *yintercept, float *xintercept)
{
	*yintercept = floor(m->py / WALL_SIZE) * WALL_SIZE;
	if (m->rays[i].rayisdown)
		*yintercept += WALL_SIZE;
	else
		(*yintercept)--;
	*xintercept = m->px + (*yintercept - m->py) / tan(m->rays[i].rayangle);
}

double	check_horizontale(t_info *m, int i, float rayangel, float ystep)
{
	float	xstep;
	float	x_chk;
	float	y_chk;

	get_horizontal_inter(m, i, &y_chk, &x_chk);
	ystep = WALL_SIZE;
	if (m->rays[i].rayisup)
		ystep *= -1;
	xstep = WALL_SIZE / tan(rayangel);
	if (m->rays[i].rayisleft && xstep > 0)
		xstep *= -1;
	if (m->rays[i].rayisright && xstep < 0)
		xstep *= -1;
	while (!is_wall(m, x_chk, y_chk, '1') && !is_wall(m, x_chk, y_chk, 'D'))
	{
		x_chk += xstep;
		y_chk += ystep;
	}
	m->cast.hx = x_chk;
	m->cast.hy = y_chk;
	return (distancebetwenpoint(m->px, m->py, x_chk, y_chk));
}

void	cast_ray(float rayangel, int i, t_info *m)
{
	double	horz_dist;
	double	vert_dist;

	rayangel = normaliseangle(rayangel);
	m->rays[i].rayangle = rayangel;
	get_directions(m, rayangel, i);
	horz_dist = check_horizontale(m, i, rayangel, 0);
	vert_dist = check_vertical(m, i, rayangel, 0);
	if (horz_dist <= vert_dist)
	{
		m->rays[i].w_x = m->cast.hx;
		m->rays[i].w_y = m->cast.hy;
		m->rays[i].distance = horz_dist;
	}
	else
	{
		m->rays[i].w_x = m->cast.vx;
		m->rays[i].w_y = m->cast.vy;
		m->rays[i].distance = vert_dist;
	}
	m->rays[i].washitvertical = (vert_dist < horz_dist);
}

void	rays(t_info *m)
{
	float	ra;
	int		i;

	ra = m->pa - (FOV / 2);
	i = 0;
	while (i < 320)
	{
		cast_ray(ra, i, m);
		i++;
		ra += FOV / 320;
	}
}
