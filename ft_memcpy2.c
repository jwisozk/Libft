/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:13:09 by jwisozk           #+#    #+#             */
/*   Updated: 2018/12/16 15:40:15 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_memcpy2(void **dst, const void **src, size_t n)
{
	unsigned char	**d;
	unsigned char	**s;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = (unsigned char**)dst;
	s = (unsigned char**)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}
