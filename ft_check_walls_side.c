/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls_side.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavas <tyavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 01:01:07 by tyavas            #+#    #+#             */
/*   Updated: 2023/03/24 11:54:29 by tyavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_side_walls(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map [0][j] != '\n')
		j++;
	j--;
	while (map[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (map[i][0] != '1' || map[i][j] != '1')
		{
			ft_printf("Side Wall Error\n");
			exit(1);
		}
		i--;
	}
}

static	void	ft_check_side_walls_3(char **map, int x_column, int y_line)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (map[i] && i <= x_column -1)
	{
		j = 0;
		while (map [i][j] != '\n')
			j++;
		if (y_line != j)
		{
			ft_printf("Side Wall Intermediate Place Error\n");
			exit(0);
		}		
		i++;
	}
}

void	ft_check_side_walls_2(char **map)
{
	int	i;
	int	j;
	int	y_line;
	int	x_column;

	i = 0;
	j = 0;
	y_line = 0;
	x_column = 0;
	while (map[0][y_line] != '\n')
		y_line++;
	while (map[x_column])
		x_column++;
	x_column--;
	while (map [x_column][j] != 0)
		j++;
	if (y_line != j)
	{
		ft_printf("Side Wall Bottom or Top Error\n");
		exit(0);
	}
	ft_check_side_walls_3(map, x_column, y_line);
}
