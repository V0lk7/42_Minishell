/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify_user_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:54:42 by jduval            #+#    #+#             */
/*   Updated: 2023/03/20 17:51:17 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/utils.h"
#include "../../includes/enum.h"

static void	check_and_free(char **array, int *index)
{
	int	i;

	i = -1;
	if (array != NULL)
	{
		while (array[++i])
			free(array[i]);
		free(array);
	}
	if (index != NULL)
		free(index);
}

static char	*create_str_part(char *str, int i, int *index)
{
	char	*part;

	if (index[0] == 0)
		part = ft_strdup(str);
	else if (i == 0)
		part = ft_substr(str, 0, index[1]);
	else if (i == index[0])
		part = ft_substr(str, index[i] + 1, ft_strlen(str) - index[i]);
	else
		part = ft_substr(str, index[i] + 1, index[i + 1] - index[i] - 1);
	if (part == NULL)
		return (NULL);
	return (part);
}

static void	create_array(char *str, char ***array, int *index)
{
	int	i;

	i = 0;
	while (i < index[0] + 1)
	{
		(*array)[i] = create_str_part(str, i, index);
		if ((*array)[i] == NULL)
			check_and_free(*array, index);
		i++;
	}
	(*array)[i] = NULL;
}

char	**isolate_by_pipe(char *str)
{
	int		*index;
	char	**array;
	int		i;

	i = 0;
	index = find_index_pipe(str);
	if (index == NULL)
		return (NULL);
	array = malloc(sizeof(char *) * (index[0] + 2));
	if (array == NULL)
	{
		free(index);
		return (NULL);
	}
	create_array(str, &array, index);
	free(index);
	if (array == NULL)
		return (NULL);
	return (array);
}
