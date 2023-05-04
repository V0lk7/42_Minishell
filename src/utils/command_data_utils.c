/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_data_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:01:08 by jduval            #+#    #+#             */
/*   Updated: 2023/05/04 13:05:18 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdbool.h>
#include <sys/stat.h>

int	type_of_file(char *str)
{
	struct stat	file;

	stat(str, &file);
	if (S_ISDIR(file.st_mode) == true)
		return (-2);
	return (0);
}

int	loop_on_path(char **path, char *cmd, char *arg)
{
	int	i;
	int	len;
	int	valid;

	i = 0;
	len = 0;
	valid = -1;
	while (path[i] && valid == -1)
	{
		len = ft_strlen(path[i]);
		ft_strlcpy(arg, path[i], len + 1);
		len += ft_strlen(arg) + 1;
		ft_strlcat(arg, cmd, len);
		if (access(arg, F_OK) == 0)
			valid = type_of_file(arg);
		i++;
	}
	return (valid);
}

int	check_absolute_path(char *cmd)
{
	int	valid;

	if (access(cmd, F_OK) != 0)
		return (-1);
	valid = type_of_file(cmd);
	return (valid);
}

int	check_file(char *cmd)
{
	if (access(cmd, F_OK) == 0)
		return (type_of_file(cmd));
	return (-1);
}

int	is_builtin(const char *cmd)
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
		return (6);
	else if (ft_strncmp(cmd, "export", 6) == 0 && len_cmd == 6)
		return (3);
	else if (ft_strncmp(cmd, "pwd", 3) == 0 && len_cmd == 3)
		return (4);
	else if (ft_strncmp(cmd, "unset", 5) == 0 && len_cmd == 5)
		return (5);
	else
		return (-1);
}
