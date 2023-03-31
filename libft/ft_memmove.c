/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavas <tyavas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:40:25 by tyavas            #+#    #+#             */
/*   Updated: 2023/03/13 18:10:44 by tyavas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest == src || !n)
		return (dest);
	if (src < dest)
	{
		while (n--)
		{
			*((unsigned char *) dest + n) = *((unsigned char *) src + n);
		}
		return (dest);
	}
	else
	{
		while (n--)
		{
			*((unsigned char *) dest + i) = *((unsigned char *)src + i);
			i++;
		}
	}
	return (dest);
}
