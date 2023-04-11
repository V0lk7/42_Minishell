#include "../../includes/utils.h"

static int	replace_after_arg(t_cmd *cmd, char *dollar, int index, int j)
{
	char	*substr;
	int		next_dollar;

	if (dollar[j - 1] != '$' && dollar[j - 1] != '\0')
	{
		substr = ft_substr(dollar, j - 1, ft_strlen(dollar));
		next_dollar = search_c(substr, '$');
		if (next_dollar != -1)
			substr = ft_substr(dollar, j - 1, next_dollar);
		cmd->cmd[index] = ft_strjoin(cmd->cmd[index], substr);
		free(substr);
		return (ft_strlen(substr));
	}
	return (0);
}

static void	replace_before_arg(t_cmd *cmd, char *substr, int index, int find)
{
	if (find == -1)
	{
		cmd->cmd[index] = ft_strdup("");
		return ;
	}
	substr = ft_substr(cmd->mini->envp_cpy[find],
			search_c(cmd->mini->envp_cpy[find], '=') + 1,
			ft_strlen(cmd->mini->envp_cpy[find]));
	cmd->cmd[index] = substr;
}

static void	replace_dollar(t_cmd *cmd, char *substr, int index, int i)
{		
	int	find;

	find = find_expansion_array(cmd->mini->envp_cpy, substr);
	if (!ft_strncmp(substr, "?", 1))
	{
		interrogation_dollar(cmd, i, index);
		return ;
	}
	if (!i)
		replace_before_arg(cmd, substr, index, find);
	else
	{
		if (find == -1)
		{
			cmd->cmd[index] = ft_strjoin(cmd->cmd[index], "");
			return ;
		}
		substr = ft_substr(cmd->mini->envp_cpy[find],
				search_c(cmd->mini->envp_cpy[find], '=') + 1,
				ft_strlen(cmd->mini->envp_cpy[find]));
		if (!substr)
			return ;
		cmd->cmd[index] = ft_strjoin(cmd->cmd[index], substr);
	}
}

static void	find_dollar(t_cmd *cmd, char *dollar, int index)
{
	char	*substr;
	int		c_dollar;
	int		i;
	int		j;

	c_dollar = search_c(dollar, '$');
	i = -1;
	j = c_dollar + 1;
	while (++i < count_c(dollar, '$'))
	{
		if (dollar[j - 1] == '$' && !ft_isalnum(dollar[j]))
		{
			if (!i)
				cmd->cmd[index] = ft_strdup("$");
			else
				cmd->cmd[index] = ft_strjoin(cmd->cmd[index], "$");
		}
		else
		{
			while ((dollar[j] && dollar[j] != '$' && (ft_isalnum(dollar[j])
						|| dollar[j] == '_' || dollar[j] == '?')))
				j++;
			if (i)
			{
				substr = ft_substr(dollar, c_dollar + 1, ft_strlen(dollar));
				c_dollar += search_c(substr, '$') + 1;
			}
			substr = ft_substr(dollar, c_dollar + 1, j - c_dollar - 1);
			j++;
			if (find_expansion_array(cmd->mini->envp_cpy, substr) != 0)
				replace_dollar(cmd, substr, index, i);
			else if (!i)
				cmd->cmd[index] = ft_strdup("");
			j += replace_after_arg(cmd, dollar, index, j);
			free(substr);
		}
	}
}

void	expansion(t_cmd *cmd)
{
	char	*join;
	int		c_dollar;
	int		i;

	i = -1;
	while (cmd->cmd[++i])
	{
		if (i)
		{
			c_dollar = search_c(cmd->cmd[i], '$');
			if (c_dollar > 0)
				join = ft_substr(cmd->cmd[i], 0, c_dollar);
		}
		find_dollar(cmd, cmd->cmd[i], i);
		if (i)
		{
			if (c_dollar > 0)
			{
				cmd->cmd[i] = ft_strjoin(join, cmd->cmd[i]);
				free(join);
			}
		}
	}
}
