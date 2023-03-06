#include "../includes/minishell.h"

void	ft_env(t_minis *minis)
{
	int		i;
	int		length;

	i = 0;
	if (!minis->envp_cpy)
		return ;
	length = count_args_2d(minis->envp_cpy);
	while (i < length)
	{
		printf("%s\n", minis->envp_cpy[i]);
		i++;
	}
}
