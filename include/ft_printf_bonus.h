/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:24:33 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/05 21:54:06 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);

char	*ft_itoa_base_int(int n, int base, int upper);
char	*ft_itoa_base_uint(unsigned int n, int base, int upper);
char	*ft_itoa_base_ulong(unsigned long n, int base, int upper);
char	**ft_clear_tab(char **tab);
char	**ft_split_printf(const char *s);
char	ft_last_char(char *str);

char	*ft_parse_char(char **token, int c);
char	*ft_parse_int(char **token, int n);
char	*ft_parse_ptr(char **token, unsigned long ptr);
char	*ft_parse_string(char **token, char *str);
char	*ft_parse_uint(char **token, unsigned int n, char conversion);

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                                 BONUS
*/

typedef struct s_flags
{
	int	dash;
	int	zero;
	int	dot;
	int	hash;
	int	space;
	int	plus;
}	t_flags;

t_flags	*ft_get_flags(const char *token);
char	*ft_conversion_hex(unsigned int n,
	char conversion, const t_flags *flags)

#endif
