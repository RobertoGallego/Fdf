/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:45:42 by groberto          #+#    #+#             */
/*   Updated: 2019/02/20 18:51:01 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_error(char *text)
{
	ft_putendl(text);
	return (-1);
}

void init_movements(t_config * env)
{
	env->move.x = 0;
	env->move.y = 0;
	env->move.z = 0;
	env->move.blancks = SPACE;
	
}

int		main(int argc, char *argv[])
{
	t_config	start; //datos de mi structura
	int			fd; // file descriptor

	if (argc == 2) // si tengo dos argumentos entonces arranca
	{
		init_movements(&start);
		start.name = argv[1]; // stock name, nombre del fichero pasado en parametros
		if ((fd = open(argv[1], O_RDONLY)) == -1) // si en el argumento escribimos weas
			return (ft_error("error: invalide file"));
		else
		{
			if (ft_check(&start) == -1) // aca vamos a pasar los parametros de mi fd
				return (-1);
	//		config = (t_config *)malloc(sizeof(t_config));
			ft_construct_mlx(&start); // aca llegamos a construir nuestro proyecto
	//		free(config);
		}
		close(fd); // si no pasa el parsin como quedo abierto lo cerramos
	}
	else
		return (ft_error("usage: ./fdf FileName")); // aca el resto
//	config = (t_config *)malloc(sizeof(t_config));
//	ft_construct_mlx(config);*/
//	free(config);
	return (0);
}
