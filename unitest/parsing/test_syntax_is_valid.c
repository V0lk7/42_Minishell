/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_syntax_is_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:55:02 by jduval            #+#    #+#             */
/*   Updated: 2023/03/17 23:27:26 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "../greatest.h"

TEST	syntax_is_valid1(void)
{
	ASSERT_EQ_FMT(16, is_syntax_valid("cat |> cat | lol"), "%d");
	PASS();
}

TEST	syntax_is_valid2(void)
{
	ASSERT_EQ_FMT(-4, is_syntax_valid("cat |"), "%d");
	PASS();
}

TEST	syntax_is_valid3(void)
{
	ASSERT_EQ_FMT(18, is_syntax_valid("\"cat |\"cat | \'lol\'"), "%d");
	PASS();
}

TEST	syntax_is_valid4(void)
{
	ASSERT_EQ_FMT(-13, is_syntax_valid("cat | \'lol\' >| cat"), "%d");
	PASS();
}

TEST	syntax_is_valid5(void)
{
	ASSERT_EQ_FMT(-6, is_syntax_valid("cat | <>"), "%d");
	PASS();
}

TEST	syntax_is_valid6(void)
{
	ASSERT_EQ_FMT(12, is_syntax_valid("cat | <> out"), "%d");
	PASS();
}

TEST	syntax_is_valid7(void)
{
	ASSERT_EQ_FMT(-1, is_syntax_valid("||"), "%d");
	PASS();
}

TEST	syntax_is_valid8(void)
{
	ASSERT_EQ_FMT(-1, is_syntax_valid("|<>"), "%d");
	PASS();
}

SUITE (test_syntax_is_valid)
{
	RUN_TEST(syntax_is_valid1);
	RUN_TEST(syntax_is_valid2);
	RUN_TEST(syntax_is_valid3);
	RUN_TEST(syntax_is_valid4);
	RUN_TEST(syntax_is_valid5);
	RUN_TEST(syntax_is_valid6);
	RUN_TEST(syntax_is_valid7);
	RUN_TEST(syntax_is_valid8);
}
