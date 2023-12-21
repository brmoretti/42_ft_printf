/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:50:35 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/21 03:47:04 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	null_string(t_flags *flags)
{
	char	*str;
	int		len;

	if (0 <= flags->dot && flags->dot <= 5)
		str = ft_strdup("");
	else
		str = ft_strdup("(null)");
	str = dash_flag(str, flags->dash);
	str = len_flag(str, flags->len);
	len = ft_putstr_len(str);
	free(str);
	free(flags);
	return (len);
}

static char	*string_limit(char *str, int limit)
{
	char	*new_str;
	int		i;

	if (!str)
		return (NULL);
	if ((0 <= limit) && (limit < (int)ft_strlen(str)))
	{
		new_str = ft_calloc(limit + 1, sizeof(char));
		if (!new_str)
			return (NULL);
		i = 0;
		while (limit--)
		{
			new_str[i] = str[i];
			i++;
		}
	}
	else
		return (str);
	free(str);
	return (new_str);
}

int	parse_string(char **token, char *str)
{
	t_flags	*flags;
	int		len;

	flags = get_flags(*token);
	free(*token);
	if (!flags)
		return (-1);
	if (!str)
		return (null_string(flags));
	str = ft_strdup(str);
	if (flags->dot >= 0)
		str = string_limit(str, flags->dot);
	str = dash_flag(str, flags->dash);
	str = len_flag(str, flags->len);
	len = ft_putstr_len(str);
	free(flags);
	free(str);
	return (len);
}
