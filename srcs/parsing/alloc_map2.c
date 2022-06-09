/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:26:13 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/06/09 18:29:43 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	malloc_fail(char *line)
{
	secure_line(line);
	return (error_message("Malloc fail", 0));
}

void	ft_copy(int *i, t_env *env, char *map)
{
	while ((*i) < env->width)
	{
		map[(*i)] = ' ';
		(*i)++;
	}
}

int	error_message(char *str, int ret)
{
	printf("Error: %s\n", str);
	return (ret);
}

int	ft_check_end(char *map)
{
	int	len;

	len = ft_strlen(map);
	len -= 1;
	if (map[len] == '1')
		return (1);
	else
	{
		while (len > 0 && map[len] == ' ')
			len--;
		if (map[len] == '1')
			return (1);
		else
			return (0);
	}
	return (0);
}
