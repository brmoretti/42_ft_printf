/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:33:13 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/02 15:41:56 by bmoretti         ###   ########.fr       */
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
