#include "../includes/minishell.h"

void	ft_pwd(t_minis *minis)
{
	char	cwd[PATH_MAX];

	(void)minis;
	if (!getcwd(cwd, PATH_MAX))
	{
		perror("Error getcwd ");
		return ;
	}
	printf("%s\n", cwd);
}
