#include "../includes/libft.h"

char	**cpy_array2d(char **array2d)
{
	int		i;
	char	**cpy;

	i = 0;
	cpy = malloc (sizeof(char *) * count_args_2d(array2d));
	while (array2d[i])
	{
		cpy[i] = malloc(sizeof(char) * ft_strlen(array2d[i]) + 1);
		ft_strcpy(cpy[i], array2d[i]);
		i++;
	}
	cpy[i - 1] = NULL;
	return (cpy);
}
