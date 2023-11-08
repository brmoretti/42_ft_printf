/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:11:41 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/08 15:50:49 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_is_in_conversion_set(const char c)
{
	char	*set;
	char	*mover;
	int		is_in;

	set = ft_strdup("cspdiuxX%");
	if (!set)
		return (-1);
	mover = set;
	is_in = 0;
	while (*mover)
	{
		if (*(mover++) == c)
		{
			is_in = 1;
			break ;
		}
	}
	free(set);
	return (is_in);
}

static unsigned int	ft_count_tokens(const char *s)
{
	unsigned int	count;

	count = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			while (*s && !ft_is_in_conversion_set(*s))
				s++;
			if (*s)
				s++;
		}
		else
		{
			while (*s && *s != '%')
				s++;
		}
		count++;
	}
	return (count);
}

static char	*ft_split_malloc(const char *start)
{
	unsigned int	i;
	char			*mem;

	i = 0;
	if (start[i] && start[i] == '%')
	{
		i++;
		while (start[i] && !ft_is_in_conversion_set(start[i]))
			i++;
		if (start[i])
			i++;
	}
	else if (start[i++])
	{
		while (start[i] && start[i] != '%')
			i++;
	}
	mem = malloc(i + 1);
	return (mem);
}

static char	*ft_copy_split_printf(char *dest, const char *src)
{
	if (src && *src == '%')
	{
		*(dest++) = *(src++);
		while (*src && !ft_is_in_conversion_set(*src))
			*(dest++) = *(src++);
		if (*src)
			*(dest++) = *(src++);
	}
	else if (src)
	{
		while (*src && *src != '%')
			*(dest++) = *(src++);
	}
	*dest = '\0';
	return ((char *)src);
}

char	**ft_split_printf(const char *s)
{
	char			**tab;
	char			*mover;
	unsigned int	i;
	unsigned int	n_tokens;

	if (!s)
		return (NULL);
	n_tokens = ft_count_tokens(s);
	tab = ft_calloc((size_t)n_tokens + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	mover = (char *)s;
	i = -1;
	while (++i < n_tokens)
	{
		tab[i] = ft_split_malloc(mover);
		if (tab[i] == NULL)
			return (ft_clear_tab(tab));
		mover = ft_copy_split_printf(tab[i], mover);
	}
	return (tab);
}
