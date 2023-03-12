#include "../../includes/clear.h"

static void	free_tabstruct_element(t_builts *builts)
{
	int	i;

	i = -1;
	while (++i)
		free(builts[i].str);
}

void	free_exit(t_mini *mini, t_builts *builts)
{
	free_array2d(mini->cmd);
	free_array2d(mini->envp_cpy);
	free_tabstruct_element(builts);
	free(builts);
}
