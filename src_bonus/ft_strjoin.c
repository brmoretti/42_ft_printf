/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 08:20:17 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/08 15:50:59 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*joined;
	char	*origin;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc(len + 1);
	if (joined == NULL)
		return (NULL);
	origin = joined;
	while (*s1)
		*(joined++) = *(s1++);
	while (*s2)
		*(joined++) = *(s2++);
	*joined = '\0';
	return (origin);
}
