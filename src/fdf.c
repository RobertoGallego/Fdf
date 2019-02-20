/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 10:19:23 by groberto          #+#    #+#             */
/*   Updated: 2019/02/20 15:59:10 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h" 

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		deal_key(int key, t_config *param)
{
	printf("%i\n", key);
	if(key == 53)
		exit(0);
	move(key, param);
	color(key, param);
	//projection(key, param);
	iso_paral(key, param);
	zoom(key, param);
	projection(key, param);
	
	//mlx_pixel_put(mlx_ptr, win_ptr, 100, 100, 0xFFFFFF);
	return (0);
}

//int		deal_mouse(int button, void *param)
int		deal_mouse(void)
{
	
	//printf("%i\n", key);
	
	// ft_putchar('W');
	//mlx_pixel_put(mlx_ptr, win_ptr, 100, 100, 0xFFFFFF);
	return (0);
}

//void	ft_config(t_af *p) estos seran los parametros de colores tamano etc de la malla

int		ft_construct_mlx(t_config *first)
{

	//ft_config(*first); y aqui deberia iniciar esos parametros
	first->start = 1;
	first->proj = 0;
	first->mlx_ptr = mlx_init();
	 // identificar la parte grafica
	first->win_ptr = mlx_new_window(first->mlx_ptr, WIDTH,  HEIGHT, first->name); // x/y/titulo, abrir una ventana
//	first->data = mlx_get_data_addr(first->image, first->mlx.bpp, &e->mlx.size_l, &e->mlx.endian);
//	first->image = mlx_new_image(first->mlx_ptr, first->grid.height, first->grid.width);
	// aqui tengo que poner mlx_new_image para poder manipular la imagen.
	make_draw(first);
	//	mlx_pixel_put(first->mlx_ptr, first->win_ptr, 550, 550, 0xFFFFFF); // pixeles. poner imagen aca
	//mlx_key_hook(first->win_ptr, deal_key, (void *)0); // touch
	mlx_key_hook(first->win_ptr, deal_key, first); // touch keyboard
	mlx_mouse_hook(first->win_ptr, deal_mouse, first); // button mouse

	mlx_loop(first->mlx_ptr); // demanda a macos una parte de desgne, mouse keyboard, evenement.

	return (0);
}
