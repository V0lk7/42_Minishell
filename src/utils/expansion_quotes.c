#include "../../includes/utils.h"

int	expansion_simple_quote(t_cmd *cmd, char *str, int index, int value_i)
{
	char	*substr;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (++i && str[i])
		if (str[i] == '\'')
			break ;
	j = i;
	while (++j && str[j])
		if (str[j] == '\'')
			break ;
	ft_printf("I : %d\nJ : %d\n", i, j);
	substr = ft_substr(str, i + 1, j - 1);
	if (!value_i)
		cmd->cmd[index] = ft_strdup(substr);
	else
		cmd->cmd[index] = ft_strjoin(cmd->cmd[index], substr);
	return (j + 1);
}
