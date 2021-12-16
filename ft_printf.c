/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:43:38 by yeju              #+#    #+#             */
/*   Updated: 2021/06/23 19:00:50 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long			ft_get_value(t_tag *flag, va_list ap)
{
	if (flag->type & PERCENT)
		return (0);
	else if (flag->type & (STRING | POINTER))
		return ((long long)va_arg(ap, void *));
	else if (flag->type & (CHAR | DIGIT))
		return (va_arg(ap, int));
	else if (flag->type & (UDIGIT | HEXA | XHEXA))
		return (va_arg(ap, unsigned int));
	return (0);
}

int					ft_format_parse(char *format, va_list ap)
{
	int				value_len;
	t_tag			tag;

	value_len = 0;
	ft_bzero(&tag, sizeof(t_tag));
	while (*format)
	{
		if (*format == '%' && ft_setting_tag(&tag, &format, ap))
			value_len += ft_manage_print(&tag, ft_get_value(&tag, ap));
		else
			value_len += write(1, format++, 1);
	}
	return (value_len);
}

int					ft_printf(const char *format, ...)
{
	int				value_len;
	va_list			ap;

	va_start(ap, format);
	value_len = ft_format_parse((char *)format, ap);
	va_end(ap);
	return (value_len);
}
