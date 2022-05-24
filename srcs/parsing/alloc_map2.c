/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:26:13 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/05/24 14:53:39 by bben-yaa         ###   ########.fr       */
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
