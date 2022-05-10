/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_params_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:50:33 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/05/10 11:38:46 by bben-yaa         ###   ########.fr       */
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

void	pass_space(char *line, int *i)
{
	while(line[*i] && (line[*i] == ' ' || line[(*i)] == '\t'))
		(*i)++;
}

void    finish_line(char *line, int *i)
{
	while(line[*i])
		(*i)++;
}
