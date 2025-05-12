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

void	init_game(t_game *g, char *map_file)
{
	g->map = create_parse_map(map_file, &g->x_map, &g->y_map);
	g->mlx = mlx_init();
	load_image(g->mlx, &g->image);
	g->win = mlx_new_window(g->mlx, g->x_map * 64, g->y_map * 64, "So Long");
	g->moves = 0;
	g->collectibles = 0;
	g->player_x = 0;
	g->player_y = 0;
}

void	find_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			if (game->map[i][j] == 'C')
				game->collectibles++;
			j++;
		}
		i++;
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	int	x;
	int	y;

	x = game->player_x + dx;
	y = game->player_y + dy;
	if (game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == 'C')
		game->collectibles--;
	if (game->map[y][x] == 'E' && game->collectibles == 0)
	{
		free_map(game->map);
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	game->map[game->player_y][game->player_x] = '0';
	game->map[y][x] = 'P';
	game->player_x = x;
	game->player_y = y;
	game->moves++;
	draw_map(game->mlx, game->win, game->map, game->image);
}

static int	handle_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		free_map(game->map);
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, 0, 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, 1, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argc;
	init_game(&game, argv[1]);
	find_player(&game);
	draw_map(game.mlx, game.win, game.map, game.image);
	mlx_hook(game.win, 2, 1L<<0, handle_key, &game);
	mlx_loop(game.mlx);
	return (0);
}
