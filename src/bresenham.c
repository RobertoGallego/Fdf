/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:35:21 by groberto          #+#    #+#             */
/*   Updated: 2019/02/06 16:53:44 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		vertical(t_config *fdf, int *x, int *y, int *xy)
{
	int		i;
	int		e;

	i = 0;
	e = y[0] / 2;
	while (i < y[0])
	{
		xy[1] += y[1];
		e += x[0];
		if (e >= y[0])
		{
			e -= y[0];
			xy[0] += x[1];
		}
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, xy[0], xy[1], 0xFFFFFF);
		i++;
	}
}

void		horizontal(t_config *fdf, int *x, int *y, int *xy)
{
	int		i;
	int		e;

	i = 0;
	e = x[0] / 2;
	while (i < x[0])
	{
		xy[0] += x[1];
		e += y[0];
		if (e >= x[0])
		{
			e -= x[0];
			xy[1] += y[1];
		}
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, xy[0], xy[1], 0xFFFFFF);
		i++;
	}
}

void		bresenham(t_config *fdf, int *tabxy, int x2, int y2)
{
	int		xy[2];
	int		x[2];
	int		y[2];

	xy[0] = tabxy[0];
	xy[1] = tabxy[1];
	x[0] = ft_abs(x2 - xy[0]);
	y[0] = ft_abs(y2 - xy[1]);
	x[1] = xy[0] < x2 ? 1 : -1;
	y[1] = xy[1] < y2 ? 1 : -1;
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, xy[0], xy[1], 0xFFFFFF);
	if (x[0] > y[0])
		horizontal(fdf, x, y, xy);
	else
		vertical(fdf, x, y, xy);
}
