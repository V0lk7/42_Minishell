/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapeshift_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:52:35 by jduval            #+#    #+#             */
/*   Updated: 2023/04/24 17:34:14 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/enum.h"
#include "../../includes/utils.h"
#include "../libft/include/libft.h"

int	number_of_whitespace(t_expand *cmd)
{
	int	i;
	int	count;

	count = 0;
	while (cmd != NULL)
	{
		i = 0;
		while (cmd->id == 0 && cmd->word[i])
		{
			if (ft_isspace(cmd->word[i]) == 1)
				count++;
			i++;
		}
		cmd = cmd->next;
	}
	return (count);
}

int	save_whitespace(t_expand *cmd, char **tmp)
{
	int	len;
	int	i;
	int	j;

	len = number_of_whitespace(cmd);
	j = -1;
	if (len == 0)
		return (1);
	(*tmp) = ft_calloc(len + 1, sizeof(char));
	if ((*tmp) == NULL)
		return (-1);
	while (cmd != NULL)
	{
		i = -1;
		while (cmd->id == 0 && cmd->word[++i])
		{
			if (ft_isspace(cmd->word[i]) == 1)
			{
				(*tmp)[++j] = cmd->word[i];
				cmd->word[i] = -128;
			}
		}
		cmd = cmd->next;
	}
	return (0);
}

void	restore_whitespace(char **array, char *tmp)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == -128)
			{
				array[i][j] = tmp[k];
				k++;
			}
			j++;
		}
		i++;
	}
}
