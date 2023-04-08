#include "../../includes/utils.h"

void	interrogation_dollar(t_cmd *cmd, int i, int index)
{
	if (!i)
		cmd->cmd[index] = ft_strdup(ft_itoa(g_status));
	else
		cmd->cmd[index] = ft_strjoin(cmd->cmd[index], ft_itoa(g_status));
	return ;
}
