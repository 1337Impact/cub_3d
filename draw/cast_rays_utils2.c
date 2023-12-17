/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:25:21 by aaitoual          #+#    #+#             */
/*   Updated: 2022/07/29 16:34:46 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	is_end_window(t_info *m, double x, double y)
{
	if (x < 0 || x >= (WALL_SIZE * WALL_SIZE)
		|| y < 0 || y >= m->map_h * WALL_SIZE)
		return (TRUE);
	return (FALSE);
}

float	normaliseangle(float angle)
{
	angle = remainder(angle, (2 * PI));
	if (angle < 0)
	{
		angle = (2 * PI) + angle;
	}
	return (angle);
}

float	distancebetwenpoint(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
