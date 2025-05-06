/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adecauch <adecauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 01:00:50 by adecauch          #+#    #+#             */
/*   Updated: 2025/05/06 03:08:55 by adecauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_square(void *mlx, void *win, int x, int y, int side, int color)
{
	int i;
	int	j;

	i = 0;
	while (i < side)
	{
		j = 0;
		while (j < side)
		{
			mlx_pixel_put(mlx, win, x+j, y+i, color);
			j++;
		}
		i++;
	}
}

void	draw_item(void *mlx, void *win, char c, int x, int y, t_image image)
{
	if (c == '1' || c == 'P')
		mlx_put_image_to_window(mlx, win, image.wall, x, y);
	else if (c == '0')
		mlx_put_image_to_window(mlx, win, image.floor, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(mlx, win, image.collectible, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(mlx, win, image.exit, x, y);
}

void	load_image(void *mlx, t_image *image)
{
	int	raf;

	raf = 0;
	image->wall = mlx_xpm_file_to_image(mlx, "../xpm/wall.xpm", &raf, &raf);
	image->floor = mlx_xpm_file_to_image(mlx, "../xpm/floor.xpm", &raf, &raf);
	image->exit = mlx_xpm_file_to_image(mlx, "../xpm/exit.xpm", &raf, &raf);
	image->collectible = mlx_xpm_file_to_image(mlx, "../xpm/collectible.xpm", &raf, &raf);
}
void	draw_map(void *mlx, void *win, char **map, t_image image)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = 0;
	y = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			draw_item(mlx, win, map[i][j], x, y, image);
			j++;
			x += 16;
		}
		x = 0;
		y += 16;
		i++;
	}
}
