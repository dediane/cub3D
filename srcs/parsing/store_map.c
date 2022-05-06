/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:44:40 by ddecourt          #+#    #+#             */
/*   Updated: 2022/05/05 16:00:58 by bben-yaa         ###   ########.fr       */
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
	int		flag;
	int		height;
	
	flag = 0;
	height = 0;
	(void)path;
	while (get_next_line(fd, &line) > 0)
	{
		if (flag < 4)
		{
			if (ft_check_texture(&env->texture, line))
				flag++;
		}
		if (flag == 4)
		{
			load_all_textures(env);
			flag++;
		}
		if (flag > 4)
		{
			if (!(is_empty(line)))
				height++;
			else
				flag++;
		}
	}
	return (1);
}
