/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:29:32 by adecauch          #+#    #+#             */
/*   Updated: 2025/05/06 09:11:09 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	char	**map;
	t_image	image;
	t_map	map_size;

	(void)argc;
	map = create_parse_map(argv[1], &map_size.x_size, &map_size.y_size);
	mlx = mlx_init();
	load_image(mlx, &image);
	win = mlx_new_window(mlx, map_size.x_size * 64, map_size.y_size * 64, "test");
	draw_map(mlx, win, map, image);
	mlx_loop(mlx);
	free_map(map);
}
