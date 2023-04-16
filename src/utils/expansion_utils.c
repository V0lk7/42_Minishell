#include "../../includes/utils.h"

int	next_carac(char *str, int start)
{
	while (str[++start])
		if (!ft_isalnum(str[start])
			&& (str[start] == '$' || str[start] != '_' || str[start] == '\0'))
			return (start - 1);
	return (ft_strlen(str));
}
