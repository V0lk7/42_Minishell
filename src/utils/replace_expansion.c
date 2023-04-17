#include "../../includes/utils.h"
#define SIMPLE 39

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
		*str = ft_substr(envp[find], equal, ft_strlen(envp[find]));
	}
	else
	{
		free(*str);
		*str = ft_strdup("");
	}
}

static void	replace_command(t_cmd *cmd, char **array, int index)
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
	free(cmd->cmd[index]);
	free_array2d(array);
	cmd->cmd[index] = new_command;
}

void	replace_expansion(t_cmd *cmd, char **envp, char **array, int index)
{
	char	*join;
	int		i;
	int		length;

	join = join_array(array);
	i = 0;
	length = 0;
	while (array[i])
	{
		length += ft_strlen(array[i]);
		if (is_quoted(join, length - ft_strlen(array[i]), length) != 39)
		{
			if (!ft_strcmp(array[i], "$?"))
				status_expansion(&array[i]);
			else if (array[i][0] == '$')
				loop_replace_expansion(envp, &array[i]);
		}
		i++;
	}
	free(join);
	replace_command(cmd, array, index);
}
