/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:21:11 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/05/19 14:28:05 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	open_map(t_env *env, int fd)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = gnl(fd);
		if (!line)
			break ;
		else if (is_param(line))
			secure_line(line);
		else
		{
			if (empty_line(line))
				secure_line(line);
			else
			{
				return (alloc_map(env, fd, line));
			}
		}
	}
	return (1);
}

int	alloc_map(t_env *env, int fd, char *line)
{
	int		j;

	j = 0;
	env->map = malloc(sizeof(char *) * (env->height + 1));
	if (env->map == NULL)
		return (error_message("malloc fail", 0));
	while (j < env->height)
	{
		if (j != 0)
			line = gnl(fd);
		if (!line)
			break ;
		else
		{
			env->map[j] = malloc(sizeof(char) * (env->width + 1));
			if (env->map[j] == NULL)
				return (error_message("malloc fail", 0));
			copy_line(line, env, env->map[j]);
			secure_line(line);
			j++;
		}
	}
	env->map[j] = NULL; //derniere liste
	return (1);
}

int		ft_len(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

void	copy_line(char *line, t_env *env, char *map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_len(line);
	while (i < env->width)
	{
		if (!line[i])
		{
			while (i < env->width)
			{
				map[i] = ' ';
				i++;
			}
			map[i] = '\0';
		}
		else if (line[i] && line[i] == '\n')
		{
			while (i < env->width)
			{
				map[i] = ' ';
				i++;
			}
			break;
		}
		else
		{
			if (line[i])
				map[i] = line[i];
		}
		i++;
	}
	map[i] = '\0';
}