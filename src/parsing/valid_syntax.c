/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:51:19 by jduval            #+#    #+#             */
/*   Updated: 2023/03/09 18:36:08 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_bool	valid_character(const char *str, char c, int i)
{
	if (ft_isalnum(c) > 0 || ft_isspace(c) > 0)
		return (TRUE);
	
}

t_bool	valid_syntax(const char *str)
{
	t_bool	open;
	int		i;
	int		character;

	open = FALSE;
	i = 0;
	character = 0;
	while (str[i])
	{
		if (open == FALSE && (str[i] == 34 || str[i] == 39))
		{
			character = str[i];
			open = TRUE;
		}
		else if (open == TRUE && str[i] == character)
			open == FALSE;
		else if (open == FALSE)
		{
			if (valid_character(str, str[i], i) == FALSE)
				return (FALSE);
		}
		else
			i++;
	}
	if (open == TRUE)
		return (FALSE);
	else
		return (TRUE);
}
