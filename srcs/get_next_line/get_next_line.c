/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:31:24 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/05/10 12:40:48 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	ft_strclen(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	if (c == '\0')
	{
		while (str[i])
			i++;
		return (i);
	}
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strndu(char *str, int n)
{
	char	*ret;
	int		i;

	i = 0;
	while (str[i] && i < n)
		i++;
	ret = malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i] && i < n)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoi(char *s1, char *s2)
{
	char	*ret;
	int		size;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	size = ft_strclen(s1, '\0') + ft_strclen(s2, '\0') + 1;
	ret = malloc(sizeof(char) * size);
	if (!ret)
	{
		free(s1);
		return (NULL);
	}
	ret = copy(s1, &i, ret);
	while (s2[y])
	{
		ret[i + y] = s2[y];
		y++;
	}
	ret[i + y] = '\0';
	free(s1);
	return (ret);
}

char	*ft_ret_str(char **ret_str)
{
	char	*line;
	char	*tmp;
	int		position;

	position = ft_strclen(*ret_str, '\n');
	line = NULL;
	if (position != -1)
	{
		line = ft_strndu(*ret_str, position + 1);
		tmp = *ret_str;
		*ret_str = ft_strndu(*ret_str + position + 1,
				ft_strclen(*ret_str + position + 1, '\0'));
		free(tmp);
	}
	else if (*ret_str)
	{
		line = ft_strndup(*ret_str, ft_strclen(*ret_str, '\0'));
		free(*ret_str);
		*ret_str = NULL;
	}
	return (line);
}

char	*gnl(int fd)
{
	static char		*ret_str;
	char			buff[5 + 1];
	int				ret;


	while (ft_strclen(ret_str, '\n') == -1)
	{
		ret = read(fd, &buff, 5);
		if (ret <= 0)
			break ;
		buff[ret] = '\0';
		if (!ret_str)
			ret_str = ft_strndu(buff, ft_strclen(buff, '\0'));
		else
			ret_str = ft_strjoi(ret_str, buff);
	}
	return (ft_ret_str(&ret_str));
}
