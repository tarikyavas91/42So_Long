/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavas <tyavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:36:19 by tyavas            #+#    #+#             */
/*   Updated: 2023/03/24 12:00:22 by tyavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_path(t_map *map)
{
	t_map	clone;

	ft_memcpy(&clone, map, sizeof(t_map));
	ft_move_around(&clone, clone.player[0], clone.player[1]);
	if (clone.collectible_status < map ->collectible_nbr || clone.ex_status)
	{
		ft_printf("Map does not have a valid path!\n");
		exit (1);
	}
}
