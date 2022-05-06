/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:24:34 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/05/06 17:39:39 by bben-yaa         ###   ########.fr       */
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

int	pass_text(char *line, t_env *env)
{
	int			text;
	static int	i = 0;

	text = 0;
	if (i == 4)
		return (1);
	text = ft_check_texture(&env->texture, line);
	if (text == -1)
	{
		return (error_message("textures are not complete", 0));
	}
	i++;
	return (1);
}
/*
int	pass_col(char *line, t_env *env)
{
	int			col;
	static int	i = 0;
	if (i == 2)
		return (1);
	col = ft_check_col(&env);
}*/

void	read_file(int fd, int *nb_line, t_env *env, int *stop)
{
	char	*line;

	line = NULL;
	(void)env;
	(void)stop;
	while (1)
	{
		line = gnl(fd, nb_line, true);									//je recupere la ligne
		if (!line)														//je check si c'est la fin du fichier 
		{
			printf("Condition qui intervient a la fin du fichier\n");
			break;
		}
		if (!pass_text(line, env))
		{
			(*stop) = 42;
			break ;
		}
		secure_line(line);
	}
	secure_line(line);
	close(fd);
	printf("Fin de la lecture du fichier\n");
	printf("alors on a :\n");
	printf("north path :%s\n", env->texture.no_path);
	printf("south path :%s\n", env->texture.so_path);
	printf("east path :%s\n", env->texture.ea_path);
	printf("weast path :%s\n", env->texture.we_path);
}

void	pass_space(char *line, int *i)
{
	while(line[*i] && line[*i] == ' ')
		(*i)++;
}

/*
int	malloc_map(t_env *env, int fd)
{
	//int	*size;
}
*/