/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:36:31 by ddecourt          #+#    #+#             */
/*   Updated: 2022/05/24 15:53:35 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

//store texture path
int	ft_store_texture(char **path, char *line)
{
	int	i;

	i = 0;
	ft_memmove(&line[i], &line[i] + 3, ft_strlen(&line[i]));
	pass_space(line, &i);
	*path = ft_strdup(&line[i]);
	return (1);
}

//a revoir l.21
//store color fot floor and ceiling
int	ft_store_fc(char *line, unsigned int *rgb, int i)
{
	int	col;
	int	ret;
	t_rgb couleur;


	col = 0;
	while (col < 3 && line[i])
	{
		pass_space(line, &i);
		ret = recup_col(line, i);
		if (ret == -1)
			return (-1);
		store_rgb(ret, col, &couleur);
		i += len_num(&line[i]);
		if ((line[i] == '\n' || line[i] == '\0') && col == 2)
			break ;
		else if (line[i] == ',')
			i++;
		col++;
	}
	(*rgb) = create_trgb(1, couleur.r, couleur.g, couleur.b);
	return (1);
}

int	ft_check_col(t_texture *texture, char *line)
{
	int	i;

	i = 0;
	if (!is_num(line))
		return (-1);
	if (line[i] == 'F' && texture->f == false)
	{
		texture->f = true;		// le true vient apres avoir check la coul
		return (ft_store_fc(&line[i + 1], &texture->fcl, i + 1));
	}
	else if (line[i] == 'C' && texture->c == false)
	{
		texture->c = true;		// le true vient apres avoir check la coul
		return (ft_store_fc(&line[i + 1], &texture->ccl, i + 1));
	}
	return (-1);
}

//	check path texture and if texture exist
int	ft_check_texture(t_texture *texture, char *line)
{
	int	i;

	i = 0;
	if (!extension(".xpm", line, 5))
		return (error_message("texture is not in xpm extention", -1));
	while (line[i])
	{
		pass_space(line, &i);	
		if (line[i] == 'N' && line[i + 1] && line[i + 1] == 'O' && texture->no_path == NULL)
			return (ft_store_texture(&(texture->no_path), &line[i]));
		else if (line[i] == 'S' && line[i + 1] && line[i + 1] == 'O' && texture->so_path == NULL)
			return (ft_store_texture(&(texture->so_path), &line[i]));
		else if (line[i] == 'W' && line[i + 1] && line[i + 1] == 'E' && texture->we_path == NULL)
			return (ft_store_texture(&(texture->we_path), &line[i]));
		else if (line[i] == 'E' && line[i + 1] && line[i + 1] == 'A' && texture->ea_path == NULL)
			return (ft_store_texture(&(texture->ea_path), &line[i]));
		else
			return(error_message("texture are not valid", -1));
	}
	return (error_message("texture are not valid" , -1));
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


