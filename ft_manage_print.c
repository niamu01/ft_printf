/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:43:54 by yeju              #+#    #+#             */
/*   Updated: 2021/06/23 18:57:47 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	boxing_char(t_tag *tag, t_box *box)
{
	box->value_len = 1;
	if (tag->type & PERCENT)
		box->value = '%';
	if (tag->flag & 2 && !(tag->flag & 1))
		box->zero = tag->width - box->value_len;
}

static void	boxing_string(t_tag *tag, t_box *box)
{
	box->value_len = 6;
	if (box->value)
		box->value_len = ft_strlen((char *)box->value);
	if (tag->precision != -1 && tag->precision < box->value_len)
		box->value_len = tag->precision;
	if (tag->flag & 2 && !(tag->flag & 1))
		box->zero = tag->width - box->value_len;
}

static void	boxing_number(t_tag *tag, t_box *box)
{
	if (box->value < 0)
	{
		box->sign = '-';
		box->value = -box->value;
	}
	ft_memcpy(box->base, "0123456789", 10);
	box->base_len = 10;
	box->value_len = ft_get_number_len((t_ull)box->value, 10);
	if (tag->precision == 0 && box->value == 0)
		box->value_len = 0;
	if (tag->precision != -1)
		box->zero = tag->precision - box->value_len;
	else if (tag->flag & 2 && !(tag->flag & 1))
		box->zero = tag->width - box->value_len
			- (box->sign > 0) - (box->prefix > 0) * 2;
}

static void	boxing_hexa(t_tag *tag, t_box *box)
{
	char	*base;

	if (tag->type & POINTER)
		box->prefix = 'x';
	base = "0123456789abcdef";
	if (tag->type & XHEXA)
		base = "0123456789ABCDEF";
	ft_memcpy(box->base, base, 16);
	box->base_len = 16;
	box->value_len = ft_get_number_len((t_ull)box->value, 16);
	if (box->value == 0 && !(tag->type & POINTER))
		box->prefix = 0;
	if (tag->precision == 0 && box->value == 0)
		box->value_len = 0;
	if (tag->precision != -1)
		box->zero = tag->precision - box->value_len;
	else if (tag->flag & 2 && !(tag->flag & 1))
		box->zero = tag->width - box->value_len
			- (box->sign > 0) - (box->prefix > 0) * 2;
}

int			ft_manage_print(t_tag *tag, long long value)
{
	int		len;
	t_box	box;

	ft_bzero(&box, sizeof(t_box));
	box.value = value;
	if (tag->type & (PERCENT | CHAR))
		boxing_char(tag, &box);
	else if (tag->type & STRING)
		boxing_string(tag, &box);
	else if (tag->type & (DIGIT | UDIGIT))
		boxing_number(tag, &box);
	else if (tag->type & (HEXA | XHEXA | POINTER))
		boxing_hexa(tag, &box);
	len = box.value_len + ft_max(box.zero, 0)
		+ (box.sign > 0) + (box.prefix > 0) * 2;
	box.margin = ft_max(tag->width - len, 0);
	ft_lineup_box(tag, &box);
	return (box.margin + len);
}
