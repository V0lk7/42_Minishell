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

static void	find_dollar(t_mini *mini, char *dollar, int index)
{
	char	*cpy;
	int		i;
	int		j;
	int		length;

	i = 0;
	j = 1;
	length = count_args_2d(mini->envp_cpy);
	cpy = malloc (sizeof (char) * ft_strlen(dollar) + 1);
	while (i < (int)ft_strlen(dollar))
	{
		cpy[i] = dollar[j];
		i++;
		j++;
	}
	cpy[i] = '\0';
	ft_printf("CPY %s\n", cpy);
	j = 0;
	while (j < length)
	{
		i = search_c(mini->envp_cpy[j], '=');
		if (!ft_strncmp(mini->envp_cpy[j], cpy, i))
		{
			cpy = cut_dollar(mini->envp_cpy[j]);
			ft_printf("CUT %s\n", cpy);
			mini->cmd[index] = ft_strdup(cpy);
			return ;
		}
		j++;
	}
	return ;
}

void	dollars(t_mini *mini)
{
	int	i;
	int	length;

	i = 0;
	length = count_args_2d(mini->cmd);
	while (i < length)
	{
		if (verif_dollar(mini->cmd[i]) == 1)
			find_dollar(mini, mini->cmd[i], i);
		i++;
	}
}
