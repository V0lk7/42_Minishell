#include "../../includes/utils.h"

static int	verif_dollar(char *cmd)
{
	int	dollar;

	dollar = search_c(cmd, '$');
	if (dollar == -1)
		return (-1);
	else if (dollar == 0)
		return (1);
	return (0);
}

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

static void	find_dollar(t_cmd *cmd, char *dollar, int index)
{
	char	*cpy;
	int		i;
	int		j;
	int		length;

	i = 0;
	j = 1;
	length = count_args_2d(cmd->mini->envp_cpy);
	cpy = malloc (sizeof (char) * ft_strlen(dollar) + 1);
	while (i < (int)ft_strlen(dollar))
	{
		cpy[i] = dollar[j];
		i++;
		j++;
	}
	cpy[i] = '\0';
	j = 0;
	while (j < length)
	{
		i = search_c(cmd->mini->envp_cpy[j], '=');
		if (!ft_strncmp(cmd->mini->envp_cpy[j], cpy, i))
		{
			cpy = cut_dollar(cmd->mini->envp_cpy[j]);
			cmd->cmd[index] = ft_strdup(cpy);
			return ;
		}
		j++;
	}
	return ;
}

void	expansion(t_cmd *cmd)
{
	int	i;
	int	length;

	i = 0;
	length = count_args_2d(cmd->cmd);
	while (i < length)
	{
		if (verif_dollar(cmd->cmd[i]) == 1)
			find_dollar(cmd, cmd->cmd[i], i);
		i++;
	}
}
