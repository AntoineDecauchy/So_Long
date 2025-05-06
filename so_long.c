/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:29:32 by adecauch          #+#    #+#             */
/*   Updated: 2025/04/22 23:29:34 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	char	**map;
	t_image	image;

	(void)argc;
	map = create_parse_map(argv[1]);
	mlx = mlx_init();
	load_image(mlx, &image);
	win = mlx_new_window(mlx, 400, 400, "test");
	//for (int i = 0; i < 100; i++)
	//	mlx_pixel_put(mlx, win, i, i, 0x00FF0000);
	//for (int i = 100; i < 300; i++)
	//	mlx_pixel_put(mlx, win, i, i, 0x000000FF);
	//for (int i = 300; i < 400; i++)
	//	mlx_pixel_put(mlx, win, i, i, 0x0000FF00);
	//draw_square(mlx, win, 0, 0, 50, 0x00FF0000);
	//draw_square(mlx, win, 150, 150, 100, 0x000000FF);
	//draw_square(mlx, win, 350, 350, 50, 0x0000FF00);
	draw_map(mlx, win, map, image);
	(void)win;
	mlx_loop(mlx);
	free_map(map);
}
