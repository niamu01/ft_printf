/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:44:26 by yeju              #+#    #+#             */
/*   Updated: 2021/06/23 19:00:19 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_char(char c, int len)
{
	while (len-- > 0)
		write(1, &c, 1);
}

static void		print_string(char *str, int len)
{
	if (str == 0)
		write(1, "(null)", len);
	else
		write(1, str, len);
}

static void		print_number(t_ull num, char *base, int base_len)
{
	char		i;

	i = 0;
	if (num > (unsigned int)base_len - 1)
		print_number(num / base_len, base, base_len);
	i = base[num % base_len];
	write(1, &i, 1);
}

void			ft_lineup_box(t_tag *tag, t_box *box)
{
	print_char(' ', !(tag->flag & 1) * box->margin);
	print_char('-', box->sign > 0);
	print_char('0', box->prefix > 0);
	print_char('x', box->prefix > 0);
	print_char('0', box->zero);
	if (tag->type & (PERCENT | CHAR))
		print_char((char)box->value, 1);
	else if (tag->type & STRING)
		print_string((char *)box->value, box->value_len);
	else if (box->value_len)
		print_number((t_ull)box->value, box->base, box->base_len);
	print_char(' ', (tag->flag & 1) * box->margin);
}
