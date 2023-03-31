/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavas <tyavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 01:20:43 by tyavas            #+#    #+#             */
/*   Updated: 2023/03/24 11:54:25 by tyavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	ft_exit(t_map *map, int status)
{
	free(map -> obj -> ext);
	free(map -> obj -> player);
	free(map -> obj -> space);
	free(map -> obj -> collectible);
	free(map -> obj -> wall);
	free(map -> obj -> mlx);
	free(map -> obj -> mlx_window);
	if (status)
		ft_printf("Congratulations! You Win!\n");
	exit (1);
}

int	ft_compare_locations(int x, int y, int arr[2048][1][2], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (x == arr[i][0][0] && y == arr[i][0][1])
			return (i);
		i++;
	}
	return (-1);
}

static	int	ft_action(int keycode, t_map *vars)
{
	if (keycode == D)
		ft_move_right(vars);
	if (keycode == A)
		ft_move_left(vars);
	if (keycode == S)
		ft_move_down(vars);
	if (keycode == W)
		ft_move_up(vars);
	if (keycode == ESC)
		ft_exit(vars, 0);
	if (vars -> collectible_status == vars -> collectible_nbr)
		mlx_put_image_to_window(vars -> obj -> mlx, vars -> obj -> mlx_window,
			vars -> obj -> ext, vars -> ex[0], vars -> ex[1]);
	return (0);
}

static	int	ft_close(void)
{
	exit(0);
}

void	ft_key_events(t_map *map)
{
	mlx_hook(map -> obj -> mlx_window, 17, 0, ft_close, map);
	mlx_hook(map -> obj -> mlx_window, 2, 1L << 0, ft_action, map);
}
