#include "libft.h"

int	compare(char **array, char *str)
{
	int	equal;
	int	i;

	equal = search_c(str, '=');
	i = 0;
	if (str[equal - 1] == '+')
		equal = equal - 2;
	while (i < count_args_2d(array))
	{
		if (!ft_strncmp(array[i], str, equal))
			return (1);
		i++;
	}
	return (0);
}
