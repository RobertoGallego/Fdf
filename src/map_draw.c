/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 10:21:02 by groberto          #+#    #+#             */
/*   Updated: 2019/02/20 18:51:33 by groberto         ###   ########.fr       */
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
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, xy[0], xy[1], fdf->color);
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
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, xy[0], xy[1], fdf->color);
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
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, xy[0], xy[1], fdf->color);
	if (x[0] > y[0])
		horizontal(fdf, x, y, xy);
	else
		vertical(fdf, x, y, xy);
}

// void	draw_bresenham(t_config *fdf, int x, int y)
// {
// 	int tabxy[2];
//     //tabxy[0] = ((x % fdf->grid.width) * fdf->move.blancks) + (fdf->move.x + (WIDTH / 2) - ((fdf->grid.width * fdf->move.blancks)/ 2));
// 	//tabxy[1] = ((y % fdf->grid.width) * fdf->move.blancks) + (fdf->move.y + (HEIGHT / 2) - ((fdf->grid.height * fdf->move.blancks)/ 2));

//     //esta parte va a imprimir los puntos y los espacios entre | este los pone almedio;

// 	tabxy[0] = x + fdf->size.px;
// 	tabxy[1] = y + fdf->size.py;

// //	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, tabxy[0], tabxy[1], fdf->color);
//  	if (x / fdf->move.blancks < fdf->grid.width - 1)
//  		bresenham(fdf, tabxy,
//  		(x + fdf->move.blancks) + fdf->size.px, 
//  		y + fdf->size.py);
//  	if (y / fdf->move.blancks < fdf->grid.height - 1)
//  		bresenham(fdf, tabxy,
//  		x + fdf->size.px, 
//  		(y + fdf->move.blancks) + fdf->size.py);
// }

void	make_draw(t_config *fdf)
{
//	int i = 0;
	int x = 0;
	int y = 0;
	
	fdf->size.dx = (fdf->move.x + (WIDTH / 2) - ((fdf->grid.width * fdf->move.blancks)/ 2));
	fdf->size.dy = (fdf->move.y + (HEIGHT / 2) - ((fdf->grid.height * fdf->move.blancks)/ 2));
	
	fdf->size.px = (fdf->move.x + (WIDTH / 2) - (((fdf->grid.width / fdf->grid.height) * fdf->move.blancks)/ 2)/2);
	fdf->size.py = (fdf->move.y + (HEIGHT / 2) - ((fdf->grid.height * fdf->move.blancks)/ 2));
	
	if (fdf->start == 1)
	{
		fdf->color = 0xFFFFFF;
		fdf->move.z = -1;
	}
	fdf->start = 0;

	while (x  < fdf->grid.width || y  < fdf->grid.height - 1)
	{
		if (x  == fdf->grid.width)
		{
			x = 0;
			y ++;
		}
		draw_bresenham(fdf, x, y);
		x ++;
	}

	

	// while (x / fdf->move.blancks < fdf->grid.width || y / fdf->move.blancks < fdf->grid.height - 1)
	// {
	// 	if (x / fdf->move.blancks == fdf->grid.width)
	// 	{
	// 		x = 0;
	// 		y += fdf->move.blancks;
	// 	}
	// 	draw_bresenham(fdf, x, y);
	// 	x += fdf->move.blancks;
		
	// }
/*	while(i < (fdf->grid.width * fdf->grid.height))
	{
		
		//if (fdf->color)
		//	fdf->color = 0xFFFFFF;
		// printf("%d\n", fdf->grid.width);
		draw_bresenham(fdf, i);
		

		// mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr,
		// 		((i % fdf->grid.width) * fdf->move.blancks) + (fdf->move.x + (WIDTH  / 2) - ((fdf->grid.width * fdf->move.blancks) / 2)),
		// 		((i / fdf->grid.width) * fdf->move.blancks) + (fdf->move.y + (HEIGHT  / 2) - ((fdf->grid.height * fdf->move.blancks) / 2)), 
		// 		0xFF0000 + (color_tmp));
		i++;
	}
*/	
	if (WIDTH >= 190 && HEIGHT >= 190)
		info(fdf);
}