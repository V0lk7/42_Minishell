/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:49:42 by jduval            #+#    #+#             */
/*   Updated: 2023/04/25 16:33:03 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"
#define SIMPLE 39
#define DOUBLE 34

static void	status_expansion(char **str)
{
	free(*str);
	*str = ft_itoa(g_status);
}

static void	loop_replace_expansion(char **envp, char **str)
{
	char	*substr;
	int		equal;
	int		find;

	substr = ft_substr(*str, 1, ft_strlen(*str));
	if (find_expansion_array(envp, substr) != -1)
	{
		find = find_expansion_array(envp, substr);
		equal = search_c(envp[find], '=') + 1;
		free(*str);
		free(substr);
		substr = ft_substr(envp[find], equal, ft_strlen(envp[find]));
		*str = ft_strdup(substr);
		free(substr);
	}
	else
	{
		free(*str);
		*str = ft_strdup("");
		free(substr);
	}
}

static char	*replace_command(char **array)
{
	char	*new_command;
	int		i;

	i = 0;
	while (array[i])
	{
		if (!i)
			new_command = ft_strdup(array[i]);
		else if (array[i])
			new_command = ft_strjoin_free(new_command, array[i]);
		i++;
	}
	free_array2d(array);
	return (new_command);
}

static void	check_in_env(char **envp, char **str, int index)
{
	char	*substr;

	substr = ft_substr(*str, 1, ft_strlen(*str));
	if (find_expansion_array(envp, substr) == -1)
	{
		if (!index)
		{
			free(*str);
			*str = ft_strdup("");
		}
		else
			*str = ft_strjoin_free(*str, "");
	}
	free(substr);
}

char	*replace_expansion(char **envp, char **array)
{
	char	*join;
	char	*final_value;
	int		i;
	int		length;

	join = join_array(array);
	i = -1;
	length = 0;
	while (array[++i])
	{
		ft_printf("%s\n", array[i]);
		length += ft_strlen(array[i]);
		if (is_quoted(join, length - ft_strlen(array[i]), length) != SIMPLE)
		{
			if (!ft_strcmp(array[i], "$?"))
				status_expansion(&array[i]);
			else if (array[i][0] == '$')
				loop_replace_expansion(envp, &array[i]);
		}
		else if (array[i][0] == '$')
			check_in_env(envp, &array[i], i);
	}
	free(join);
	final_value = replace_command(array);
	return (final_value);
}
