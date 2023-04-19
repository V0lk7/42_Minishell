/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:11:56 by jduval            #+#    #+#             */
/*   Updated: 2023/04/18 16:11:57 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	next_carac(char *str, int start)
{
	while (str[++start])
		if ((!ft_isalnum(str[start])
				&& str[start] != 32 && str[start] != '_')
			|| str[start] == '\0')
			return (start - 1);
	return (ft_strlen(str));
}

char	*join_array(char **array)
{
	char	*joined;
	int		i;

	i = -1;
	while (array[++i])
	{
		if (!i)
			joined = ft_strdup(array[i]);
		else
			joined = ft_strjoin_free(joined, array[i]);
	}
	return (joined);
}

int	is_quoted(char *str, int start, int end)
{
	int	i;
	int	block;
	int	quotes;

	i = -1;
	block = 0;
	quotes = 0;
	while (str[++i])
	{
		if (quotes && i >= end)
			block++;
		if (!block && i < start)
		{
			if (!quotes && (str[i] == '\'' || str[i] == '\"'))
				quotes = str[i];
			else if (str[i] == quotes)
				quotes = 0;
		}
		if (block && str[i] == quotes)
			return (quotes);
	}
	return (0);
}

int	count_args_expansion(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (int)ft_strlen(str))
	{
		if (str[i] == '$')
		{
			i = (next_carac(str, i + 1) + 1);
			j++;
		}
		else
		{
			i = next_carac(str, i) + 1;
			j++;
		}
	}
	return (j);
}
