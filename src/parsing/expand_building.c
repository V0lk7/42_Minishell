/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_building.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:56:26 by jduval            #+#    #+#             */
/*   Updated: 2023/04/25 17:49:04 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"
#include "../libft/include/libft.h"

static char	*create_str(t_expand *cmd)
{
	char	*str;

	str = ft_calloc(1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (cmd != NULL)
	{
		if (cmd->word[0] != '\0')
		{
			str = ft_strjoin_free(str, cmd->word);
			if (str == NULL)
				return (NULL);
		}
		cmd = cmd->next;
	}
	return (str);
}

static char	**insert_array(char **cmd, char **array, int i)
{
	int		j;
	int		k;
	char	**tmp;

	j = -1;
	k = -1;
	tmp = malloc(sizeof(char *) * (count_args_2d(cmd) + count_args_2d(array)));
	if (tmp == NULL)
		return (NULL);
	while (++k < i)
		tmp[k] = cmd[k];
	while (array[++j])
		tmp[k++] = array[j];
	j = i + 1;
	while (cmd[j])
		tmp[k++] = cmd[j++];
	free(cmd[i]);
	free(cmd);
	tmp[k] = NULL;
	return (tmp);
}

char	**rebuild_cmd(char **cmd, int i, t_expand *words)
{
	char	*str;
	char	**array;

	str = create_str(words);
	if (str == NULL)
		return (NULL);
	array = split_by_str(str, "\n\t ");
	free(str);
	if (array == NULL)
		return (NULL);
	cmd = insert_array(cmd, array, i);
	free(array);
	if (cmd == NULL)
		return (NULL);
	return (cmd);
}
