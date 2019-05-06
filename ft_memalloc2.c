/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:12:23 by jwisozk           #+#    #+#             */
/*   Updated: 2018/12/17 12:53:01 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_memalloc2(size_t size)
{
	unsigned char	**s;

	if (size + 1 == 0)
		return (NULL);
	s = (unsigned char**)malloc(sizeof(*s) * size);
	if (!s)
		return (NULL);
	ft_bzero2((void**)s, size);
	return ((void**)s);
}
