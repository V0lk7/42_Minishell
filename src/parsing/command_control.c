/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:02:47 by jduval            #+#    #+#             */
/*   Updated: 2023/05/04 13:05:20 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/clear.h"
#include "../libft/include/libft.h"
#include "../../includes/utils.h"
#include <limits.h>

static int	is_cmd_valid(char *cmd, char *arg, char **path)
{
	int	len;

	len = ft_strlen(cmd);
	ft_strlcpy(arg, cmd, len + 1);
	if (len == 0)
		return (-1);
	if (arg[0] == '/')
		return (check_absolute_path(arg));
	if (len >= 2 && arg[0] == '.' && arg[1] == '/')
		return (check_file(arg));
	return (loop_on_path(path, cmd, arg));
}

int	type_of_command(t_cmd *cmd, t_mini *utils)
{
	char	*arg;

	if (cmd->valid == 2)
		return (0);
	cmd->id = is_builtin(cmd->cmd[0]);
	if (cmd->id >= 0)
	{
		cmd->valid = 0;
		return (0);
	}
	arg = ft_calloc(_POSIX_ARG_MAX, sizeof(char));
	if (arg == NULL)
		return (1);
	cmd->valid = is_cmd_valid(cmd->cmd[0], arg, utils->path);
	if (cmd->valid < 0)
	{
		free(arg);
		return (0);
	}
	free(cmd->cmd[0]);
	cmd->cmd[0] = arg;
	return (0);
}

t_data	*command_manager(t_data **head)
{
	t_data	*tmp;
	int		flag;

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
