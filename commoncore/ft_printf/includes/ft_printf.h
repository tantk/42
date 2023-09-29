/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 00:25:19 by titan             #+#    #+#             */
/*   Updated: 2023/09/30 05:21:43 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# define CS_LOWER_HEX	"0123456789abcdef"
# define CS_UPPER_HEX	"0123456789ABCDEF"
# define CS_FLAGS "cspdiuxX%"

typedef int	(*t_parsers)(va_list *va_ptr);
int	print_hex(unsigned long long values, const char *hex_char);
int	ft_parse_c(va_list *va_ptr);
int	ft_parse_s(va_list *va_ptr);
int	ft_parse_p(va_list *va_ptr);
int	ft_parse_d(va_list *va_ptr);
int	ft_parse_i(va_list *va_ptr);
int	ft_parse_u(va_list *va_ptr);
int	ft_parse_x(va_list *va_ptr);
int	ft_parse_ux(va_list *va_ptr);
int	ft_parse_percent(va_list *va_ptr);
int	ft_printf(const char *input, ...) __attribute__((format(printf, 1, 2)));
#endif
