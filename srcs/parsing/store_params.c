/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:24:34 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/05/10 12:26:30 by bben-yaa         ###   ########.fr       */
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
		return ((*stop) = 42, 0);
	finish_line(line, len);
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
			break ;
		if (is_param(line))
		{
			(*nb_line)++;
			if (!read_line(line, env, stop))
				break ;
		}
		else
			secure_line(line);
	}
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
				return (secure_line(line), 0);
		}
		else if (line[i] == 'F' || line[i] == 'C')
		{
			if (!pass_col(line, env, &i, stop))
				return (secure_line(line), 0);
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
	if ((line[i] == 'N' && line[i + 1] && line[i + 1] == 'O') || \
		(line[i] == 'S' && line[i + 1] && line[i + 1] == 'O') || \
		(line[i] == 'E' && line[i + 1] && line[i + 1] == 'A') || \
		(line[i] == 'W' && line[i + 1] && line[i + 1] == 'E') || \
		(line[i] == 'F' && line[i + 1] && line[i + 1] == ' ') || \
		(line[i] == 'C' && line[i + 1] && line[i + 1] == ' '))
		return (1);
	else
		return (0);
}
//&& line[i + 2] && line[i + 2] == ' '