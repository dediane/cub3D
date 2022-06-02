/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:36:57 by ddecourt          #+#    #+#             */
/*   Updated: 2022/06/02 19:02:57 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	ft_check_file(int fd)
{
	if (fd < 0)
		return (0);
	return (1);
}
//fonction pour check si map a la bonne extension
		//fonction pour parser la map (textures & colors)
		//fonction check si les textures existent et peuvent etre ouvertes
		//fonction check si les couleurs de floor et ceiling sont valide

//fonction pour check si map peut-etre ouverte
//fonction pour parser la map
		//fonction pour parser la map (1001)
		//fonction check si la map ne contient que des caracteres valides
		//fonction qui check si la map contient un seul player

int	check_around(char **map, int x, int y)
{
	if ((map[x - 1][y] && (map[x - 1][y] != '0') && (map[x - 1][y] != '1') \
	&& (map[x - 1][y] != 'S') && (map[x - 1][y] != 'W') && \
	(map[x - 1][y] != 'N') && (map[x - 1][y] != 'E')) || \
	(map[x + 1][y] && (map[x + 1][y] != '0') \
	&& (map[x + 1][y] != '1') && (map[x + 1][y] != 'S') \
	&& (map[x + 1][y] != 'W') && (map[x + 1][y] != 'N') \
	&& (map[x + 1][y] != 'E')) || (map[x][y - 1] && (map[x][y - 1] != '0') \
	&& (map[x][y - 1] != '1') && (map[x][y - 1] != 'S') && \
	(map[x][y - 1] != 'W') && (map[x][y - 1] != 'N') && (map[x][y - 1] != 'E')))
		return (0);
	return (1);
}

void	player_pos(char c, t_env *env)
{
	if (c == 'N')
	{
		env->ray.vec.diry = -1;
		env->ray.vec.planx = 0.66;
	}
	if (c == 'S')
	{
		env->ray.vec.diry = 1;
		env->ray.vec.planx = -0.66;
	}
	if (c == 'W')
	{
		env->ray.vec.dirx = -1;
		env->ray.vec.plany = -0.66;
	}
	if (c == 'E')
	{
		env->ray.vec.dirx = 1;
		env->ray.vec.plany = 0.66;
	}
}

int	check_valid_char(t_env *env, char c, int x, int y)
{
	if (c == ' ')
		return (1);
	else if (c == '0' || c == '1')
	{
		if (c == '0')
		{
			if (!(check_around(env->map, x, y)))
				return (0);
		}
		return (1);
	}
	else if ((c == 'N' || c == 'S' || c == 'W' || c == 'E') && env->ppos == 0)
	{
		env->spawn_pos[0] = x;
		env->spawn_pos[1] = y;
		env->ray.mapx = x;
		env->ray.mapy = y;
		env->ppos = 1;
		player_pos(c, env);
		return (1);
	}
	return (0);
}

int	check_wall_line(char *f_line, int width)
{
	int	i;

	i = 0;
	while (f_line[i] && i < width)
	{
		if (f_line[i] != '1' && f_line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_walls(t_env *env, char **map)
{
	int	x;
	int	y;

	x = 0;
	if (!check_wall_line(map[x], env->width))
		return (error_message("Map must be surrounded by walls.", 0));
	while (map[x] && x < env->height - 1)
	{
		y = 0;
		while (map[x][y] && y < env->width)
		{
			if (!check_valid_char(env, map[x][y], x, y))
				return (error_message("Open map or wrong players", 0));
			y++;
		}
		x++;
	}
	if (!(check_wall_line(map[x], env->width)))
		return (error_message("Map must be surrounded by walls.", 0));
	if (!env->ppos)
		return (error_message("Miss player", 0));
	return (1);
}
