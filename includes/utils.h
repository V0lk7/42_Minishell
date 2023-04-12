/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:14:38 by jduval            #+#    #+#             */
/*   Updated: 2023/04/11 16:02:50 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*-------Headers------*/
# include "enum.h"
# include "../src/libft/include/libft.h"

/*--------list_utils.c-------*/
t_data	*new_node_command(char **array, t_mini *utils, int index);
t_data	*new_node_redirect(t_class name, char **file, t_way way, int index);
void	add_back_node(t_data **head, t_data *node);
t_data	*reach_last_node(t_data *head);
int		type_of_cmd(t_data *lst);

/*--------list_utils2.c-------*/
t_bool	is_pipeline(t_data *cmdline);
int		find_last_sequence(t_data *lst);
t_data	*next_sequence(t_data *lst);

/*--------split_by_pipe_utils.c-------*/
int		*find_index_pipe(char *str);

/*--------data_by_line_utils.c-------*/
int		find_rafter(const char *str);
int		rafter_index(const char *str, int i);
t_way	rafter_id(const char *str, int i);
int		normal_word_lengh(const char *str, int i);

/*--------make_command_utils.c-------*/
int		count_words(const char *str, int redirect);
int		pass_next_word(const char *str, int i);
char	**fill_array_cmd(const char *str, int words);

/*--------command_data_utils.c-------*/
int		type_of_file(char *str, int index);

/*--------errors.c-------*/
int		errors_command(t_cmd *cmd);
void	command_not_found(char *cmd);
void	command_is_directory(char *cmd);
int		ctrl_d_hdoc(char *str, int n);
void	error_exit(char *str);

/*--------$-------*/
void	expansion(t_cmd *cmd);
int		expansion_simple_quote(t_cmd *cmd, char *str, int index, int value_i);
void	interrogation_dollar(t_cmd *cmd, int i, int index);

/*--------hdoc_utils.c-------*/
int		create_tmp_hdoc(t_red *node);
t_hdoc	*create_hdoc_node(char *str, int flag);
void	add_back_hdoc(t_hdoc **head, t_hdoc *node);
t_hdoc	*reach_last_hdoc(t_hdoc *head);
void	close_here_doc(t_data *lst);
#endif
