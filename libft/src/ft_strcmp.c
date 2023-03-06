/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:00:36 by kramjatt          #+#    #+#             */
/*   Updated: 2022/10/19 11:35:33 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	value;

	i = 0;
	value = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			value = ((unsigned char)s1[i]) - ((unsigned char)s2[i]);
			return (value);
		}
		i++;
	}
	return (0);
}
