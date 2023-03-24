#include "../../include/libft.h"

int	find_in_eq(char **array, char *str)
{
	int	equal;
	int	i;

	equal = search_c(str, '=');
	i = 0;
	if (equal != -1)
	{
		while (array[i])
		{
			if (!ft_strncmp(array[i], str, equal - 1))
				return (i);
			i++;
		}
	}
	return (-1);
}

int	find_in(char **array, char *str)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (!ft_strncmp(array[i], str, ft_strlen(str)))
			return (i);
		i++;
	}
	return (-1);
}
