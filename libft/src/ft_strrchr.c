/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:46:41 by kramjatt          #+#    #+#             */
/*   Updated: 2023/02/24 19:47:07 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strrchr(const char *s, int c)
{
	int			i;
	int			cpt;
	char		*point;

	cpt = -1;
	point = (char *)s;
	i = (int)ft_strlen(point) - 1;
	if (c == '\0')
		return (cpt);
	while (i >= 0)
	{
		if (point[i] == (unsigned char)c)
			cpt++;
		i--;
	}
	return (cpt);
}
