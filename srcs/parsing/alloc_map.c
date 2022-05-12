/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:21:11 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/05/12 18:44:59 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	open_map(t_env *env, int fd)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = gnl(fd);
		if (!line)
			break ;
		else if (is_param(line))
			secure_line(line);
		else
		{
			if (empty_line(line))
				secure_line(line);
			else
			{
				printf("Alloue map gooo\n");
				return (alloc_map(env, fd, line));
			}
		}
	}
	return (1);
}

int	alloc_map(t_env *env, int fd, char *line)
{
	int		j;

	j = 0;
	env->map = malloc(sizeof(char *) * (env->height + 1));
	if (env->map == NULL)
		return (error_message("malloc fail", 0));
	printf("height vaut %d\n", env->height);
	printf("!!!!!!!!!!j'alloue la **map!!!!!!!!!!!\n");
	while (j < env->height)
	{
		if (j != 0)
			line = gnl(fd);
		if (!line)
			break ;
		else
		{
			env->map[j] = malloc(sizeof(char) * (env->width + 1));
			if (env->map[j] == NULL)
				return (error_message("malloc fail", 0));
			printf("j'alloue #####map[%d]#######\n", j);
			printf("j'alloue %d de place\n", env->width + 1);
			copy_line(line, env, env->map[j]);
			printf("pour line %s map[%d] = %s\n", line, j, env->map[j]);
			secure_line(line);
			j++;
		}
	}
	printf("here before le caca\n");
	env->map[j] = NULL; //derniere liste
	return (1);
}

int		ft_len(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

void	copy_line(char *line, t_env *env, char *map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_len(line);
	printf("len vaut %d\n", len);
	printf("width vaut %d\n", env->width);
	printf("height vaut %d\n", env->height);
	printf("line vaut %s", line);
	while (i < env->width)
	{
	//	printf("i is %i and env->width is %i\n", i, env->width);
	//	printf("line[%d] = -%c-\n", i, line[i]);
	//	printf("%s\n", line);
		if (i == 32)
			printf("------%c-------\n",line[i]);
		if (len < i)
		{
			printf("ici pour i vaut %d\n", i);
			if (!line[i])
				printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
			while (i < env->width)
			{
				map[i] = '1';
				i++;
			}
			break ;
		}
		if (!line[i])
		{
			printf("IT IS NULL");
			while (i < env->width - 1)
			{
				map[i] = '1';
				i++;
			}
			map[i] = '\0';
			// break ;
		}
		else if (line[i] && line[i] == '\n')
		{
			printf("Quand c'est un backslash n\n");
			while (i < env->width)
			{
				map[i] = '1';
				i++;
			}
			printf("vient dans le break\n");
			break;
		}
		else if (line[i] == ' ')
		{
			printf("here pour i vaut %d\n", i);
			map[i] = '1';
		}
		else
		{
			printf("hnaa pour i vaut %d\n", i);
			if (line[i])
				map[i] = line[i];
		}
		i++;
	}
	printf("ici avant le deuxieme caca i vsut 33 normalement et il vaut %d\n", i);
	map[i] = '\0';
	printf("a la fin map vaut %s\n", map);
	printf("len map vaut %d\n", ft_strlen(map));
}