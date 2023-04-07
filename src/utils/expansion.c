#include "../../includes/utils.h"

static void	replace_dollar(t_cmd *cmd, char *substr, int index, int i)
{		
	int	find;

	find = find_expansion_array(cmd->mini->envp_cpy, substr);
	if (!i)
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
	i = 0;
	j = c_dollar + 1;
	while (i < count_c(dollar, '$'))
	{
		while (dollar[j] && dollar[j] != '$')
			j++;
		if (i)
		{
			free(substr);
			substr = ft_substr(dollar, c_dollar + 1, ft_strlen(dollar));
			c_dollar += search_c(substr, '$') + 1;
		}
		substr = ft_substr(dollar, c_dollar + 1, j - c_dollar - 1);
		j++;
		if (find_expansion_array(cmd->mini->envp_cpy, substr) != 0)
			replace_dollar(cmd, substr, index, i);
		else if (!i)
			cmd->cmd[index] = ft_strdup("");
		i++;
	}
}

void	expansion(t_cmd *cmd)
{
	char	*join;
	int		c_dollar;
	int		i;

	i = -1;
	while (++i < count_args_2d(cmd->cmd))
	{
		if (i)
		{
			c_dollar = search_c(cmd->cmd[i], '$');
			if (c_dollar > 0)
				join = ft_substr(cmd->cmd[i], 0, c_dollar);
		}
		find_dollar(cmd, cmd->cmd[i], i);
		if (i && c_dollar > 0)
		{
			cmd->cmd[i] = ft_strjoin(join, cmd->cmd[i]);
			if (join)
				free(join);
		}
	}
}
