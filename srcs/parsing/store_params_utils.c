/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_params_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:50:33 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/06/08 18:38:51 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	len_num(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ',')
		i++;
	return (i);
}

void	secure_line(char *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
}

void	pass_space(char *line, int *i)
{
	while (line[*i] && (line[*i] == ' '))
		(*i)++;
}

void	finish_line(char *line, int *i)
{
	while (line[*i])
		(*i)++;
}

//load all textures images
int	load_all_textures(t_env *env)
{
	load_texture(env, &(env->texture.text[0]), env->texture.no_path);	//No
	load_texture(env, &(env->texture.text[1]), env->texture.so_path);	//So
	load_texture(env, &(env->texture.text[2]), env->texture.we_path);	//We
	load_texture(env, &(env->texture.text[3]), env->texture.ea_path);	//Ea
	return (0);
}
