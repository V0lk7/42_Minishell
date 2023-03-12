#include "../../includes/built_in.h"

void	ft_exit(t_mini *mini)
{
	mini->exit = 1;
	if (count_args_2d(mini->cmd) > 2)
	{
		ft_putstr_fd(2, "Too many arguments");
		return ;
	}
	else if (mini->cmd[1] && !ft_isdigit(mini->cmd[1][0]))
		ft_putstr_fd(2, "Numeric argument required");
	else if (!mini->cmd[1])
		return ;
	else
		mini->exit = ft_atoi(mini->cmd[1]);
}
