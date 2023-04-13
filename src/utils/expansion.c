#include "../../includes/utils.h"
#define SIMPLE '\''
#define DOUBLE '"'

int	next_carac(char *str, int start)
{
	int	i;

	i = 0;
	while (str[++start])
		if (str[start] == '$')
			return (start);
	return (-1);
}

static int	*is_quoted(char *str, int start, int end)
{
	char	*substr;
	int		i;
	int		j;
	int		simple_q[2];
	int		double_q[2];

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			if (str[i] == '\'')
			{
				simple_q[j] = i;
				j++;
				if (j == 2)
					return (simple_q);
			}
			if (str[i] == '"')
			{
				double_q[j] = i;
				j++;
				if (j == 2)
					return (double_q);
			}
		}

	}
	free(dollar);
}

void	split_expansion(t_cmd *cmd, char *str, int index)
{
	char	**array;
	char	*tmp;
	int		*quoted;
	int		i;
	int		j;

	(void)index;
	i = 0;
	j = 0;
	array = malloc(sizeof (char *) * count_args_2d(cmd->cmd));
	quoted = malloc(sizeof (int *) * count_args_2d(cmd->cmd));
	while (str[i])
	{
		if (str[i] == '$')
		{
			tmp = ft_substr(str, i + 1, next_carac(str, i) - 1);
			quoted[j] = is_quoted(str, i, next_carac(str, i));
			array[j] = tmp;
			ft_printf("STR %s\n", str);
			ft_printf("START %d\n", i);
			ft_printf("END %d\n", next_carac(str, i) - 1);
			ft_printf("TMP %s\n", tmp);
			ft_printf("------------------------------\n");
			i += ((next_carac(str, i) - 1) - i);
			free(tmp);
			j++;
		}
			i++;
	}
}

void	expansion(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->cmd[++i])
		split_expansion(cmd, cmd->cmd[i], i);
}
