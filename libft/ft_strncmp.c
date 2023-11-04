/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:41:42 by bmoretti          #+#    #+#             */
/*   Updated: 2023/10/17 15:43:53 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while ((*s1 || *s2) && (n-- > 0))
	{
		if (*(s1++) != *(s2++))
			return (*(unsigned char *)(--s1) - *(unsigned char *)(--s2));
	}
	return (0);
}
