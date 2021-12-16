/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setting_tag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:44:13 by yeju              #+#    #+#             */
/*   Updated: 2021/06/23 18:58:10 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_num(char **format, va_list ap)
{
	int	ret;

	ret = 0;
	if (**format == '*')
	{
		(*format)++;
		return (va_arg(ap, int));
	}
	while ('0' <= **format && **format <= '9')
		ret = ret * 10 + *((*format)++) - '0';
	return (ret);
}

static int	parse_type(char **format, char *charset)
{
	int		ret;
	char	*ptr;

	ret = 0;
	if (**format && (ptr = ft_strchr(charset, **format)))
	{
		ret |= 1 << (ptr - charset);
		(*format)++;
	}
	return (ret);
}

static int	parse_flag(char **format, char *find)
{
	int		ret;
	char	*ptr;

	ret = 0;
	while (**format && (ptr = ft_strchr(find, **format)))
	{
		ret |= 1 << (ptr - find);
		(*format)++;
	}
	return (ret);
}

int			ft_setting_tag(t_tag *tag, char **format, va_list ap)
{
	char	*ptr;

	ptr = ++(*format);
	tag->flag = parse_flag(&ptr, "-0");
	if ((tag->width = get_num(&ptr, ap)) < 0)
	{
		tag->width *= -1;
		tag->flag |= 1;
	}
	tag->precision = -1;
	if (parse_flag(&ptr, "."))
		if ((tag->precision = get_num(&ptr, ap)) < 0)
			tag->precision = -1;
	if ((tag->type = parse_type(&ptr, "%cspdiuxX")))
		*format = ptr;
	return (tag->type);
}
