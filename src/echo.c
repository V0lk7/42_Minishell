#include "../includes/minishell.h"

void	ft_echo(t_minis *minis)
{
	int	i;
	int	backslash_n;

	i = 0;
	backslash_n = 0;
	if (!minis->cmd[1])
	{
		printf("\n");
		return ;
	}
	if (!ft_strcmp(minis->cmd[1], " ") && !minis->cmd[2])
		return ;
	while (minis->cmd[++i] && !ft_strcmp(minis->cmd[i], "-n"))
		backslash_n++;
	while (minis->cmd[i])
	{
		printf("%s", minis->cmd[i]);
		if (minis->cmd[i + 1] && ft_strcmp(minis->cmd[i], "\0"))
			printf (" ");
		i++;
	}
	printf("\n");
	free_array2d(minis->cmd);
}
