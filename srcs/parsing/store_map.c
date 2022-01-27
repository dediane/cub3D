/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:44:40 by ddecourt          #+#    #+#             */
/*   Updated: 2022/01/26 15:31:18 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/cub3D.h"

int	is_empty(char *s)
{
	int i;

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

int ft_store_map(char *path, t_env *env, int fd)
{
	char	*line;

	(void)path;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(ft_check_texture(&env->texture, line)))
			return (0);
		if (!(ft_check_valid_files(&env->texture)))
			return (0);
	}
	return (1);
}
