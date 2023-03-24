/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_character_spe.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:55:02 by jduval            #+#    #+#             */
/*   Updated: 2023/03/15 16:21:34 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "../greatest.h"

TEST	redirection_1(void)
{
	ASSERT_EQ_FMT(REDIRECTION, is_character_spe('<'), "%d");
	PASS();
}

TEST	redirection_2(void)
{
	ASSERT_EQ_FMT(REDIRECTION, is_character_spe('>'), "%d");
	PASS();
}

TEST	the_pipe(void)
{
	ASSERT_EQ_FMT(PIPE, is_character_spe('|'), "%d");
	PASS();
}

TEST	null_character(void)
{
	ASSERT_EQ_FMT(NONE, is_character_spe(0), "%d");
	PASS();
}

TEST	other_character(void)
{
	ASSERT_EQ_FMT(NONE, is_character_spe('7'), "%d");
	PASS();
}

SUITE (test_is_character_spe)
{
	RUN_TEST(redirection_1);
	RUN_TEST(redirection_2);
	RUN_TEST(the_pipe);
	RUN_TEST(null_character);
	RUN_TEST(other_character);
}
