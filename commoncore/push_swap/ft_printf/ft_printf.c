/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titan <titan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:10:55 by titan             #+#    #+#             */
/*   Updated: 2024/05/02 12:54:17 by titan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	valid_flags(char c)
{
	if (ft_strchr(CS_FLAGS, c))
		return (1);
	return (0);
}

static int	get_flags_index(char c)
{
	const char	*flags;
	int			count;

	flags = CS_FLAGS;
	count = 0;
	while (*flags)
	{
		if (*flags == c)
			return (count);
		count++;
		flags++;
	}
	return (-1);
}

static int	ft_parse(char c, va_list *va_ptr, int fd)
{
	int						flags_index;
	static const t_parsers	parse_table[] = {
		ft_parse_c,
		ft_parse_s,
		ft_parse_p,
		ft_parse_d,
		ft_parse_i,
		ft_parse_u,
		ft_parse_x,
		ft_parse_ux,
		ft_parse_percent
	};

	flags_index = get_flags_index(c);
	if (flags_index != -1)
		return (parse_table[flags_index](va_ptr, fd));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	va_ptr;
	int		char_printed;

	char_printed = 0;
	va_start(va_ptr, input);
	while (*input)
	{
		if (*input == '%')
		{
			if (valid_flags(input[1]))
			{
				char_printed += ft_parse(input[1], &va_ptr, STDIN_FILENO);
				input++;
			}
		}
		else
		{
			ft_putchar_fd(*input, 1);
			char_printed++;
		}
		input++;
	}
	va_end(va_ptr);
	return (char_printed);
}

int	ft_printf_err(const char *input, ...)
{
	va_list	va_ptr;
	int		char_printed;

	char_printed = 0;
	va_start(va_ptr, input);
	while (*input)
	{
		if (*input == '%')
		{
			if (valid_flags(input[1]))
			{
				char_printed += ft_parse(input[1], &va_ptr, STDERR_FILENO);
				input++;
			}
		}
		else
		{
			ft_putchar_fd(*input, 2);
			char_printed++;
		}
		input++;
	}
	va_end(va_ptr);
	return (char_printed);
}
