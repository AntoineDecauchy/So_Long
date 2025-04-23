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

#include "so_long.h"

int	number_line(int fd)
{
	int	i;

	i = 0;
	while (get_next_line(fd))
		i++;
	return (i);
}

char	**create_map(char *file_name)
{
	int		fd;
	int		fd2;
	int		nl;
	int		i;
	char	**map;

	i = 0;
	fd = open(file_name, O_RDONLY);
	fd2 = open(file_name, O_RDONLY);
	nl = number_line(fd);
	map = malloc((nl + 1) * sizeof(char *));
	while (i < nl)
	{
		map[i] = get_next_line(fd2);
		i++;
	}
	map[i] = NULL;
	close(fd);
	close(fd2);
	return (map);
}

//void	map_parsing(char **map)

int main(void)
{
	char **map = create_map("test.txt");
	int i = 0;
	printf("%s", map[0]);
	//while(map[i])
	//{
	//	printf("%s", map[i]);
	//	i++;
	//}
	return 0;
}
