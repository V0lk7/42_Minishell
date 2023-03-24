/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pipe_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:55:02 by jduval            #+#    #+#             */
/*   Updated: 2023/03/17 13:17:46 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "../greatest.h"

TEST	pipe_case1(void)
{
	ASSERT_EQ_FMT(6, pipe_case("cat | lol", 5), "%d");
	PASS();
}

TEST	pipe_case2(void)
{
	ASSERT_EQ_FMT(7, pipe_case("cat |< lol", 5), "%d");
	PASS();
}

TEST	pipe_case3(void)
{
	ASSERT_EQ_FMT(-5, pipe_case("cat || lol", 5), "%d");
	PASS();
}

TEST	pipe_case4(void)
{
	ASSERT_EQ_FMT(-4, pipe_case("cat |   ", 5), "%d");
	PASS();
}

TEST	pipe_case5(void)
{
	ASSERT_EQ_FMT(-4, pipe_case("cat |", 5), "%d");
	PASS();
}

TEST	pipe_case6(void)
{
	ASSERT_EQ_FMT(5, pipe_case("cat |cat", 5), "%d");
	PASS();
}

SUITE (test_pipe_case)
{
	RUN_TEST(pipe_case1);
	RUN_TEST(pipe_case2);
	RUN_TEST(pipe_case3);
	RUN_TEST(pipe_case4);
	RUN_TEST(pipe_case5);
	RUN_TEST(pipe_case6);
}
