/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:04:26 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/05/12 13:09:23 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int len_map(char *line)
{
	(void)line;
	return (0);
}

int empty_line(char *line)
{
	int i;

	i = 0;
	pass_space(line, &i);
	if (line[i] == '\n')
		return (1);
	else
		return (0);
}

int read_map(int fd, t_env *env, int *exit)
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
				printf("Dans le debut de la map\n");
				secure_line(line);
				return (store_map(env, fd, exit));
			}
		}
	}
	return (1);
}

int	store_map(t_env *env, int fd, int *exit)
{
	char	*line;
	int		len;

	len = 1;
	line = NULL;
	while(1)
	{
		line = gnl(fd);
		if (!line)
			break ;
		if (empty_line(line))
		{
			(*exit) = 42;
			secure_line(line);
			return (error_message("empty line present in map", 0));
		}
		else
		{
			env->width = store_width(line, env->width);
			len++;
			secure_line(line);
		}
	}
	env->height = len;
	return (0);
}
			// chercher la width la plus longue
			// et tempis je recommecerais d'ouvrir le fichier pour stocker
			// une fois la map allouer et la stocker
			// une fois stocker parse la map
			// une fois ca fait on passe a l'exec 

int	store_width(char *line, int width)
{
	int	temp_width;
	int	i;

	i = 0;
	temp_width = 0;
	while (line[i] && line[i] != '\n')
	{
		i++;
		temp_width++;
	}
	printf("la width de la line --%s--, vaut %d\n", line, temp_width);
	if (temp_width > width)
		return (temp_width);
	else
		return (width);
}
