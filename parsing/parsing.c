/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:21:31 by adecauch          #+#    #+#             */
/*   Updated: 2025/04/23 13:21:56 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "parsing.h"

int	number_line(char *file_name)
{
	int	i;
	int fd;

	i = 0;
	fd = open(file_name, O_RDONLY);
	while (get_next_line(fd))
		i++;
	close(fd);
	return (i);
}

char	**create_map(char *file_name)
{
	int		fd;
	int		nl;
	int		i;
	char	**map;

	i = 0;
	fd = open(file_name, O_RDONLY);
	nl = number_line(file_name);
	map = malloc((nl + 1) * sizeof(char *));
	while (i < nl)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	map_parsing(char **map)
{
	t_parse	parse = {0};
}

int main(void)
{
	char **map = create_map("test.txt");
	int i = 0;
	while(map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	return 0;
}
