/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:09:42 by groberto          #+#    #+#             */
/*   Updated: 2019/02/06 15:10:09 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_init(t_fdf *draw)
{
	if (draw->init == 1)
	{
		draw->info = 0;
		draw->z = -5;
		draw->dx = WIDTH * 0.4;
		draw->dy = HEIGHT * 0.2;
		if (draw->chars >= draw->lines)
		{
			draw->sx = draw->chars * 2 > WIDTH ? 1 :
				(WIDTH * 0.5) / draw->chars;
			draw->sy = draw->sx;
		}
		else
		{
			draw->sy = draw->lines * 2 > HEIGHT ? 1 :
				(HEIGHT * 0.5) / draw->lines;
			draw->sx = draw->sy;
		}
		draw->color = 0xFFFFFF;
	}
	draw->init = 0;
}

void		drawing(t_fdf *draw)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	draw_init(draw);
	while (x / draw->sx < draw->chars || y / draw->sy < draw->lines - 1)
	{
		if (x / draw->sx == draw->chars)
		{
			x = 0;
			y += draw->sy;
		}
		projection(draw, x, y);
		x += draw->sx;
	}
	if (WIDTH >= 190 && HEIGHT >= 190)
		info(draw);
}
