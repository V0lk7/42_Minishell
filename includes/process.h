/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:55:54 by kramjatt          #+#    #+#             */
/*   Updated: 2023/03/29 16:21:31 by jduval           ###   ########.fr       */
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
void	normal_execution(t_data *lst, t_mini *mini, t_fd *fds);
/*-----normal_execution.c-----*/
void	execution_part(t_data *tmp, t_data *lst, t_fd *fds, t_mini *mini);
int		pipeline_execution(t_data *lst, t_fd *fds, t_mini *mini);
/*-----duplicate_functions.c-----*/
int		pipe_redirection(t_data *tmp, t_fd *fds, int last);
int		pipe_rdir_management(t_data *tmp, t_fd *fds);
t_data	*redirection_management(t_data *tmp, t_fd *fds, int index);
int		in_redirection(t_red *rdict, t_fd *fds);
int		out_redirection(t_red *rdict, t_fd *fds);

#endif
