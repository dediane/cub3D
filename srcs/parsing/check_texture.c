/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:36:31 by ddecourt          #+#    #+#             */
/*   Updated: 2022/01/08 02:37:26 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./../inc/cub3D.h"

int	ft_store_texture(char *path, char *line)
{
	ft_memmove(line, line + 3, ft_strlen(line));
	path = ft_strdup(line);
	printf("path = [%s]\n", path);
	return (1);
}

int	ft_check_texture(t_texture *texture, char *line)
{
	int i;

	i = 0;
	if (line[i] == 'N' && line[i + 1] && line[i + 1] == 'O')
		ft_store_texture(texture->no_path, line);
	if (line[i] == 'S' && line[i + 1] && line[i + 1] == 'O')
		ft_store_texture(texture->so_path, line);
	if (line[i] == 'W' && line[i + 1] && line[i + 1] == 'E')
		ft_store_texture(texture->we_path, line);
	if (line[i] == 'E' && line[i + 1] && line[i + 1] == 'A')
		ft_store_texture(texture->ea_path, line);
	else
		return (ft_putstr("Error\n"), 2);
	return (1);
}

int	ft_check_valid_files(t_texture *texture)
{
	texture->fd_no = open(texture->no_path, O_RDONLY);
	texture->fd_so = open(texture->so_path, O_RDONLY);
	texture->fd_we = open(texture->we_path, O_RDONLY);
	texture->fd_ea = open(texture->ea_path, O_RDONLY);
	if (texture->fd_no == -1 || texture->fd_so == -1 \
	|| texture->fd_we == -1 || texture->fd_ea == -1)
		return (ft_putstr("Error\nCannot open texture.\n"), 0);
	return (1);
}