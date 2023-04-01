#include "../../includes/utils.h"

static char	*cut_dollar(char *cmd)
{
	char	*cut;
	int		i;
	int		j;
	int		equal;

	equal = search_c(cmd, '=');
	cut = malloc(sizeof(char) * (ft_strlen(cmd) - equal) + 1);
	if (!cut)
		return (NULL);
	i = 0;
	while (i <= equal)
		i++;
	j = 0;
	while (i < (int)ft_strlen(cmd))
	{
		cut[j] = cmd[i];
		i++;
		j++;
	}
	cut[j] = '\0';
	return (cut);
}

int	count_c(char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

static void	loop_dollar(t_cmd *cmd, char *cpy, int index, int count)
{
	int	i;

	i = 0;
	while (i < count_args_2d(cmd->mini->envp_cpy))
	{
		if (!ft_strncmp(cmd->mini->envp_cpy[i], cpy, ft_strlen(cpy)))
		{
			cpy = cut_dollar(cmd->mini->envp_cpy[i]);
			if (count == count_c(cmd->cmd[index], '$'))
				cmd->cmd[index] = ft_strjoin("", cpy);
			else
				cmd->cmd[index] = ft_strjoin(cmd->cmd[index], cpy);
			return ;
		}
		i++;
	}
	cmd->cmd[index] = NULL;
}

static void	find_dollar(t_cmd *cmd, char *dollar, int index)
{
	char	*cpy;
	int		count;
	int		c_dollar;
	int		next;

	c_dollar = search_c(dollar, '$');
	if (c_dollar > 0)
		cmd->cmd[index] = ft_strjoin("", ft_substr(dollar, 0, c_dollar));
	count = count_c(dollar, '$');
	while (count > 0)
	{
		if (count == count_c(dollar, '$'))
			next = search_c
				(ft_substr(dollar, c_dollar + 1, ft_strlen(dollar)), '$');
		else
			next = search_c
				(ft_substr(cpy, c_dollar + 1, ft_strlen(dollar)), '$');
		if (next != -1)
			cpy = ft_substr(dollar, c_dollar + 1, next);
		else
			cpy = ft_substr(dollar, c_dollar + 1, ft_strlen(dollar));
		loop_dollar(cmd, cpy, index, count);
		c_dollar += next + 1;
		count--;
	}
}

void	expansion(t_cmd *cmd)
{
	int	i;

	i = -1;
	while (++i < count_args_2d(cmd->cmd))
		find_dollar(cmd, cmd->cmd[i], i);
}
