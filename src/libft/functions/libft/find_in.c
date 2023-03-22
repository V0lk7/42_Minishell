#include "../../include/libft.h"

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
