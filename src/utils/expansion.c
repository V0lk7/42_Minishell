#include "../../includes/utils.h"

static void	find_dollar(t_cmd *cmd, char *dollar, int index)
{
	int		c_dollar;
	int		find;
	int		i;
	int		j;

	c_dollar = search_c(dollar, '$');
	if (c_dollar > 0)
		cmd->cmd[index] = ft_strdup(ft_substr(dollar, 0, c_dollar));
	i = -1;
	while (++i < count_c(dollar, '$'))
	{
		if (i != 0)
			c_dollar += search_c(ft_substr(dollar, c_dollar + 1, ft_strlen(dollar)), '$') + 1;
		j = 1;
		while (dollar[j])
		{
			if (find_in(cmd->mini->envp_cpy, ft_substr(dollar, c_dollar + 1, j)) != -1 && (dollar[j + 1] != '_' || dollar[j + 1] == '\0' || dollar[j + 1] != '$'))
			{
				find = find_in(cmd->mini->envp_cpy, ft_substr(dollar, c_dollar + 1, j));
				if (!c_dollar)
					cmd->cmd[index] = ft_strjoin("", ft_substr(cmd->mini->envp_cpy[find], search_c(cmd->mini->envp_cpy[find], '=') + 1, ft_strlen(cmd->mini->envp_cpy[find])));
				else
					cmd->cmd[index] = ft_strjoin(cmd->cmd[index], ft_substr(cmd->mini->envp_cpy[find], search_c(cmd->mini->envp_cpy[find], '=') + 1, ft_strlen(cmd->mini->envp_cpy[find])));
				break ;
			}
			else
			j++;
		}
	}
}

void	expansion(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (++i < count_args_2d(cmd->cmd))
		find_dollar(cmd, cmd->cmd[i], i);
}
