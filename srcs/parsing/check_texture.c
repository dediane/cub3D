/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:36:31 by ddecourt          #+#    #+#             */
/*   Updated: 2021/12/27 02:40:42 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./../inc/cub3D.h"

int	ft_store_texture(char *path, char *line)
{
	ft_memmove(line, line + 3, ft_strlen(line));
	path = ft_strdup(line);
	printf("path = [%s]\n", path);
}

int	ft_check_texture(t_texture *texture, char *line)
{
	int i;

	i = 0;
	if (line[i] == 'N' && line[i + 1] && line[i + 1] == 'O')
		ft_store_texture(texture->NO_path, line);
	if (line[i] == 'S' && line[i + 1] && line[i + 1] == 'O')
		ft_store_texture(texture->SO_path, line);
	if (line[i] == 'W' && line[i + 1] && line[i + 1] == 'E')
		ft_store_texture(texture->WE_path, line);
	if (line[i] == 'E' && line[i + 1] && line[i + 1] == 'A')
		ft_store_texture(texture->EA_path, line);
	else
		return (ft_putstr("Error\n"), 2);
}