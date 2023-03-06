#include "../includes/libft.h"

int	count_args_2d(char **array2d)
{
	int	i;

	i = 0;
	while (array2d[i])
		i++;
	return (i);
}
