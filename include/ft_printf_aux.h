/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:23:14 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/30 15:26:35 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_AUX_H
# define FT_PRINTF_AUX_H

# include "ft_printf.h"

typedef struct s_flags
{
	int	len;
	int	dash;
	int	zero;
	int	dot;
	int	hash;
	int	space;
	int	plus;
}	t_flags;

enum	e_case
{
	lowercase,
	uppercase
};

char	*ft_itoa_base_case(int n, int base, int hexcase);
char	*ft_utoa_base_case(unsigned int n, int base, int hexcase);
char	*ft_ultoa_base_case(unsigned long n, int base, int hexcase);
char	**ft_clear_tab(char **tab);
char	**ft_split_printf(const char *s);
char	ft_last_char(const char *str);
int		ft_putstr_len(const char *s);

int		parse_char(char **token, int c);
int		parse_int(char **token, int n);
int		parse_ptr(char **token, unsigned long ptr);
int		parse_string(char **token, char *str);
int		parse_uint(char **token, unsigned int n, char conversion);
int		parse_perc(char **token);

t_flags	*get_flags(const char *s);
char	*dash_flag(char *str, int dash_len);
char	*len_flag(char *str, int len_flag);
char	*zero_flag_int(char *str, int zeros, size_t len_nb);
char	*zero_flag_uint(int zeros, char *str);
char	*precision_int(int n, int precision, char *str, size_t len_nb);
char	*precision_uint(unsigned int n, int precision, char *str);

#endif