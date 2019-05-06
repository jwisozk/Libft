/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:00:11 by jwisozk           #+#    #+#             */
/*   Updated: 2018/12/18 16:47:44 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_assets	ft_create_assets(void)
{
	t_assets tmp;

	tmp.count = 1;
	tmp.len = 0;
	tmp.i = 0;
	tmp.start = 0;
	return (tmp);
}

static t_assets	ft_get_len_start(t_assets t, const char *s, char c)
{
	while (s[t.i] == c && s[t.i] != '\0')
		t.i++;
	t.start = t.i;
	while (s[t.i] != c && s[t.i] != '\0')
		t.i++;
	t.len = t.i - t.start;
	return (t);
}

static char		**ft_create_copy_ptr(char **s, char **t, size_t count)
{
	s = (char**)ft_memalloc2(count + 1);
	if (!s)
		return (NULL);
	if (count > 1)
		ft_memcpy2((void**)s, (const void**)t, count - 1);
	return (s);
}

static char		**ft_check_return(char **str)
{
	if (str == NULL)
	{
		if (!(str = (char**)ft_memalloc2(1)))
			return (NULL);
		str[0] = NULL;
	}
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**str;
	char		**tmp;
	t_assets	t;

	t = ft_create_assets();
	str = NULL;
	tmp = NULL;
	while (s != NULL && s[t.i] != '\0')
	{
		t = ft_get_len_start(t, s, c);
		if (t.len == 0)
			break ;
		if (!(str = ft_create_copy_ptr(str, tmp, t.count)) ||
			!(str[t.count - 1] = ft_strsub(s, t.start, t.len)))
		{
			ft_free_all((void**)tmp);
			return (NULL);
		}
		free(tmp);
		tmp = str;
		t.count++;
	}
	return (ft_check_return(str));
}
