/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:39:32 by kramjatt          #+#    #+#             */
/*   Updated: 2023/02/24 19:53:54 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	j = 0;
	if (s1 == NULL)
		s1 = ft_calloc(1, sizeof(char));
	if (s2 == NULL)
		return (NULL);
	value = ft_calloc((ft_strlen(s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (value == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		value[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		value[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (value);
}
