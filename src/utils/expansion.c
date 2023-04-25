/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:11:36 by jduval            #+#    #+#             */
/*   Updated: 2023/04/25 18:26:49 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"
#include "../../includes/parsing.h"

static void	loop_split_expansion(char **array, char *str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < (int)ft_strlen(str))
	{
		if (str[i] == '$')
		{
			tmp = ft_substr(str, i, (next_carac(str, i + 1) + 1) - i);
			array[j] = ft_strdup(tmp);
			i = (next_carac(str, i + 1) + 1);
			free(tmp);
			j++;
		}
		else
		{
			array[j] = ft_substr(str, i, (next_carac(str, i) + 1) - i);
			j++;
			i = next_carac(str, i) + 1;
		}
	}
	array[j] = NULL;
	free(str);
}



char	*expansion(t_mini *mini, char *str, t_way way)
{
	char	**array;

	array = malloc(sizeof (char *) * (count_args_expansion(str) + 1));
	loop_split_expansion(array, str);
	str = replace_expansion(mini->envp_cpy, array);
	if (way != HDOC)
		remove_the_quote(str);
	return (str);
}
