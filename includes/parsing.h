/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:53:48 by jduval            #+#    #+#             */
/*   Updated: 2023/04/27 17:21:01 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
/*-------Libraries------*/

/*-------Headers------*/
# include "enum.h"
# include "../src/libft/include/libft.h"

/*-------valid_quotes.c-------*/
t_bool		valid_quotes(const char *str);
/*-------syntax_is_valid.c-------*/
int			redirection_case(const char *str, int i);
int			pipe_case(const char *str, int i);
int			past_character(const char *str, int i, t_spe character);
int			is_syntax_valid(const char *str);
/*-------syntax_is_valid2.c-------*/
int			first_character(const char *str);
t_spe		is_character_spe(int c);
int			pass_whitespace(const char *str, int i);
int			valid_redirection(const char *str, int i, char character);
/*-------syntax_management.c-------*/
t_bool		empty_line(char *str);
t_bool		syntactical_parsing(char *str);
/*-------simplify_user_input.c-------*/
char		**isolate_by_pipe(char *str);
/*-------make_cmdline.c-------*/
t_data		*make_lst_line(char *str, t_mini *utils);
/*-------make_data.c-------*/
t_data		*create_node_command(char *str, t_mini *utils, int words, int i);
t_data		*create_node_redirect(const char *str, int *i, int tmp, int index);
t_data		*put_redirection(const char *str, int nbr, int index);
/*-------make_path.c-------*/
char		**make_array_path(char **envp);
/*-------make_path.c-------*/
t_data		*command_manager(t_data	**head);
int			type_of_command(t_cmd *cmd, t_mini *utils);
/*-------quote_removal.c-------*/
int			quote_removal(t_data *lst);
int			remove_the_quote(char *str);
/*-------dollar_in_quote.c-------*/
t_bool		dollar_in_quote(const char *str);
/*-------expansion_management.c-------*/
int			expansion_management(t_data *lst, t_mini *mini);
/*-------expand_wordsplitting.c-------*/
char		**expansion_wdsplit(char **cmd, t_mini *mini, int i);
/*-------expand_building.c-------*/
char		**rebuild_cmd(char **cmd, int i, t_expand *words);
/*-------shapeshift_str.c-------*/
int			number_of_whitespace(t_expand *cmd);
int			save_whitespace(t_expand *cmd, char **tmp);
void		restore_whitespace(char **array, char *tmp);
/*-------divide_words.c-------*/
int			next_expand_word(const char *str, int i);
int			id_word(const char *str, int start);
int			dollar_end(const char *str, int i);
t_expand	*node_expand(const char *cmd, int *i);
t_expand	*divide_words(const char *cmd);
/*-------expand_hdoc.c-------*/
int			expand_heredoc(t_red *hdoc, t_mini *mini);
#endif
