/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:42:35 by groberto          #+#    #+#             */
/*   Updated: 2019/02/11 12:16:30 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		free_splited_str(char **str)
{
	int i;

	i = 0;
	while (str[i])
		ft_memdel((void **)&str[i++]);
	ft_memdel((void **)&str);
}

int		ft_count_words(char const *str)
{
	int		count;
	int		sw;
	char	s;

	sw = 0;
	count = 0;
	s = ' ';
	while (*str != '\0') // indiferente al fin de la string leer todo
	{
		if (sw == 1 && *str == s) // si hay un espacio saltamos
			sw = 0;
		if (sw == 0 && *str != s) // comienza en 0 y no es un espacio vacio (es una letra)
		{
			sw = 1;
			count++; // contamos 1 2 3 4 ...
		}
		str++; // recorrimos la str completa
	}
	return (count); // enviamos el valos de las palabras sin espacios
}

int		ft_check_lines(t_config *read, char *line)
{
	int		fd;
	int		word;
	char 	**tmp; // [0] = ["10"] tmp = ["10" "10" "10"] 

	int 	i =0;
	int		flag = 0;
	int		p = 0;

	line = "\0";
	fd = open(read->name, O_RDONLY); // nombre del fichero a leer
	// get_next_line(fd, &line); //leemos
	read->grid.height = 0;
	while (get_next_line(fd, &line) > 0) // que aya contenido
	{
		if(flag == 0)
		{
				word = ft_count_words(line); // guardamos las palabras
				flag = 1; // para que entre una vez y lea la primera linea para comparar
				read->grid.width = word; // voy a guardar el ancho
		} 
		if(word != ft_count_words(line)) // vamos a dar vueltas y checkear todas las lineas
			return (ft_error("Found wrong line length.")); // si una es diferemte cago el programa
		tmp = ft_strsplit(line, ' '); // romper las lineas separadas por espacio
		i = 0;
		while(tmp[i])
		{
			read->grid.grip[p] = ft_atoi(tmp[i]); // como es una string hay que transformarlo en un int
			// printf("%i", (int)read->grid.grip[p]); // char solamente por el espacio de memoria que es la mitad de un int
			p++;
			i++;
		}
		read->grid.height++; // y aca el largo
		// printf("\n");
		free_splited_str(tmp);
		free(line); // liberamos para seguir contando una nueva linea
	}

	close(fd);
	return (0);
	//AQUI ESTOY
}

int		ft_check_files(t_config *read, char *line) //voy a checkear que mi fichero no este vacio
{
	int fd;

	line = NULL;
	fd = open(read->name, O_RDONLY); // nombre del fichero y leemos
	if (get_next_line(fd, &line) <= 0) // en vez de ret si es -1 o 0 no data found.
		return (ft_error("No data found."));
	close(fd);
	free(line);
	return (0);
}

int		ft_check(t_config *read)
{
/*	(void)read;
	ft_putstr("OK");
	return (0);*/ // comprobando que mis ficheros esten conectados.

	char *line;

	line = NULL;
	if (ft_check_lines(read, line) == -1) // verifico que las lineas de mi programa sean correctas.
		return (-1);
	if (ft_check_files(read, line) == -1) // verifico que mi fd no este vacio.
		return (-1);
	return (0);
}
