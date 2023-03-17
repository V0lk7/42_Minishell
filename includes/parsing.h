/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:53:48 by jduval            #+#    #+#             */
/*   Updated: 2023/03/17 12:02:14 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
/*-------Libraries------*/

/*-------Headers------*/
# include "enum.h"
# include "../src/libft/include/libft.h"

/*-------valid_quotes.c-------*/
t_bool	valid_quotes(const char *str);
/*-------syntax_is_valid.c-------*/
int		redirection_case(const char *str, int i);
int		pipe_case(const char *str, int i);
int		past_character(const char *str, int i, t_spe character);
int		is_syntax_valid(const char *str);
/*-------syntax_is_valid2.c-------*/
int		first_character(const char *str);
t_spe	is_character_spe(int c);
int		pass_whitespace(const char *str, int i);
int		valid_redirection(const char *str, int i, char character);
/*-------syntax_management.c-------*/
t_bool	syntax_management(char *str);
#endif
