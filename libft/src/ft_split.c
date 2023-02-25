/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 23:47:49 by kramjatt          #+#    #+#             */
/*   Updated: 2023/02/24 19:54:04 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_count_split(char const *s, char c)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			count++;
			i += j;
		}
		else
			i++;
	}
	return (count);
}

static int	ft_len(char const *s, char c, int i)
{
	int	value;

	value = 0;
	if (s == NULL)
		return (value);
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		value++;
	}
	return (value);
}

static int	ft_verif_c(const char *s, char c, char **value, int l)
{
	int	ret;

	ret = 0;
	while (s[ret] != c && s[ret] != '\0')
	{	
		value[l][ret] = s[ret];
		ret++;
	}
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**value;
	int		i;
	int		l;

	i = 0;
	l = 0;
	if (s == NULL)
		return (NULL);
	value = ft_calloc(ft_count_split(s, c) + 1, sizeof(char *));
	if (value == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			value[l] = ft_calloc(ft_len(s, c, i) + 1, sizeof(char));
			if (value[l] == NULL)
				return (NULL);
			i += ft_verif_c(s + i, c, value, l);
			l++;
		}
		else
			i++;
	}
	return (value);
}
