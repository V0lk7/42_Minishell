/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:59:08 by jduval            #+#    #+#             */
/*   Updated: 2023/04/05 14:11:32 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../../includes/utils.h"
#include <readline/readline.h>

int	errors_command(t_cmd *cmd)
{
	int	flag;

	flag = 1;
	if (cmd->valid == -1)
	{
		command_not_found(cmd->cmd[0]);
		flag = 127;
	}
	else if (cmd->valid == -2)
	{
		command_is_directory(cmd->cmd[0]);
		flag = 126;
	}
	return (flag);
}

void	command_not_found(char *cmd)
{
	ft_putstr_fd(2, "😈 Minishell 😈 : Command '");
	ft_putstr_fd(2, cmd);
	ft_putstr_fd(2, "' not found\n");
}

void	command_is_directory(char *cmd)
{
	ft_putstr_fd(2, "😈 Minishell 😈 : ");
	ft_putstr_fd(2, cmd);
	ft_putstr_fd(2, ": Is a directory\n");
}

int	ctrl_d_hdoc(char *str, int n)
{
	char	*line;

	line = ft_itoa(n);
	if (line == NULL)
	{
		perror(NULL);
		return (1);
	}
	ft_putstr_fd(2, "😈 Minishell 😈: warning: here-document at line ");
	ft_putstr_fd(2, line);
	ft_putstr_fd(2, " delimited by end-of-file (wanted `");
	ft_putstr_fd(2, str);
	ft_putstr_fd(2, "\')\n");
	free (line);
	return (0);
}

void error_exit(char *str)
{
	ft_putstr_fd(2, "😈 Minishell 😈 : exit: ");
	ft_putstr_fd(2, str);
	ft_putstr_fd(2, ": Numeric argument required\n");
}
