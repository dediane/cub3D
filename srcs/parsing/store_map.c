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

int ft_store_map(char *path, t_env *env, int fd)
{
	char *line;
	
	get_next_line(fd, line);
	if (!(ft_check_texture(env->textures, line)))
		return (0);
	if (!(ft_check_valid_files(env->textures)))
		return (0);
}