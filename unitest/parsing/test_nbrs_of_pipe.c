/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_nbrs_of_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:55:02 by jduval            #+#    #+#             */
/*   Updated: 2023/03/20 17:48:18 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"
#include "../greatest.h"
#include "../../src/utils/split_by_pipe_utils.c"

TEST	one_pipe(void)
{
	ASSERT_EQ_FMT(1, nbrs_of_pipe("je suis | ton pere"), "%d");
	PASS();
}

TEST	one_pipe_with_quote(void)
{
	ASSERT_EQ_FMT(1, nbrs_of_pipe("je \"hello | \"suis | ton pere"), "%d");
	PASS();
}

TEST	two_pipe(void)
{
	ASSERT_EQ_FMT(2, nbrs_of_pipe("je suis|ton|pere"), "%d");
	PASS();
}

TEST	no_pipe(void)
{
	ASSERT_EQ_FMT(0, nbrs_of_pipe("hello"), "%d");
	PASS();
}

TEST	mlt_pipe_with_quote(void)
{
	ASSERT_EQ_FMT(3, nbrs_of_pipe("je | suis | \"lol | \' mdr\'|\" et ou | cat"), "%d");
	PASS();
}

SUITE (test_nbrs_of_pipe)
{
	RUN_TEST(one_pipe);
	RUN_TEST(one_pipe_with_quote);
	RUN_TEST(two_pipe);
	RUN_TEST(no_pipe);
	RUN_TEST(mlt_pipe_with_quote);
}
