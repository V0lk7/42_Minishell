/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_management.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:03:21 by jduval            #+#    #+#             */
/*   Updated: 2023/04/18 17:17:01 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/enum.h"
#include "../../includes/utils.h"
#include "../include/libft.h"

static int	redirect_expand_setting(t_red *red, t_mini *mini)
{
	if (red->way == HDOC)
	{
		if (ft_strcspn(red->file[0], "\'\"") != (int)ft_strlen(red->file[0]))
			red->expand = 1;
		else
			red->expand = 0;
		if (remove_the_quote(red->file[0]) == -1)
			return (1);
	}
	else
	{
		if (dollar_in_quote(red->file[0]) == TRUE)
			red->file[0] = expansion(mini, red->file[0]);
		else
		{
			//expansion_wdsplit(red->file, mini, NULL);
			red->expand = count_args_2d(red->file);
		}
	}
	return (0);
}

static int	command_expand_setting(t_cmd *cmd, t_mini *mini)
{
	int	i;

	i = 0;
	while (cmd->cmd[i] != NULL)
	{
		if (search_c(cmd->cmd[i], '$') > -1 && dollar_in_quote(cmd->cmd[i]) == TRUE)
			cmd->cmd[i] = expansion(mini, cmd->cmd[i]);
//		else
//			expansion_wdsplit(cmd->cmd, mini, &i);
		i++;
	}
	return (0);
}

int	expansion_management(t_data *lst, t_mini *mini)
{
	int	flag;

	while (lst != NULL)
	{
		if (lst->name == REDIRECTION
			&& search_c(lst->data.rdict.file[0], '$') > -1)
		{
			flag = redirect_expand_setting(&lst->data.rdict, mini);
			if (flag > 0)
				return (flag);
		}
		else
		{
			flag = command_expand_setting(&lst->data.cmd, mini);
			if (flag < 0)
				return (flag);
		}
		lst = lst->next;
	}
	return (0);
}
