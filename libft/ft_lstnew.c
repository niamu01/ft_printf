/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:44:44 by yeju              #+#    #+#             */
/*   Updated: 2021/01/13 17:16:25 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list *a;

	if ((a = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	a->content = content;
	a->next = NULL;
	return (a);
}
