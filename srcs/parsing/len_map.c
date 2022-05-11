/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:04:26 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/05/11 16:55:09 by bben-yaa         ###   ########.fr       */
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
	(void)env;
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
				secure_line(line);
				printf("here\n");
				// debut autre fonction
				// finish autre fonction
				printf("Ici LA MAP FINI et len vaut %d\n", store_map(env, fd, exit));
				break ;
			}
		}
	}
	printf("on vient la avant\n");
	return (1);
}

int	store_map(t_env *env, int fd, int *exit)
{
	char	*line;
	int		len;

	len = 1;
	line = NULL;
	(void)env;
	while(1)
	{
		line = gnl(fd);
		if (!line)
			break ;
		if (empty_line(line))
		{
			(*exit) = 42;
			secure_line(line);
			// j'imagine qu'ici il y aura un free map
			return (error_message("empty line in map", 0));
		}
		else
		{
			// chercher la width la plus longue
			// et tempis je recommecerais d'ouvrir le fichier pour stocker
			// une fois la map allouer et la stocker
			// une fois stocker parse la map
			// une fois ca fait on passe a l'exec 
			len++;
		}
	}
	env->height = len
	printf("Ici on fini la map et len vaut %d\n", len);
	return (len);
}
