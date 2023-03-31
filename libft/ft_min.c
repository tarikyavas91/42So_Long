/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavas <tyavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:39:53 by tyavas            #+#    #+#             */
/*   Updated: 2023/03/13 18:58:28 by tyavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_min(int *tab, int len)
{
	int	index;
	int	len2;
	int	total;

	total = len;
	len--;
	index = 0;
	len2 = len;
	while (len >= 0)
	{
		while (len2 >= 0)
		{
			if (tab[len] <= tab[len2])
				index++;
			if (index == total)
				return (tab[len]);
			len2--;
		}
		len2 = total - 1;
		len--;
		index = 0;
	}
	return (0);
}
