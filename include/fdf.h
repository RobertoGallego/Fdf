/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:20:12 by groberto          #+#    #+#             */
/*   Updated: 2019/02/20 18:51:42 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# define WIDTH	1920
# define HEIGHT	1080
# define BUFFER 1280 * 720
# define SPACE 2
#include "libft.h"

#include <stdio.h>


typedef struct			s_move
{
	int x;
	int y;
	float z;
	int blancks;
}						t_move;

typedef struct			s_size
{
	int dx;
	int dy;
	int sx;
	int sy;
	int py;
	int px;
}						t_size;


typedef struct			s_grid
{
	int 	grip[BUFFER];
	int 	width;
	int		height;
}						t_grid;

typedef struct			s_config
{
	t_grid 	grid;
	t_size  size;
	void	*mlx_ptr;
	void	*win_ptr;
	t_move move;
	char	*name; // nombre del fichero fd
	int		color;
	int		start;
	int		proj;
}						t_config;

void		ft_putchar(char c);
int			deal_key(int key, t_config *param);
int			deal_mouse(void);
int			ft_construct_mlx(t_config *first);
int			ft_check(t_config *read);
int			ft_error(char *text);
void		make_draw(t_config *fdf);
void		move(int key, t_config *param);
void		color(int key, t_config *param);
void		zoom(int key, t_config *param);
void		projection(int key, t_config *param);
void		iso_paral(int key, t_config *param);
void		projection(int key, t_config *param);
void		info(t_config *param);
void		draw_bresenham(t_config *fdf, int x, int y);
void		bresenham(t_config *fdf, int *tabxy, int x2, int y2);
#endif
