/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:24:34 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/05/09 18:47:43 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"



int	pass_text(char *line, t_env *env, int *len, int *stop)
{
	int			text;

	text = ft_check_texture(&env->texture, line);
	if (text == -1)
	{
		(*stop) = 42;
		return (error_message("textures are not complete", 0));
	}
	finish_line(line, len);
	return (1);
}

int	pass_col(char *line, t_env *env, int *len, int *stop)
{
	int	col;

	col = ft_check_col(&env->texture, line);
	if (col == -1)
	{
		(*stop) = 42;
		return (error_message("the floor and the wall are incomplete", 0));
	}
	finish_line(line, len);
	return (1);
}


void	read_file(int fd, int *nb_line, t_env *env, int *stop)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = gnl(fd, nb_line, true);									//je recupere la ligne
		if (!line)														//je check si c'est la fin du fichier 
		{
			printf("Condition qui intervient a la fin du fichier\n");
			break ;
		}
		if (is_param(line))
		{
			if (!read_line(line, env, stop))
				break ;
			// maybe here we can check 6 lines only
		}
		else
			secure_line(line);
	}
	secure_line(line);
	close(fd);
}

int	read_line(char *line, t_env *env, int *stop)
{
	int	i;

	i = 0;
	while(line[i])
	{
		pass_space(line, &i);
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
		{
			if (!pass_text(line, env, &i, stop))
				return (0); // we want to break
		}
		else if (line[i] == 'F' || line[i] == 'C')
		{
			if (!pass_col(line, env, &i, stop))
			{
				printf("!!!!on pas dans le break qui est sencer tout arreter!!!\n");
				exit(0);
			}
		}
	}
	secure_line(line);
	return (1);
}

int	is_param(char *line)
{
	int	i;

	i = 0;
	pass_space(line, &i);
	if (line[i] == '\n')
		return (0);
	if ((line[i] == 'N' && line[i + 1] && line[i + 1] == 'O' && line[i + 2] && line[i + 2] == ' ') || \
		(line[i] == 'S' && line[i + 1] && line[i + 1] == 'O' && line[i + 2] && line[i + 2] == ' ') || \
		(line[i] == 'E' && line[i + 1] && line[i + 1] == 'A' && line[i + 2] && line[i + 2] == ' ') || \
		(line[i] == 'W' && line[i + 1] && line[i + 1] == 'E' && line[i + 2] && line[i + 2] == ' ') || \
		(line[i] == 'F' && line[i + 1] && line[i + 1] == ' ') || \
		(line[i] == 'C' && line[i + 1] && line[i + 1] == ' '))
		return (1);
	else
		return (0);
}