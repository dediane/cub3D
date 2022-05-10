/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:00:58 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/05/10 12:38:37 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	recup_col(char *line, int i)
{
	char	*buf;
	int		y;
	int		j;
	int		len;

	y = 0;
	j = i;
	len = 0;
	while((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
	{
		i++;
		len++;
	}
	buf = ft_strndup(&line[j], len);
	y = ft_check_int(buf);
	free(buf);
	return (y);
}

void	store_rgb(int ret, int col, t_rgb *couleur)
{
	if (col == 0)
		couleur->r = ret;
	else if (col == 1)
		couleur->g = ret;
	else if (col == 2)
		couleur->b = ret;
}


void	ft_check(const char *str, int *i, int *k, int *sign)
{
	while (str[(*i)] == '\t' || str[(*i)] == '\n' || str[(*i)] == '\v'
		|| str[(*i)] == '\f' || str[(*i)] == '\r' || str[(*i)] == ' ')
		(*i)++;
	while (str[(*i)] == '-')
	{
		(*sign) = -(*sign);
		(*k)++;
		(*i)++;
	}
}

void	ft_maxmin(long int *n)
{
	if ((*n) > 255)
	{
		printf("The number : %ld overtake the max of rgb value \n \
		so we fixed at the value at 255\n", (*n));
		(*n) = 255;
	}
	if ((*n) < 0)
	{
		printf("The number : %ld overtake the min of rgb value \n \
		so we fixed at the value at 0\n", (*n));
		(*n) = 0;
	}
}

int	ft_check_int(char *str)
{
	long int	n;
	int			sign;
	int			k;
	int			i;

	n = 0;
	k = 0;
	sign = 1;
	i = 0;
	ft_check(str, &i, &k, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	n = n * sign;
	ft_maxmin(&n);
	return (n);
}
