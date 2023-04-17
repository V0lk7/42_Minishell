#include "../../includes/utils.h"

//Ne recoit plus quune str, cmd devient mini
void	expansion(t_cmd *cmd)
{
	int		i;

	i = 0;
	while (cmd->cmd[++i])
		split_expansion(cmd, cmd->cmd[i], i);
}
