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

#define GBA_WIDTH 240
#define GBA_HEIGHT 160
#define SCALE 4
#define WINDOW_WIDTH  (GBA_WIDTH * SCALE)
#define WINDOW_HEIGHT (GBA_HEIGHT * SCALE)

static int  key_hook(int keycode, void *param)
{
    (void)param;
    if (keycode == 53)
        exit(EXIT_SUCCESS);
    return (0);
}

int main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (!mlx)
		return EXIT_FAILURE;
	win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "So_Long");
	if (!win)
		return 1;

	// Dessin d'un damier noir/blanc 1 pixel logique = SCALE² pixels réels
	for (int ly = 0; ly < GBA_HEIGHT; ly++){
		for (int lx = 0; lx < GBA_WIDTH; lx++) {
			int color = ((lx + ly) & 1) ? 0x00FFFFFF : 0x00000000;
			for (int dy = 0; dy < SCALE; dy++)
				for (int dx = 0; dx < SCALE; dx++)
					mlx_pixel_put(mlx, win,
								  lx * SCALE + dx,
								  ly * SCALE + dy,
								  color);
		}
	}
    // Hook pour la touche ESC
    mlx_key_hook(win, key_hook, NULL);

    mlx_loop(mlx);
    return EXIT_SUCCESS;
}
