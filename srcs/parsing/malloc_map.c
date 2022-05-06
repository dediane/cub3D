/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:24:34 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/05/05 16:17:55 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"


void	secure_line(char *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
}

void	read_file(int fd, int *p)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	p->nb_of_lines = 0;
	while (1)
	{
		line = get_next_line(fd, *p, true);
		if (!line || !line[0])
		{
			secure_line(line);
			break;
		}
		secure_line(line);
		i++;
	}
	secure_line(line);
	close(fd);
}
/*
int	malloc_map(t_env *env, int fd)
{
	//int	*size;
}
*/