/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:29:20 by kramjatt          #+#    #+#             */
/*   Updated: 2023/02/24 19:54:12 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*swap;

	swap = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		swap[i] = c;
		i++;
	}
	return (swap);
}
