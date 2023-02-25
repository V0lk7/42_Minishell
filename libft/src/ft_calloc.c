/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:07:57 by kramjatt          #+#    #+#             */
/*   Updated: 2023/02/24 19:54:20 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*memory;

	if (size == 0 || nmemb == 0)
	{
		memory = malloc(1);
		return (memory);
	}
	if (nmemb * size == 0 || ((nmemb * size) / size != nmemb))
		return (NULL);
	memory = malloc(nmemb * size);
	if (memory == NULL)
		return (NULL);
	ft_memset(memory, 0, nmemb * size);
	return (memory);
}
