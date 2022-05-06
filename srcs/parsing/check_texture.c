/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:36:31 by ddecourt          #+#    #+#             */
/*   Updated: 2022/05/06 17:02:22 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/cub3D.h"

//store textures path
int	ft_store_texture(char **path, char *line)
{
	ft_memmove(line, line + 3, ft_strlen(line));
	*path = ft_strdup(line);
	return (1);
}

//check the if the path right formatted and store it
int	ft_check_texture(t_texture *texture, char *line)
{
	int	i;

	i = 0;
	if (!extension(".xpm", line, 5))
		return (error_message("texture is not in xpm extention", -1));
	if (line[i] == 'N' && line[i + 1] && line[i + 1] == 'O' && texture->no_path == NULL)
		return (ft_store_texture(&(texture->no_path), line));
	else if (line[i] == 'S' && line[i + 1] && line[i + 1] == 'O' && texture->so_path == NULL)
		return (ft_store_texture(&(texture->so_path), line));
	else if (line[i] == 'W' && line[i + 1] && line[i + 1] == 'E' && texture->we_path == NULL)
		return (ft_store_texture(&(texture->we_path), line));
	else if (line[i] == 'E' && line[i + 1] && line[i + 1] == 'A' && texture->ea_path == NULL)
		return (ft_store_texture(&(texture->ea_path), line));
	else if (!texture->no_path && !texture->so_path && !texture->we_path && !texture->ea_path)
		return (-1);
	return (2);
}

//function to load a texture
int	load_texture(t_env *env, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(env->params.mlx, path, \
	&(img->width), &(img->height));
	if (img->img)
		img->addr = mlx_get_data_addr(img->img, \
		&(img->bits_per_pixel), &(img->line_length), \
		&(img->endian));
	return (0);
}

//load all textures images
int	load_all_textures(t_env *env)
{
	load_texture(env, &(env->texture.no_texture), env->texture.no_path);
	load_texture(env, &(env->texture.so_texture), env->texture.so_path);
	load_texture(env, &(env->texture.we_texture), env->texture.we_path);
	load_texture(env, &(env->texture.ea_texture), env->texture.ea_path);
	return (0);
}
