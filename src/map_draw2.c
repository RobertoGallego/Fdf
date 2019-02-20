/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 10:21:02 by groberto          #+#    #+#             */
/*   Updated: 2019/02/11 12:18:09 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void		horizontal(t_config *fdf, int x, int y, int x1, int y1)
{
	int		i;
	int		e;
	int tmp0 = 0;
	int tmp1 = 0;

	i = 0;
	e = x / 2;

	while (i < x)
	{
		tmp0 += x1;
		e += y;
		if (e >= x)
		{
			e -= x;
			tmp1 += y1;
		}
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, tmp0, tmp1, 0xFFFFFF);
		i++;
	}
}*/
/*
void	ligne(t_config *fdf, int xi, int yi, int xf, int yf)
{
	int x,y,dx,sx,dy,sy,err,e2;

	x = xi;
	y = yi;
	dx = (ft_abs(xf - xi));
	dy = (ft_abs(yf - yi));
	sx = (xi < xf ? 1 : -1);
	sy = (yi < yf ? 1 : -1);
	err = (dx > dy ? dx : -dy) / 2;
	while (1)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0xFF00FF);
		if (xi == xf && yi == yf)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			xi += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			yi += sy;
		}
	}
}

void ligne(t_config *fdf, int xi,int yi,int xf,int yf)
{
	int dx,dy,cumul,x,y;
	x = xi ;
	y = yi ;
	dx = (ft_abs(xf - xi)) ;
	dy = (ft_abs(yf - yi)) ;
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0xFF00FF);
	cumul = dx / 2 ;
	for ( x = xi+1 ; x <= xf ; x++ ) {
    cumul += dy ;
    if ( cumul >= dx ) {
      cumul -= dx ;
      y += 1 ; }
    mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0xFF00FF); 
}
}
*/
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

void	draw_bresenham(t_config *fdf, int i)
{
	int x2;
	int y2;


	int		tabxy[2];

	tabxy[0] = ((i  % fdf->grid.width) * fdf->move.blancks) + (fdf->move.x  + (WIDTH  / 2 ) - ((fdf->grid.width  * fdf->move.blancks) / 2));
	tabxy[1] = ((i  / fdf->grid.width ) * fdf->move.blancks) + (fdf->move.y + (HEIGHT  / 2 ) - ((fdf->grid.height  * fdf->move.blancks) / 2));
	
	x2 = ((i  % fdf->grid.width ) * fdf->move.blancks ) + ((fdf->move.x ) + (WIDTH / 2) - ((fdf->grid.width  * fdf->move.blancks) / 2));
	y2 = ((i  / fdf->grid.width ) * fdf->move.blancks) + (fdf->move.y  + (HEIGHT  / 2) - ((fdf->grid.height  * fdf->move.blancks) / 2));

	if (fdf->move.x < fdf->grid.width - 1)
		bresenham(fdf, tabxy, ((i % fdf->grid.width) * fdf->move.blancks) + (fdf->move.x +(WIDTH  / 2 ) - ((fdf->grid.width + 1 * fdf->move.blancks) / 2)), ((i  / fdf->grid.width ) * fdf->move.blancks) + (fdf->move.y + (HEIGHT  / 2 ) - ((fdf->grid.height  * fdf->move.blancks) / 2)));

	if (fdf->move.y <fdf->grid.height - 1)
		bresenham(fdf, tabxy, ((i  % fdf->grid.width) * fdf->move.blancks) + (fdf->move.x + (WIDTH  / 2 ) - ((fdf->grid.width  * fdf->move.blancks) / 2)), ((i  / fdf->grid.width ) * fdf->move.blancks) + (fdf->move.y + (HEIGHT  / 2 ) - ((fdf->grid.height + 1 * fdf->move.blancks) / 2)));


	bresenham(fdf, tabxy, x2, y2);
	unsigned int red = 0xFF0000;
	unsigned int green = 0x00FF00;
	unsigned int blue = 0x0000FF;

	red += (0x010000 * fdf->color);
	green += (0x000100 * fdf->color);
	blue += (0x000001 * fdf->color);

}

void	make_draw(t_config *fdf)
{
	int i = 0;
	// printf("ccouou \n");
	while(i < (fdf->grid.width * fdf->grid.height))
	{
		fdf->color = ((i / fdf->grid.width) * fdf->move.blancks)+ HEIGHT / 2 + fdf->move.y - fdf->grid.grip[i];
		if(fdf->color > 256)
			fdf->color = 256;
		// printf("cxcouou %d\n", fdf->grid.width);
		// draw_bresenham(fdf, i);

		// mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr,
		// 		((i % fdf->grid.width) * fdf->move.blancks) + (fdf->move.x + (WIDTH  / 2) - ((fdf->grid.width * fdf->move.blancks) / 2)),
		// 		((i / fdf->grid.width) * fdf->move.blancks) + (fdf->move.y + (HEIGHT  / 2) - ((fdf->grid.height * fdf->move.blancks) / 2)), 
		// 		0xFF0000 + (color_tmp));
		i++;
	}
}