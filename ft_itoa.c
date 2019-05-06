/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:41:25 by jwisozk           #+#    #+#             */
/*   Updated: 2018/12/16 13:39:13 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count(long n)
{
	int len;

	len = 1;
	if (n < 0)
		len = 2;
	while ((n /= 10) != 0)
		len++;
	return (len);
}

static	void	ft_putnbrs(long n, char *s)
{
	if (s != NULL)
	{
		if (n >= 10)
		{
			ft_putnbrs(n / 10, s);
		}
		s[ft_count(n) - 1] = n % 10 + '0';
	}
}

char			*ft_itoa(int n)
{
	int		len;
	long	num;
	char	*str;
	int		i;

	i = 0;
	num = n;
	len = ft_count(num);
	str = (char*)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[i] = '-';
		num *= -1;
		i = 1;
	}
	ft_putnbrs(num, &str[i]);
	str[len] = '\0';
	return (str);
}
