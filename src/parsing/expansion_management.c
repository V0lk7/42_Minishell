/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_management.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:03:21 by jduval            #+#    #+#             */
/*   Updated: 2023/05/01 19:42:15 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"
#include "../../includes/parsing.h"

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
			red->file[0] = expansion(mini, red->file[0], 0);
		else
		{
			red->file = expansion_wdsplit(red->file, mini, 0);
			red->expand = count_args_2d(red->file);
		}
	}
	if (red->file == NULL || red->file[0] == NULL)
		return (1);
	if (red->file[0][0] == '\0')
		red->expand = 2;
	return (0);
}

static int	command_expand_setting(t_cmd *cmd, t_mini *mini)
{
	int	i;

	i = 0;
	while (cmd->cmd[i] != NULL)
	{
		if (search_c(cmd->cmd[i], '$') > -1)
		{
			if (dollar_in_quote(cmd->cmd[i]) == TRUE)
				cmd->cmd[i] = expansion(mini, cmd->cmd[i], 0);
			else
				cmd->cmd = expansion_wdsplit(cmd->cmd, mini, i);
			if (cmd->cmd == NULL || cmd->cmd[i] == NULL)
				return (1);
			if (cmd->cmd[0][0] == '\0')
				cmd->valid = 2;
		}
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
			lst->data.rdict.save = ft_strdup(lst->data.rdict.file[0]);
			if (lst->data.rdict.save == NULL)
				return (1);
			flag = redirect_expand_setting(&lst->data.rdict, mini);
			if (flag == 1)
				return (flag);
		}
		else if (lst->name == COMMAND)
		{
			flag = command_expand_setting(&lst->data.cmd, mini);
			if (flag == 1)
				return (flag);
		}
		lst = lst->next;
	}
	return (0);
}
