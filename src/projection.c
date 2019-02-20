/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:39:57 by groberto          #+#    #+#             */
/*   Updated: 2019/02/15 10:46:23 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		parallel(t_fdf *fdf)
{
	int		tabxy[2];

	tabxy[0] = fdf->grip.width +
		fdf->grid.grip[fdf->sy][fdf->sx] * fdf->z;
	tabxy[1] = fdf->grip.height +
		fdf->grid.grip[fdf->sy][fdf->sx] * fdf->z;
	if (fdf->sx < fdf->chars - 1)
		bresenham(fdf, tabxy, fdf->grip.width + (fdf->sx) +
				fdf->grid.grip[fdf->sx][fdf->sx + 1] * fdf->z,
				fdf->grip.height +
				fdf->grid.grip[fdf->sy][fdf->sx + 1] * fdf->z);
	if (fdf->sy < fdf->lines - 1)
		bresenham(fdf, tabxy, fdf->grip.width +
				fdf->grid.grip[fdf->sy + 1][sfdf->sx] * fdf->z,
				fdf->grip.height + ( + fdf->sy) +
				fdf->grid.grip[fdf->sy + 1][fdf->sx] * fdf->z);
}

void		isometric(t_fdf *fdf, int x, int y)
{
	int		tabxy[2];

	tabxy[0] = fdf->grip.width + (x - y);
	tabxy[1] = fdf->grip.height + (x + y) / 2 +
		fdf->grid.grip[y / fdf->sy][x / fdf->sx] * fdf->z;
	if (x / fdf->sx < fdf->chars - 1)
		bresenham(fdf, tabxy, fdf->grip.width + ((x + fdf->sx) - y),
				fdf->grip.height + ((x + fdf->sx) + y) / 2 +
				fdf->grid.grip[y / fdf->sy][x / fdf->sx + 1] * fdf->z);
	if (y / fdf->sy < fdf->lines - 1)
		bresenham(fdf, tabxy, fdf->grip.width + (x - (y + fdf->sy)),
				fdf->grip.height + (x + (y + fdf->sy)) / 2 +
				fdf->grid.grip[y / fdf->sy + 1][x / fdf->sx] * fdf->z);
}

void		projection(t_fdf *fdf, int x, int y)
{
	if (fdf->proj == 0)
		isometric(fdf, x, y);
	else if (fdf->proj == 1)
		parallel(fdf, x, y);
}
