/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:24:34 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/05/06 16:53:23 by bben-yaa         ###   ########.fr       */
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
		//	secure_line(line);
			printf("Condition qui intervient a la fin du fichier\n");
			break;
		}
		if (!pass_text(line, env))
		{
			(*stop) = 42;
		//	secure_line(line);
			break ;
		}
		secure_line(line);
	}
	secure_line(line);
	close(fd);
	printf("Fin de la lecture du fichier\n");
}

/*
int	malloc_map(t_env *env, int fd)
{
	//int	*size;
}
*/