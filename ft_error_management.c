/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavas <tyavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:13:47 by tyavas            #+#    #+#             */
/*   Updated: 2023/03/13 18:57:05 by tyavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	ft_check_fd_ac_ber(int fd, int ac, char *str)
{
	int	len;

	if (ac != 2)
	{
		ft_printf("AC Error\n");
		exit (1);
	}
	len = ft_strlen(str) - 1;
	if (fd < 0)
	{
		perror ("fd error");
		exit (1);
	}
	if (str[len] == 'r' && str[len - 1] == 'e'
		&& str[len - 2] == 'b' && str[len - 3] == '.')
		return ;
	else
	{
		ft_printf("Map is not a ber file!\n");
		exit (1);
	}
}

char	**ft_error_management(int fd, int ac, char *argv)
{
	char	**map;
	char	*str;
	int		i;

	i = 0;
	ft_check_fd_ac_ber(fd, ac, argv);
	map = (char **) malloc (sizeof(char *) * 1000);
	if (!map)
	{
		perror("malloc failure");
		exit (1);
	}
	str = get_next_line (fd);
	map[i++] = str;
	while (str)
	{
		str = get_next_line(fd);
		map[i++] = str;
	}
	ft_check_walls(map);
	ft_check_items(map);
	close (fd);
	return (map);
}
