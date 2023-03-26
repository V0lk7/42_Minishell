/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:14:38 by jduval            #+#    #+#             */
/*   Updated: 2023/03/26 16:27:21 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*-------Libraries------*/

/*-------Headers------*/
# include "enum.h"
# include "../src/libft/include/libft.h"
/*--------Structs-------*/

/*--------list_utils.c-------*/
t_data	*new_node_command(char **array, t_mini *utils, int index);
t_data	*new_node_redirect(t_class name, char *file, t_way way, int index);
void	add_back_node(t_data **head, t_data *node);
t_data	*reach_last_node(t_data *head);
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

/*--------$-------*/
//void	dollars(t_mini *mini);
#endif
