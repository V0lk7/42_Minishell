/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_management.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:03:21 by jduval            #+#    #+#             */
/*   Updated: 2023/04/18 12:59:01 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	redirect_expand_setting(t_rdict *red, t_mini *mini)
{
	int	flag;

	if (red->way == HDOC)
	{
		if (ft_strcspn(red->file[0], "\'\"") != ft_strlen(red->file[0]))
			red->expand = 1;
		else
			red->expand = 0;
		flag = remove_the_quote(red->file[0]);
	}
	else
	{
		if (dollar_in_quote(rdict->file[0]) == TRUE)
			flag = expansion(red->file[0], mini);
		else
		{
			flag = expansion_wdsplit(red->file, mini, NULL);
			if (flag == -1)
				return (flag);
			red->expansion = count_args_2d(red->file);
		}
	}
	return (flag);
}

static int	command_expand_setting(t_cmd *cmd, t_mini *mini)
{
	int	i;
	int	flag;

	i = 0;
	while (cmd->cmd[i] != NULL)
	{
		if (dollar_in_quote(cmd->cmd[i]) == TRUE)
			cmd->cmd[i] = expansion(mini, cmd->cmd[i]);
		else
			flag = expansion_wdsplit(cmd->cmd, mini, &i);
		if (flag == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	expansion_management(t_data *lst, t_mini *mini)
{
	int	flag;

	while (lst != NULL)
	{
		if (lst->name == REDIRECTION && search_c(lst->data.rdict.file[0]) > -1)
		{
			flag = redirect_expand_setting(slt->data.rdict, mini);
			if (flag < 0)
				return (flag);
		}
		else
		{
			flag = command_expand_setting(lst->data.cmd, mini);
			if (flag < 0)
				return (flag);
		}
		lst = lst->next;
	}
	return (0);
}
