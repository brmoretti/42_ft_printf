/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len_limit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:34:31 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/15 12:44:07 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr_len_limit(const char *s, int limit)
{
	unsigned int	i;

	if (!s)
		return (0);
	i = 0;
	if (limit >= 0)
	{
		while (s[i] && limit--)
			i++;
	}
	else
	{
		while (s[i])
			i++;
	}
	write(1, s, i);
	return (i);
}
