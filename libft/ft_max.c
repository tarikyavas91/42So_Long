/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavas <tyavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 04:13:23 by tyavas            #+#    #+#             */
/*   Updated: 2022/10/14 04:13:23 by tyavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max(int	*tab, int len)
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
			if (tab[len] >= tab[len2])
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
