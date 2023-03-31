/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavas <tyavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 00:00:00 by yavas             #+#    #+#             */
/*   Updated: 2023/03/21 14:42:24 by tyavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	file_open(void)
{
	int	file;

	file = open("textures/collectible.xpm", O_RDONLY);
	if (file == -1)
		exit(0);
	file = open("textures/exit.xpm", O_RDONLY);
	if (file == -1)
		exit(0);
	file = open("textures/ground.xpm", O_RDONLY);
	if (file == -1)
		exit(0);
	file = open("textures/player.xpm", O_RDONLY);
	if (file == -1)
		exit(0);
	file = open("textures/wall.xpm", O_RDONLY);
	if (file == -1)
		exit(0);
}

int	main(int ac, char *argv[])
{
	t_map	map;
	t_mlx	obj;
	char	**map_src;

	file_open();
	map_src = ft_error_management (open (argv[1], O_RDONLY), ac, argv[1]);
	ft_get_map_data(&map, map_src);
	ft_check_path(&map);
	ft_put_map(&map, &obj);
	map.obj = &obj;
	ft_key_events(&map);
	mlx_loop(obj.mlx);
}
