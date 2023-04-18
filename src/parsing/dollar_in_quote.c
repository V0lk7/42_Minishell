/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_in_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:03:47 by jduval            #+#    #+#             */
/*   Updated: 2023/04/18 17:16:58 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"

t_bool	dollar_in_quote(const char *str)
{
	int		i;
	int		quote;

	quote = 0;
	i = 0;
	while (str[i])
	{
		if (quote == 0 && (str[i] == '\'' || str[i] == '\"'))
			quote = str[i];
		else if (quote > 0 && quote == str[i])
			quote = 0;
		else if (quote == 0 && str[i] == '$')
			return (FALSE);
		i++;
	}
	return (TRUE);
}
