#include "../../includes/utils.h"

static void	loop_split_expansion(char **array, char *str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < (int)ft_strlen(str))
	{
		if (str[i] == '$')
		{
			tmp = ft_substr(str, i, (next_carac(str, i + 1) + 1) - i);
			array[j] = ft_strdup(tmp);
			i = (next_carac(str, i + 1) + 1);
			free(tmp);
			j++;
		}
		else
		{
			array[j] = ft_substr(str, i, (next_carac(str, i) + 1) - i);
			j++;
			i = next_carac(str, i) + 1;
		}
	}
	array[j] = NULL;
}

void	split_expansion(t_cmd *cmd, char *str, int index)
{
	char	**array;

	array = malloc(sizeof (char *) * (count_args_expansion(str) + 1));
	loop_split_expansion(array, str);
	replace_expansion(cmd, cmd->mini->envp_cpy, array, index);
}
