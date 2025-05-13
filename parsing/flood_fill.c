/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 05:45:58 by adecauch          #+#    #+#             */
/*   Updated: 2025/05/05 05:45:59 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../so_long.h"

void	flood_fill_rec(char **map, t_parse parse, int x, int y)
{
	if (x >= (parse.size_line - 2) || y >= (parse.number_line - 1))
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill_rec(map, parse, x + 1, y);
	flood_fill_rec(map, parse, x - 1, y);
	flood_fill_rec(map, parse, x, y + 1);
	flood_fill_rec(map, parse, x, y - 1);
}

char	flood_fill(char **map, t_parse parse)
{
	int	i;
	int	j;

	flood_fill_rec(map, parse, parse.start_x, parse.start_y);
	i = 0;
	while (i < parse.number_line - 1)
	{
		j = 0;
		while (j < parse.size_line - 2)
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
