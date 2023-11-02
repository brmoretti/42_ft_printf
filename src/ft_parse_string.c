/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:50:35 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/02 15:42:49 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_parse_string(char **token, char *str)
{
	int	i;

	free (*token);
	*token = malloc((ft_strlen((const char *)str) + 1) * sizeof(char));
	if (!*token)
		return (NULL);
	i = 0;
	while (str[i])
	{
		(*token)[i] = str[i];
		i++;
	}
	(*token)[i] = '\0';
	return (*token);
}
