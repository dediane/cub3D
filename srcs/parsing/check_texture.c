/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:36:31 by ddecourt          #+#    #+#             */
/*   Updated: 2022/05/05 16:12:53 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/cub3D.h"

//store textures path
int	ft_store_texture(char *path, char *line)
{
	ft_memmove(line, line + 3, ft_strlen(line));
	path = ft_strdup(line);
	printf("path = [%s]\n", path);
	return (1);
}

//check if the file is an xpm
int	check_texture_extension(char *line)
{
	int	size;

	size = ft_strlen(line);
	if (line[size - 4] != '.' || line[size - 3] != 'x' || \
	line[size - 2] != 'p' || line[size - 1] != 'm')
		return (0);
	return (1);
}

//check the if the path right formatted and store it
int	ft_check_texture(t_texture *texture, char *line)
{
	int i;

	i = 0;
	if (!check_texture_extension(line))
		return (ft_putstr("Error: texture is not in xpm extention.\n"), 2);
	if (line[i] == 'N' && line[i + 1] && line[i + 1] == 'O')
		ft_store_texture(texture->no_path, line);
	if (line[i] == 'S' && line[i + 1] && line[i + 1] == 'O')
		ft_store_texture(texture->so_path, line);
	if (line[i] == 'W' && line[i + 1] && line[i + 1] == 'E')
		ft_store_texture(texture->we_path, line);
	if (line[i] == 'E' && line[i + 1] && line[i + 1] == 'A')
		ft_store_texture(texture->ea_path, line);
	return (1);
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
