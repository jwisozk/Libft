/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 23:15:35 by jwisozk           #+#    #+#             */
/*   Updated: 2018/12/16 16:43:53 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (s1 != NULL && s2 != NULL)
	{
		len = ft_strlen(s1);
		len += ft_strlen(s2);
		if (len + 1 == 0)
			return (NULL);
		str = ft_strnew(len);
		if (!str)
			return (NULL);
		while (*s1 != '\0')
			*str++ = *s1++;
		while (*s2 != '\0')
			*str++ = *s2++;
		*str = '\0';
		return (str - len);
	}
	return (NULL);
}
