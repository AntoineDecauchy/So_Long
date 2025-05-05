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

void	flood_fill_rec(char **map, t_parse parse, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	map[x][y] = 'V';
	flood_fill_rec(map, parse, x + 1, y);
	flood_fill_rec(map, parse, x - 1, y);
	flood_fill_rec(map, parse, x, y + 1);
	flood_fill_rec(map, parse, x, y - 1);
}

void	flood_fill(char **map, t_parse parse)
{
	int	i;
	int	j;

	flood_fill_rec(map, parse, parse.start_x, parse.start_y);
	i = 0;
	while (i < parse.number_line)
	{
		j = 0;
		while (j < parse.size_line)
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				exit_parse("Error Map : Unreachable element\n", map);
			j++;
		}
		i++;
	}
}
