/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_valid_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:55:02 by jduval            #+#    #+#             */
/*   Updated: 2023/03/13 17:07:50 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "greatest.h"

static char	*str;

static void setup(void *data)
{
	(void) data;
	str = NULL;
}

static void teardown(void *data)
{
	(void) data;
	if (str != NULL)
		free (str);
}

TEST	no_quote(char *str)
{
	str = ft_gnl(fd);
	ASSERT_EQ_FMT(TRUE, valid_quotes(str), "%d");
	PASS();
}

TEST	double_quote(char *str)
{
	str = ft_gnl(fd);
	ASSERT_EQ_FMT(TRUE, valid_quotes(str), "%d");
	PASS();
}

TEST	mix_quote(char *str)
{
	str = ft_gnl(fd);
	ASSERT_EQ_FMT(TRUE, valid_quotes(str), "%d");
	PASS();
}

TEST	mix_quote2(char *str)
{
	str = ft_gnl(fd);
	ASSERT_EQ_FMT(TRUE, valid_quotes(str), "%d");
	PASS();
}

TEST	empty_line_quote(char *str)
{
	str = ft_gnl(fd);
	ASSERT_EQ_FMT(TRUE, valid_quotes(str), "%d");
	PASS();
}

TEST	simple_quote_open(char *str)
{
	str = ft_gnl(fd);
	ASSERT_EQ_FMT(FALSE, valid_quotes(str), "%d");
	PASS();
}

TEST	double_quote_open(char *str)
{
	str = ft_gnl(fd);
	ASSERT_EQ_FMT(FALSE, valid_quotes(str), "%d");
	PASS();
}

TEST	double_quote_open2(char *str)
{
	str = ft_gnl(fd);
	ASSERT_EQ_FMT(FALSE, valid_quotes(str), "%d");
	PASS();
}

TEST	one_simple_quote(char *str)
{
	str = ft_gnl(fd);
	ASSERT_EQ_FMT(FALSE, valid_quotes(str), "%d");
	PASS();
}

TEST	one_double_quote(char *str)
{
	str = ft_gnl(fd);
	ASSERT_EQ_FMT(FALSE, valid_quotes(str), "%d");
	PASS();
}

TEST	two_double_quote(char *str)
{
	ASSERT_EQ_FMT(TRUE, valid_quotes(str), "%d");
	PASS();
}

TEST	two_simple_quote(char *str)
{
	ASSERT_EQ_FMT(TRUE, valid_quotes(str), "%d");
	PASS();
}

TEST	simple_in_double_quote(char *str)
{
	ASSERT_EQ_FMT(TRUE, valid_quotes(str), "%d");
	PASS();
}

SUITE (test_valid_quotes)
{
	SET_SETUP(setup, NULL);
	SET_TEARDOWN(teardown, NULL);
	RUN_TEST1(no_quote, fd);
	RUN_TEST1(double_quote, fd);
	RUN_TEST1(mix_quote, fd);
	RUN_TEST1(mix_quote2, fd);
	RUN_TEST1(empty_line_quote, fd);
	RUN_TEST1(simple_quote_open, fd);
	RUN_TEST1(double_quote_open, fd);
	RUN_TEST1(double_quote_open2, fd);
	RUN_TEST1(one_simple_quote, fd);
	RUN_TEST1(one_double_quote, fd);
	RUN_TEST1(two_double_quote, fd);
	RUN_TEST1(two_simple_quote, fd);
	RUN_TEST1(simple_in_double_quote, fd);
	close(fd);
}
