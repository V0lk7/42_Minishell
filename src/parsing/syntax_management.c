/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:20:53 by jduval            #+#    #+#             */
/*   Updated: 2023/04/25 17:59:40 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static void	print_error(const char *str, int index, int flag)
{
	if (flag == 1)
		ft_putstr_fd(2, "😈 Minishell 😈: syntax error: unexpected end of file\n");
	else
	{
		ft_putstr_fd(2, "😈 Minishell 😈: syntax error near unexpected token `");
		ft_putchar_fd(2, str[index]);
		ft_putstr_fd(2, "\'\n");
	}
}

static void	syntax_error(const char *str, int flag, int index)
{
	if (flag == 0)
	{
		if (index == -2147483647)
			return ;
		else
			print_error(str, index * (-1), 0);
	}
	else
		print_error(str, 0, 1);
	return ;
}

t_bool	syntactical_parsing(char *str)
{
	int	value;

	value = first_character(str);
	if ((value == 0 && str[value] == '|') || value < 0)
	{
		syntax_error(str, 0, value);
		return (FALSE);
	}
	if (valid_quotes(str) == FALSE)
	{
		syntax_error(str, 1, value);
		return (FALSE);
	}
	value = is_syntax_valid(str);
	if (value <= 0)
	{
		syntax_error(str, 0, value);
		return (FALSE);
	}
	else
		return (TRUE);
}
