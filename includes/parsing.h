/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:53:48 by jduval            #+#    #+#             */
/*   Updated: 2023/04/12 12:23:09 by jduval           ###   ########.fr       */
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
t_bool	syntactical_parsing(char *str);
/*-------simplify_user_input.c-------*/
char	**isolate_by_pipe(char *str);
/*-------make_cmdline.c-------*/
t_data	*make_lst_line(char *str, t_mini *utils);
/*-------make_data.c-------*/
t_data	*create_node_command(const char *str, t_mini *utils, int words, int i);
t_data	*create_node_redirect(const char *str, int *i, int tmp, int index);
t_data	*put_redirection(const char *str, int nbr, int index);
/*-------make_path.c-------*/
char	**make_array_path(char **envp);
/*-------make_path.c-------*/
t_data	*command_manager(t_data	**head);
int		type_of_command(t_cmd *cmd, t_mini *utils);
/*-------quote_removal.c-------*/
int		quote_removal(t_data *lst);
int		remove_the_quote(char *str);

#endif
