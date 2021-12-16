/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:44:31 by yeju              #+#    #+#             */
/*   Updated: 2021/06/23 18:44:33 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_number_len(t_ull nbr, int len)
{
	int	i;

	i = 1;
	while ((nbr /= len) > 0)
		++i;
	return (i);
}

int		ft_max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}
