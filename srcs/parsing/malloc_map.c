/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:24:34 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/05/07 17:09:10 by bben-yaa         ###   ########.fr       */
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

int	pass_col(char *line, t_env *env)
{
	int			col;
	static int	i = 0;
	if (i == 2)
		return (1);
	col = ft_check_col(&env->texture, line);
	if (col == -1)
		return (error_message("the floor and the wall are incomplete", 0));
	i++;
	return (1);
}

void	read_file(int fd, int *nb_line, t_env *env, int *stop)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (1)
	{
		line = gnl(fd, nb_line, true);									//je recupere la ligne
		if (!line)														//je check si c'est la fin du fichier 
		{
			printf("Condition qui intervient a la fin du fichier\n");
			break ;
		}
		pass_space(line, &i);
		if (!pass_text(line, env) && (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W'))
		{
			(*stop) = 42;
			break ;
		}
		else if (!pass_col(line, env) && (line[i] == 'F' || line[i] == 'C'))
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
	printf("floor is %d\n", env->texture.f);
	printf("ceiling is %d\n", env->texture.c);
}

void	pass_space(char *line, int *i)
{
	while(line[*i] && line[*i] == ' ')
		(*i)++;
}