/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:56:09 by jduval            #+#    #+#             */
/*   Updated: 2023/03/17 23:22:49 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"

SUITE(test_valid_quotes);
SUITE(test_first_character);
SUITE(test_is_character_spe);
SUITE(test_pass_whitespace);
SUITE(test_valid_redirection);
SUITE(test_redirection_case);
SUITE(test_pipe_case);
SUITE(test_syntax_is_valid);
SUITE(test_normal_word_lengh);

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();	/*	command line initialization. */

	/* Test can also be gathered into test suites. */
	RUN_SUITE(test_valid_quotes);
	RUN_SUITE(test_first_character);
	RUN_SUITE(test_is_character_spe);
	RUN_SUITE(test_pass_whitespace);
	RUN_SUITE(test_valid_redirection);
	RUN_SUITE(test_redirection_case);
	RUN_SUITE(test_pipe_case);
	RUN_SUITE(test_syntax_is_valid);
	RUN_SUITE(test_normal_word_lengh);

	GREATEST_MAIN_END();	/* display result */
}
