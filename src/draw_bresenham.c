/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bresenham.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:48:55 by groberto          #+#    #+#             */
/*   Updated: 2019/02/20 17:45:37 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	parallel(t_config *fdf, int x, int y)
{
	int tabxy[2];
	int x2;
	int y2;
	int z2;
    //tabxy[0] = ((x % fdf->grid.width) * fdf->move.blancks) + (fdf->move.x + (WIDTH / 2) - ((fdf->grid.width * fdf->move.blancks)/ 2));
	//tabxy[1] = ((y % fdf->grid.width) * fdf->move.blancks) + (fdf->move.y + (HEIGHT / 2) - ((fdf->grid.height * fdf->move.blancks)/ 2));
	x2 = x*fdf->move.blancks;
	y2 = y*fdf->move.blancks;
	z2 = fdf->grid.grip[x+ (fdf->grid.width * y)] * fdf->move.z;
    //esta parte va a imprimir los puntos y los espacios entre | este los pone almedio;

	tabxy[0] = fdf->size.dx + x2 + z2;
	tabxy[1] = fdf->size.dy + y2 + z2;

//	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, tabxy[0], tabxy[1], fdf->color);
 	if (x2 / fdf->move.blancks < fdf->grid.width - 1)
 		bresenham(fdf, tabxy,
 		fdf->size.dx + (x2 + fdf->move.blancks) + fdf->grid.grip[x+ 1+(fdf->grid.width * y)] * fdf->move.z, 
 		fdf->size.dy + y2 + fdf->grid.grip[x+1 +(fdf->grid.width * y)] * fdf->move.z);
 	if (y2 / fdf->move.blancks < fdf->grid.height - 1)
 		bresenham(fdf, tabxy,
 		fdf->size.dx + x2 + fdf->grid.grip[x+ (fdf->grid.width * (y+1))] * fdf->move.z, 
 		fdf->size.dy + (y2 + fdf->move.blancks) + fdf->grid.grip[x+ (fdf->grid.width * (y+1))] * fdf->move.z);
}

void	isometric(t_config *fdf, int x, int y)
{
	int tabxy[2];
	int x2;
	int y2;
    
	x2 = x*fdf->move.blancks;
	y2 = y*fdf->move.blancks;

	tabxy[0] = fdf->size.px + (x2 - y2);
//	printf("%d %d %d\n",x, y, x + (fdf->grid.width * y));
	tabxy[1] = fdf->size.py + (x2 + y2) / 2 + fdf->grid.grip[x+ (fdf->grid.width * y)] * fdf->move.z;

//	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, tabxy[0], tabxy[1], fdf->color);
 	if (x2 / fdf->move.blancks < fdf->grid.width - 1)
 		bresenham(fdf, tabxy,
 		fdf->size.px + ((x2 + fdf->move.blancks) - y2), 
 		fdf->size.py + (((x2 + fdf->move.blancks) + y2) / 2) + fdf->grid.grip[x+1+ (fdf->grid.width * y)] * fdf->move.z);
 	if (y2 / fdf->move.blancks < fdf->grid.height - 1)
 		bresenham(fdf, tabxy,
 		fdf->size.px + (x2 - (y2 + fdf->move.blancks)),
 		fdf->size.py + ((x2 + (y2 + fdf->move.blancks)) / 2) + fdf->grid.grip[x+ (fdf->grid.width * (y+1))] * fdf->move.z);
}

void		draw_bresenham(t_config *fdf, int x, int y)
{
	if (fdf->proj == 0)
		isometric(fdf, x, y);
	else if (fdf->proj == 1)
		parallel(fdf, x, y);
}