/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:55:54 by kramjatt          #+#    #+#             */
/*   Updated: 2023/03/13 17:55:55 by kramjatt         ###   ########.fr       */
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
void	init_minishell(t_mini *mini, t_builts *builts, char **envp);

#endif
