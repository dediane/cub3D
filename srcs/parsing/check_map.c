/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:36:57 by ddecourt          #+#    #+#             */
/*   Updated: 2021/12/21 01:00:56 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./../inc/cub3D.h"


//fonction pour check si map peut-etre ouverte

//fonction pour parser la map
		//fonction pour parser la map (textures & colors)
				//fonction check si les textures existent et peuvent etre ouvertes

				//fonction check si les couleurs de floor et ceiling sont valide

		//fonction pour parser la map (1001)
				//fonction check si la map ne contient que des caracteres valides
				//fonction qui check si la map contient un seul player


//fonction pour check si map a la bonne extension
int	check_file_extension(char *map)
{
	int	size;

	size = ft_strlen(map);
	if (map[size - 4] != '.' || map[size - 3] != 'c' || \
	map[size - 2] != 'u' || map[size - 1] != 'b')
		return (0);
	return (1);
}

int	ft_check_map(char *path, t_env *env)
{
	int fd;
	
	if (!ft_check_extention(path))
		return (1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_putstr("Error\n"), 2);
	ft_store_map(path, env, fd);
}