/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_pipe_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:40:45 by jduval            #+#    #+#             */
/*   Updated: 2023/03/20 17:50:48 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

static int	nbrs_of_pipe(char *str);

int	*find_index_pipe(char *str)
{
	int	i;
	int	k;
	int	character;
	int	*index;

	i = nbrs_of_pipe(str);
	character = 0;
	index = malloc(sizeof(int) * (i + 1));
	if (index == NULL)
		return (NULL);
	index[0] = i;
	i = -1;
	k = 0;
	while (str[++i])
	{
		if (character == 0 && (str[i] == '\'' || str[i] == '\"'))
			character = str[i];
		else if (character > 0 && (str[i] == '\'' || str[i] == '\"'))
			character = 0;
		else if (character == 0 && str[i] == '|')
			index[++k] = i;
	}
	return (index);
}

static int	nbrs_of_pipe(char *str)
{
	int	i;
	int	count;
	int	character;

	i = 0;
	count = 0;
	character = 0;
	while (str[i])
	{
		if (character == 0 && (str[i] == '\'' || str[i] == '\"'))
			character = str[i];
		else if (character > 0 && str[i] == character)
			character = 0;
		else if (character == 0 && str[i] == '|')
			count++;
		i++;
	}
	return (count);
}
