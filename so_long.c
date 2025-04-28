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
#include <stdlib.h>

#define WIN_W 800
#define WIN_H 600
#define FPS 60
#define SPEED 5

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int	bpp;
	int	line_len;
	int	endian;
	int	x;
	int	y;
	int	up;
	int	down;
	int	left;
	int	right;
} t_data;

static void draw_rect(t_data *d, int x, int y, int w, int h, int color)
{
	int i;
	int j;

	j = 0;
	while (j < h)
	{
		i = 0;
		while (i < w)
		{
			if (x + i >= 0 && x + i < WIN_W && y + j >= 0 && y + j < WIN_H)
				*(int *)(d->addr + ((y + j) * d->line_len + (x + i) * (d->bpp / 8))) = color;
			i++;
		}
		j++;
	}
}

static int render_next_frame(t_data *d)
{
	static useconds_t last;
	useconds_t now;

	now = last + 1000000 / FPS;
	if (last)
		usleep(now - last);
	last = now;

	if (d->up)
		d->y -= SPEED;
	if (d->down)
		d->y += SPEED;
	if (d->left)
		d->x -= SPEED;
	if (d->right)
		d->x += SPEED;

	draw_rect(d, 0, 0, WIN_W, WIN_H, 0x000000);
	draw_rect(d, d->x, d->y, 50, 50, 0xFF0000);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	return (0);
}

static int key_press(int keycode, t_data *d)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_W)
		d->up = 1;
	if (keycode == KEY_S)
		d->down = 1;
	if (keycode == KEY_A)
		d->left = 1;
	if (keycode == KEY_D)
		d->right = 1;
	return (0);
}

static int key_release(int keycode, t_data *d)
{
	if (keycode == KEY_W)
		d->up = 0;
	if (keycode == KEY_S)
		d->down = 0;
	if (keycode == KEY_A)
		d->left = 0;
	if (keycode == KEY_D)
		d->right = 0;
	return (0);
}

int main(void)
{
	t_data data;

	data.x = WIN_W / 2 - 25;
	data.y = WIN_H / 2 - 25;
	data.up = 0;
	data.down = 0;
	data.left = 0;
	data.right = 0;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_W, WIN_H, "so_long_test");
	data.img = mlx_new_image(data.mlx, WIN_W, WIN_H);
	data.addr = mlx_get_data_addr(data.img, &data.bpp,
		&data.line_len, &data.endian);

	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_loop(data.mlx);
	return (0);
}

