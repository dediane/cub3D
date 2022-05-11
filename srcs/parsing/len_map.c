/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:04:26 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/05/11 13:46:31 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int len_map(char *line)
{
	(void)line;
	return (0);
}

int read_map(int fd, t_env *env)
{
	char	*line;
	int		len;

	line = NULL;
	len = 0;
	(void)env;
	while (1)
	{
		line = gnl(fd);
		if (!line)
			break ;
		else if (is_param(line))
			secure_line(line);
		else
			secure_line(line);
	}
	return (1);
}
