/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octavio.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:50:19 by groberto          #+#    #+#             */
/*   Updated: 2019/02/06 14:58:10 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

e->mlx.window = mlx_new_window(e->mlx.init, e->file.larg,
		e->file.haut, “Raytracer”);
e->mlx.image = mlx_new_image(e->mlx.init, e->file.larg, e->file.haut);
e->mlx.data = mlx_get_data_addr(e->mlx.image, &e->mlx.bpp,
		&e->mlx.size_l, &e->mlx.endian);
frame(e);
mlx_put_image_to_window(INIT, WIN, IMG, 0, 0);
mlx_mouse_hook(WIN, mousse_hook, e);
mlx_hook(e->mlx.window, 2, 0, keypress, e);
mlx_hook(e->mlx.window, 17, 0, mouse_hook_escape, e);
mlx_loop(e->mlx.init);

	ocojeda- [12:40 PM]
if (fst->data != NULL)
	((unsigned int *)fst->data)[x + y* LEN] = abs(color);
if (fst->data != NULL)
	((unsigned int *)fst->data)[x + y* LEN] = 0xFFFFFF
