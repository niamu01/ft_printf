/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:44:02 by yeju              #+#    #+#             */
/*   Updated: 2021/06/23 18:59:12 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define PERCENT 1
# define CHAR 2
# define STRING 4
# define POINTER 8
# define DIGIT 48
# define UDIGIT 64
# define HEXA 128
# define XHEXA 256

typedef unsigned long long	t_ull;

typedef struct				s_tag
{
	int						flag;
	int						width;
	int						precision;
	int						length;
	int						type;
}							t_tag;

typedef struct				s_box
{
	int						margin;
	int						sign;
	int						prefix;
	int						zero;
	char					base[16];
	int						base_len;
	long long				value;
	int						value_len;
}							t_box;

int							ft_printf(const char *format, ...);
int							ft_format_parse(char *format, va_list ap);

int							ft_setting_tag(t_tag *tag, char **format,
					va_list ap);
long long					ft_get_value(t_tag *tag, va_list ap);
int							ft_manage_print(t_tag *tag, long long arg);
void						ft_lineup_box(t_tag *tag, t_box *box);

int							ft_max(int x, int y);
int							ft_get_number_len(t_ull n, int len);
#endif
