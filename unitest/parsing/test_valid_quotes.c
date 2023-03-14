/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_valid_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:55:02 by jduval            #+#    #+#             */
/*   Updated: 2023/03/14 14:36:41 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "../greatest.h"

TEST	no_quote(void)
{
	ASSERT_EQ_FMT(TRUE, valid_quotes("je suis ton pere"), "%d");
	PASS();
}

TEST	double_quote(void)
{
	ASSERT_EQ_FMT(TRUE, valid_quotes("\"je suis\""), "%d");
	PASS();
}

TEST	mix_quote(void)
{
	ASSERT_EQ_FMT(TRUE, valid_quotes("\'hey\' \"boy\" la \'lol\'"), "%d");
	PASS();
}

TEST	mix_quote2(void)
{
	ASSERT_EQ_FMT(TRUE, valid_quotes("hey \"\'boy\'\'\'\" je \'la\' hello"), "%d");
	PASS();
}

TEST	empty_line_quote(void)
{
	ASSERT_EQ_FMT(TRUE, valid_quotes(""), "%d");
	PASS();
}

TEST	simple_quote_open(void)
{
	ASSERT_EQ_FMT(FALSE, valid_quotes("\'simple open \""), "%d");
	PASS();
}

TEST	double_quote_open(void)
{
	ASSERT_EQ_FMT(FALSE, valid_quotes("\"double open"), "%d");
	PASS();
}

TEST	double_quote_open2(void)
{
	ASSERT_EQ_FMT(FALSE, valid_quotes("\"je \" \"suis"), "%d");
	PASS();
}

TEST	one_simple_quote(void)
{
	ASSERT_EQ_FMT(FALSE, valid_quotes("\'"), "%d");
	PASS();
}

TEST	one_double_quote(void)
{
	ASSERT_EQ_FMT(FALSE, valid_quotes("\""), "%d");
	PASS();
}

TEST	two_double_quote(void)
{
	ASSERT_EQ_FMT(TRUE, valid_quotes("\"\""), "%d");
	PASS();
}

TEST	two_simple_quote(void)
{
	ASSERT_EQ_FMT(TRUE, valid_quotes("\'\'"), "%d");
	PASS();
}

TEST	simple_in_double_quote(void)
{
	ASSERT_EQ_FMT(TRUE, valid_quotes("\"\'\'\""), "%d");
	PASS();
}

TEST	null_quote(void)
{
	ASSERT_EQ_FMT(FALSE, valid_quotes(NULL), "%d");
	PASS();
}

SUITE (test_valid_quotes)
{
	RUN_TEST(no_quote);
	RUN_TEST(double_quote);
	RUN_TEST(mix_quote);
	RUN_TEST(mix_quote2);
	RUN_TEST(empty_line_quote);
	RUN_TEST(simple_quote_open);
	RUN_TEST(double_quote_open);
	RUN_TEST(double_quote_open2);
	RUN_TEST(one_simple_quote);
	RUN_TEST(one_double_quote);
	RUN_TEST(two_double_quote);
	RUN_TEST(two_simple_quote);
	RUN_TEST(simple_in_double_quote);
	RUN_TEST(null_quote);
}
