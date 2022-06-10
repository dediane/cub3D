/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:16:34 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/06/10 07:56:35 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	is_num(char *line)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	j = 0;
	num = 0;
	pass_space(line, &i);
	if (line[i] == 'F' || line[i] == 'C')
		i++;
	pass_space(line, &i);
	if (line[i] == ',')
		return (error_message("miss number in colors", 0));
	if (!is_num2(line, &i, &j, &num))
		return (0);
	if (j < 3)
		return (error_message("miss number in colors", 0));
	pass_space(line, &i);
	if (line[i] && line[i] != '\n')
		return (error_message("to much params for colors", 0));
	return (1);
}

int	is_num2(char *line, int *i, int *j, int *num)
{
	while (line[(*i)] && (*j) <= 2)
	{
		pass_space(line, i);
		if (line[(*i)] >= '0' && line[(*i)] <= '9')
		{
			while (line[(*i)] && line[(*i)] >= '0' && line[(*i)] <= '9')
				(*i)++;
			(*j)++;
			(*num)++;
		}
		else if ((line[(*i)] == ',' || line[(*i)] == '\n') && (*num) == 1)
		{
			(*i)++;
			(*num) = 0;
		}
		else
			return (error_message("Wrong color's arguments enters for F/C", 0));
		if ((*num) == 2)
			return (error_message("miss comma between number in colors", 0));
	}
	return (1);
}

int	check_file(t_texture *texture)
{
	if (access(texture->no_path, X_OK) == -1)
		return (0);
	else if (access(texture->so_path, X_OK) == -1)
		return (0);
	else if (access(texture->ea_path, X_OK) == -1)
		return (0);
	else if (access(texture->we_path, X_OK) == -1)
		return (0);
	else
		return (1);
}

int	check_path_files(t_env *env)
{
	if (open(env->texture.no_path, O_RDONLY) == -1)
		return (error_message("Path NO can't be open", 0));
	if (open(env->texture.so_path, O_RDONLY) == -1)
		return (error_message("Path SO can't be open", 0));
	if (open(env->texture.we_path, O_RDONLY) == -1)
		return (error_message("Path WE can't be open", 0));
	if (open(env->texture.ea_path, O_RDONLY) == -1)
		return (error_message("Path EA can't be open", 0));
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
