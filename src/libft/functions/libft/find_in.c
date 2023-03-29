#include "../../include/libft.h"

int	find_in_eq(char **array, char *str)
{
	int	equal;
	int	i;

	i = 0;
	while (array[i])
	{
		equal = search_c(array[i], '=');
		if (search_c(array[i], '=') > search_c(str, '='))
		{
			if (!ft_strncmp(array[i], str, equal))
				return (i);
		}
		else
		{
			equal = search_c(str, '=');
			if (!ft_strncmp(array[i], str, equal))
				return (i);
		}
		i++;
	}
	return (-1);
}

int	find_in(char **array, char *str)
{
	int	equal;
	int	i;

	i = 0;
	while (array[i])
	{
		equal = search_c(array[i], '=');
		if (equal > (int)ft_strlen(str))
		{
			if (!ft_strncmp(array[i], str, equal - 1))
				return (i);
		}
		else
		{
			if (!ft_strncmp(array[i], str, (int)ft_strlen(str)))
				return (i);
		}
		i++;
	}
	return (-1);
}
