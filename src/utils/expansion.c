#include "../../includes/utils.h"
#define SIMPLE '\''
#define DOUBLE '"'

/*static int	*is_quoted(char *str, int start, int end)
{
	char	*substr;
	int		i;
	int		j;
	int		simple_q[2];
	int		double_q[2];

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			if (str[i] == '\'')
			{
				simple_q[j] = i;
				j++;
				if (j == 2)
					return (simple_q);
			}
			if (str[i] == '"')
			{
				double_q[j] = i;
				j++;
				if (j == 2)
					return (double_q);
			}
		}

	}
	free(dollar);
}*/

static void	replace_command(t_cmd *cmd, char **array, int index)
{
	char	*new_command;
	int		i;

	i = 0;
	while (array[i])
	{
		if (!i)
			new_command = ft_strdup(array[i]);
		else
			new_command = ft_strjoin(new_command, array[i]);
		i++;
	}
	free(cmd->cmd[index]);
	cmd->cmd[index] = ft_strdup(new_command);
}

static void	replace_expansion(t_cmd *cmd, char **envp, char **array, int index)
{
	int	equal;
	int	i;
	int	find;

	i = 0;
	while (array[i])
	{
		if (!ft_strcmp(array[i], "$?"))
		{
			free(array[i]);
			array[i] = ft_itoa(g_status);
		}
		else if (array[i][0] == '$')
		{
			if (count_c(array[i - 1], '\'') % 2 == 0 && count_c(array[i + 1], '\'') % 2 == 0)
			{
				if (find_expansion_array(envp, ft_substr(array[i], 1, ft_strlen(array[i]))) != -1)
				{
					find = find_expansion_array(envp, ft_substr(array[i], 1, ft_strlen(array[i])));
					equal = search_c(envp[find], '=') + 1;
					free(array[i]);
					array[i] = ft_substr(envp[find], equal, ft_strlen(envp[find]));
				}
				else
				{
					free(array[i]);
					array[i] = ft_strdup("");
				}
			}
		}
		i++;
	}
	replace_command(cmd, array, index);
}

void	split_expansion(t_cmd *cmd, char *str, int index)
{
	char	**array;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	array = malloc(sizeof (char *) * (count_args_2d(cmd->cmd) + 2) + 1);//Malloc au hasard, creer une fonction pour quantifier le malloc
	remove_the_quote(str);
	while (i < (int)ft_strlen(str))
	{
		if (str[i] == '$')
		{
			tmp = ft_substr(str, i, (next_carac(str, i + 1) + 1) - i);
			array[j] = ft_strdup(tmp);
			i = (next_carac(str, i + 1) + 1);
			free(tmp);
			j++;
		}
		else
		{
			array[j] = ft_substr(str, i, (next_carac(str, i) + 1) - i);
			j++;
			i = next_carac(str, i) + 1;
		}
	}
	array[j] = NULL;
	replace_expansion(cmd, cmd->mini->envp_cpy, array, index);
}

void	expansion(t_cmd *cmd)
{
	int		i;

	i = 0;
	while (cmd->cmd[++i])
		split_expansion(cmd, cmd->cmd[i], i);
}
