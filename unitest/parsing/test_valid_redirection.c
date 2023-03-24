/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_valid_redirection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:55:02 by jduval            #+#    #+#             */
/*   Updated: 2023/03/17 23:29:17 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "../greatest.h"

TEST	valid_right_simple(void)
{
	ASSERT_EQ_FMT(8, valid_redirection("je usi > lol", 7, '>'), "%d");
	PASS();
}

TEST	valid_left_simple(void)
{
	ASSERT_EQ_FMT(8, valid_redirection("je usi < lol", 7, '>'), "%d");
	PASS();
}

TEST	valid_right_double(void)
{
	ASSERT_EQ_FMT(9, valid_redirection("je usi >> lol", 7, '>'), "%d");
	PASS();
}

TEST	valid_left_double(void)
{
	ASSERT_EQ_FMT(9, valid_redirection("je usi >> lol", 7, '>'), "%d");
	PASS();
}

TEST	invalid_right_triple(void)
{
	ASSERT_EQ_FMT(-7, valid_redirection("je usi >>> lol", 7, '>'), "%d");
	PASS();
}

TEST	invalid_left_triple(void)
{
	ASSERT_EQ_FMT(-7, valid_redirection("je usi <<< lol", 7, '<'), "%d");
	PASS();
}

TEST	invalid_left_pipe(void)
{
	ASSERT_EQ_FMT(-8, valid_redirection("je usi <| lol", 7, '<'), "%d");
	PASS();
}

TEST	invalid_left_end(void)
{
	ASSERT_EQ_FMT(-7, valid_redirection("je usi <", 7, '<'), "%d");
	PASS();
}

SUITE (test_valid_redirection)
{
	RUN_TEST(valid_right_simple);
	RUN_TEST(valid_left_simple);
	RUN_TEST(valid_right_double);
	RUN_TEST(valid_left_double);
	RUN_TEST(invalid_right_triple);
	RUN_TEST(invalid_left_triple);
	RUN_TEST(invalid_left_pipe);
	RUN_TEST(invalid_left_end);
}
