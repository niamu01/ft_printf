/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeju <yeju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:48:04 by yeju              #+#    #+#             */
/*   Updated: 2021/01/13 16:48:05 by yeju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		s1_len;
	int		s2_len;

	if (!(s1) && !(s2))
		return (NULL);
	else if (!(s1) || !(s2))
	{
		if (s1)
			return (ft_strdup(s1));
		return (ft_strdup(s2));
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(string = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	ft_strlcpy(string, s1, s1_len + 1);
	ft_strlcat(string + (s1_len), s2, s2_len + 1);
	return (string);
}
