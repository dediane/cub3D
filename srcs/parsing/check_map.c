/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:36:57 by ddecourt          #+#    #+#             */
/*   Updated: 2022/01/26 11:16:15 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/cub3D.h"


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
	
	if (!(check_file_extension(path)))
		return (1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_putstr("Error\n"), 2);
	ft_store_map(path, env, fd);
	return (0);
}

int check_around(char **map, int x, int y)
{
	if ((map[x - 1][y] && (map[x - 1][y] != '0') && (map[x - 1][y] != '1')\
	&& (map[x - 1][y] != 'S') && (map[x - 1][y] != 'W') && (map[x - 1][y] != 'N')\
	&& (map[x - 1][y] != 'E')) || \
	(map[x + 1][y] && (map[x + 1][y] != '0') && (map[x + 1][y] != '1') \
	&& (map[x + 1][y] != 'S') && (map[x + 1][y] != 'W') && (map[x + 1][y] != 'N')\
	&& (map[x + 1][y] != 'E')) || \
	(map[x][y - 1] && (map[x][y - 1] != '0') && (map[x][y - 1] != '1') \
	&& (map[x][y - 1] != 'S') && (map[x][y - 1] != 'W') && (map[x][y - 1] != 'N')\
	&& (map[x][y - 1] != 'E')))
		return (0);
	return (1);
}

int	check_valid_char(t_env *env, char c, int x, int y)
{
	if (c == ' ')
		return (1);
	if (c == '0' || c == '1')
	{
		if (c == '0')
		{
			if (!(check_around(env->map, x, y)))
				return (0);
		}
		return (1);
	}
	if ((c == 'N' || c == 'S' || c == 'W' || c == 'E') && env->ppos == 0)
	{
		env->spawn_pos[0] = x;
		env->spawn_pos[1] = y;
		env->ppos = 1;
		return (1);
	}
	return (0);
}

/*int	check_wall_all_around(t_env *env, char **map)
{
	int x;
	int y;
	int map_length;
	int buf;
	int buf2;

	x = -1;
	map_length = 0;
	while (map[++x])
		map_length++;
	 

	// check si premiere et derniere lignes sont que des 1 ou des espaces.
	// check si premiere ligne en dessous espace == 1 et a gauche et a droite :
	// 1 1
	// 111

	// 1  1
	// 1111

	// si pos = espace et pos + 1 = espace alors:
	//check si pos (x + 1) = 1 et si pos (x -)
}*/

//x = hauteur (ligne)  latitude
//y = largeur (position case)  longitude
/*int ft_check_walls(t_env *env, char **map)
{
	int x;
	int y;

	x = -1;
	if (!check_wall_line(map[++x]))
		return (ft_putstr("Error\nMap must be surrounded by walls.\n"), 0);
	while (map[++x])
	{
		y = -1;
		while (map[++y])
		{
			if (!(check_valid_char(env, map[x][y], x, y)))
				return (ft_putstr("Error\nInvalid map, wrong caracters or open map.\n"), 0);
		}
	}
	if (!(check_wall_all_around(env, map)))
		return (ft_putstr("Error\nMap must be surrounded by walls. \n"), 0);
	return (1);
}*/