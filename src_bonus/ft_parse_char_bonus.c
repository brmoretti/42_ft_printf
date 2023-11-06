/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:33:13 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/05 16:38:58 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_parse_char(char **token, int c)
{
	free (*token);
	*token = malloc(2 * sizeof(char));
	if (!*token)
		return (NULL);
	(*token)[0] = (char)c;
	(*token)[1] = '\0';
	return (*token);
}
