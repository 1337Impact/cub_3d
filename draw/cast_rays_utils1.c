/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:24:44 by aaitoual          #+#    #+#             */
/*   Updated: 2022/08/15 15:33:32 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	is_wall(t_info *m, int x, int y, char identf)
{
	int	grid_x;
	int	grid_y;

	grid_x = (int)floor(x / WALL_SIZE);
	grid_y = (int)floor(y / WALL_SIZE);
	if (is_end_window(m, x, y))
	{
		return (TRUE);
	}
	if (m->k.map[grid_y][grid_x] == identf)
	{
		return (TRUE);
	}
	return (FALSE);
}

void	get_directions(t_info *m, float rayangel, int i)
{
	m->rays[i].rayisdown = 0;
	m->rays[i].rayisright = 0;
	if (rayangel > 0 && rayangel < PI)
		m->rays[i].rayisdown = 1;
	m->rays[i].rayisup = !m->rays[i].rayisdown;
	if (rayangel < 0.5 * PI || rayangel > 1.5 * PI)
	m->rays[i].rayisright = 1;
	m->rays[i].rayisleft = !m->rays[i].rayisright;
}

void	get_vertical_inter(t_info *m, int i,
	float *yintercept, float *xintercept)
{
	*xintercept = floor(m->px / WALL_SIZE) * WALL_SIZE;
	if (m->rays[i].rayisright)
		*xintercept += WALL_SIZE;
	*yintercept = m->py + (*xintercept - m->px) * tan(m->rays[i].rayangle);
}

double	check_vertical(t_info *m, int i, float rayangel, float ystep)
{
	float	xstep;
	float	vx_chk;
	float	vy_chk;

	get_vertical_inter(m, i, &vy_chk, &vx_chk);
	xstep = WALL_SIZE;
	if (m->rays[i].rayisleft)
		xstep *= -1;
	ystep = WALL_SIZE * tan(rayangel);
	if (m->rays[i].rayisup && ystep > 0)
		ystep *= -1;
	if (m->rays[i].rayisdown && ystep < 0)
		ystep *= -1;
	if (m->rays[i].rayisleft)
		vx_chk--;
	while (!is_wall(m, vx_chk, vy_chk, '1') && !is_wall(m, vx_chk, vy_chk, 'D'))
	{
		vx_chk += xstep;
		vy_chk += ystep;
	}
	m->cast.vx = vx_chk;
	m->cast.vy = vy_chk;
	return (distancebetwenpoint(m->px, m->py, vx_chk, vy_chk));
}
