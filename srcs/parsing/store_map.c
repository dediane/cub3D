/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:44:40 by ddecourt          #+#    #+#             */
/*   Updated: 2021/12/27 02:29:27 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./../inc/cub3D.h"

int	is_empty(char *s)
{
	int i;

	i = 0;
	if (s == '\n')
		return (1);
	while (s[i])
		if ((ft_isprint(s[i]))
			i++;
	if (i == ft_strlen(s))
		return (1);
	else
		return (0);
}

int ft_store_map(char *path, t_env *env, int fd)
{
	char 	*line;

	while (get_next_line(fd, line) > 0)
	{
		
	}
}
	// if (!(ft_check_texture(env->textures, line)))
	// 	return (0);
	// if (!(ft_check_valid_files(env->textures)))
	// 	return (0);