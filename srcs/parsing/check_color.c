/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:16:34 by bben-yaa          #+#    #+#             */
/*   Updated: 2022/05/09 18:46:18 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	is_num(char *line)
{
	int	i;
	int j;
	int	num;

	i = 0;
	j = 0;
	pass_space(line, &i);
	if (line[i] == 'F' || line[i] == 'C')
		i++;
	pass_space(line, &i);
	if (line[i] == ',')
		return (0);
	while(line[i] && j <= 2)
	{
		pass_space(line, &i);
		if (line[i] >= '0' && line[i] <= '9')
		{
			while(line[i] && line[i] >= '0' && line[i] <= '9')
				i++;
			j++;
			num++;
		}
		else if ((line[i] == ',' || line[i] == '\n') && num == 1)
		{
			i++;
			num = 0;
		}
		else
			return (0);
		if (num == 2)
			return(0);
	}
	if (j < 3)
		return (0);
	printf("goOOOOOOOOOODDDD\n");
	return (1);
}

unsigned int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}