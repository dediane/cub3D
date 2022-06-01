/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:44:40 by ddecourt          #+#    #+#             */
/*   Updated: 2022/06/01 12:12:11 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	is_empty(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '\n' && !(s[1]))
		return (1);
	while (s[i])
		if ((ft_isprint(s[i])))
			i++;
	if (i == ft_strlen(s))
		return (1);
	else
		return (0);
}

int	in_map(char *line, int i)
{
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0' || \
			line[i] == ' ' || line[i] == 'N' || \
			line[i] == 'S' || line[i] == 'E' || \
			line[i] == 'W' || line[i] == '\n')
			i++;
		else
			return (error_message("There's a bad char present in map", 0));
	}
	return (1);
}

int	is_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		pass_space(line, &i);
		if (line[i] == '\n')
			return (1);
		else if (line[i] == '1')
			return (in_map(line, i));
		else
			return (error_message("There's a bad char present in file", 0));
		i++;
	}
	return (1);
}

int	is_param(char *line)
{
	int	i;

	i = 0;
	pass_space(line, &i);
	if (line[i] == '\n')
		return (0);
	if ((line[i] == 'N' && line[i + 1] && line[i + 1] == 'O'\
		&& line[i + 2] && line[i + 2] == ' ') || \
		(line[i] == 'S' && line[i + 1] && line[i + 1] == 'O'\
		&& line[i + 2] && line[i + 2] == ' ') || \
		(line[i] == 'E' && line[i + 1] && line[i + 1] == 'A'\
		&& line[i + 2] && line[i + 2] == ' ') || \
		(line[i] == 'W' && line[i + 1] && line[i + 1] == 'E'\
		&& line[i + 2] && line[i + 2] == ' ') || \
		(line[i] == 'F' && line[i + 1] && line[i + 1] == ' ') || \
		(line[i] == 'C' && line[i + 1] && line[i + 1] == ' '))
		return (1);
	else
		return (0);
}
