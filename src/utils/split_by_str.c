/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:56:34 by jduval            #+#    #+#             */
/*   Updated: 2023/04/21 17:47:31 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../../includes/utils.h"
#include <stdlib.h>

char	**split_by_str(const char *s, const char *delim)
{
	char	**array;
	int		flag;
	int		len;

	flag = 0;
	if (s[0] != '\0')
		len = split_count_words(s, delim);
	else
		len = 1;
	array = malloc(sizeof(char *) * (len + 1));
	if (array == NULL)
		return (NULL);
	array[len] = NULL;
	if (s[0] != '\0')
		flag = fill_array(array, len, s, delim);
	else
		flag = fill_empty_array(array);
	if (flag == 1)
	{
		free_array2d(array);
		return (NULL);
	}
	return (array);
}

int	end_word(const char *str, const char *delim)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (compare_delim(str[i], delim) == TRUE)
			return (i);
		i++;
	}
	return (i);
}

t_bool	compare_delim(int c, const char *delim)
{
	int	i;

	i = 0;
	while (delim[i])
	{
		if (delim[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	find_word(const char *str, const char *delim)
{
	int	i;

	i = 0;
	while (compare_delim(str[i], delim) == TRUE)
		i++;
	return (i);
}

int	fill_array(char **array, int word, const char *s, const char *delim)
{
	int	i;
	int	start;
	int	size;
	int	len;

	start = 0;
	len = 0;
	size = (int)ft_strlen(s);
	i = 0;
	while (i < word)
	{
		start += find_word(&s[start], delim);
		len = end_word(&s[start], delim);
		array[i] = ft_substr(s, start, len);
		start += len;
		if (array[i] == NULL)
			return (1);
		i++;
	}
	return (0);
}
