/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:55:54 by kramjatt          #+#    #+#             */
/*   Updated: 2023/04/25 16:03:06 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

/*-------Libraries------*/
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
/*-------Headers------*/
# include "built_in.h"
# include "enum.h"
# include "clear.h"
# include "utils.h"
# include "../src/libft/include/libft.h"

void	history(char *argv);

/*-----Init_f-----*/
void	init_minishell(t_mini *mini, char **envp);
/*-----management_minishell.c-----*/
void	minishell_management(char *line, t_mini *mini, char **envp);
/*-----normal_execution.c-----*/
int		normal_execution(t_data *lst, t_mini *mini, t_fd *fds);
/*-----pipeline_execution.c-----*/
int		exec_utils(t_data *tmp, t_mini *mini);
void	execution_part(t_data *tmp, t_data *lst, t_fd *fds, t_mini *mini);
int		pipeline_execution(t_data *lst, t_fd *fds, t_mini *mini);
/*-----utils_pipeline.c-----*/
void	chose_builtin_or_exec(t_data *tmp, t_data *lst, t_mini *mini);
/*-----duplicate_functions.c-----*/
int		pipe_redirection(t_data *tmp, t_fd *fds, int last);
int		pipe_rdir_management(t_data *tmp, t_fd *fds);
t_data	*redirection_management(t_data *tmp, t_fd *fds, int index);
int		in_redirection(t_red *rdict, t_fd *fds);
int		out_redirection(t_red *rdict, t_fd *fds);
/*-----here_doc.c-----*/
int		hdoc_rl_event_hook(void);
int		here_doc(t_data *lst, t_mini *mini);
/*-----signals.c-----*/
void	n_handler(int signal);
void	f_handler(int signal);
void	sigint_hdoc(int signal);
#endif
