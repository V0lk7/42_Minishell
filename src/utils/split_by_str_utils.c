/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_str_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:08:58 by jduval            #+#    #+#             */
/*   Updated: 2023/04/21 17:49:35 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	split_count_words(const char *str, const char *delim)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		i += find_word(&str[i], delim);
		if (str[i] != '\0')
			count++;
		while (str[i] && compare_delim(str[i], delim) == FALSE)
			i++;
		if (str[i] == '\0')
			break ;
	}
	return (count);
}

int	fill_empty_array(char **array)
{
	array[0] = ft_strdup("");
	if (array[0] == NULL)
		return (1);
	return (0);
}
