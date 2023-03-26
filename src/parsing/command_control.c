/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:02:47 by jduval            #+#    #+#             */
/*   Updated: 2023/03/26 16:24:35 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/enum.h"
#include "../../includes/clear.h"

static int	is_builtin(const char *cmd)
{
	int			len_cmd;

	len_cmd = ft_strlen(cmd);
	if (ft_strncmp(cmd, "cd", 2) == 0 && len_cmd == 2)
		return (0);
	else if (ft_strncmp(cmd, "echo", 4) == 0 && len_cmd == 4)
		return (1);
	else if (ft_strncmp(cmd, "env", 3) == 0 && len_cmd == 3)
		return (2);
	else if (ft_strncmp(cmd, "exit", 4) == 0 && len_cmd == 4)
		return (3);
	else if (ft_strncmp(cmd, "export", 6) == 0 && len_cmd == 6)
		return (4);
	else if (ft_strncmp(cmd, "pwd", 3) == 0 && len_cmd == 3)
		return (5);
	else if (ft_strncmp(cmd, "unset", 5) == 0 && len_cmd == 5)
		return (6);
	else
		return (-1);
}

static int	is_cmd_valid(char *cmd, char *arg, char **path)
{
	int	i;
	int	len;
	int	valid;

	i = 0;
	len = ft_strlen(cmd);
	ft_strlcpy(arg, cmd, len + 1);
 	valid = access(arg, F_OK);
	if (valid == 0 && ft_strncmp(arg, "./", 2) == 0)
		return(valid);
	while (path[i] && valid == -1)
	{
		len = ft_strlen(path[i]);
		ft_strlcpy(arg, path[i], len + 1);
		len += ft_strlen(arg) + 1;
		ft_strlcat(arg, cmd, len);
 		valid = access(arg, F_OK);
		i++;
	}
	return (valid);
}

int	type_of_command(t_cmd *cmd, t_mini *utils)
{
	char	*arg;

	cmd->id = is_builtin(cmd->cmd[0]);
	if (cmd->id >= 0)
	{
		cmd->valid = 0;
		return (0);
	}
	arg = ft_calloc(1000, sizeof(char));
	if (arg == NULL)
		return (1);
	cmd->valid = is_cmd_valid(cmd->cmd[0], arg, utils->path);
	free(cmd->cmd[0]);
	cmd->cmd[0] = arg;
	return (0);
}

t_data	*command_manager(t_data **head)
{
	t_data	*tmp;
	int		flag;;

	tmp = (*head);
	while (tmp != NULL)
	{
		if (tmp->name == COMMAND)
		{
			flag = type_of_command(&tmp->data.cmd, tmp->data.cmd.mini);
			if (flag == 1)
			{
				free_all_nodes(&(*head));
				return (NULL);
			}
		}
		tmp = tmp->next;
	}
	return ((*head));
}
